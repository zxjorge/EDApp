/**
 * KeepSimpleActivity.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses KeepSimpleActivity.h header file and implements all its methods.
 * Reviewed by: Brayden Newsom
 */
#include "keepsimpleactivity.h"
#include "mainmenu.h"
#include "qpainter.h"
#include "ui_keepsimpleactivity.h"
#include "saves.h"
#include <QColorDialog>

KeepSimpleActivity::KeepSimpleActivity(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::KeepSimpleActivity),
    drawUtils(DrawUtils()),
    mainWindow(parent)
{
    ui->setupUi(this);
    parent->getSaves()->Save("KeepSimpleLesson");
    connect(ui->colorPaletteButton,
            &QPushButton::clicked,
            this,
            [this] {
                ui->flag->setCurrentColor(QColorDialog::getColor(ui->flag->getCurrentColor(), this, "Choose a Color"));
                QString buttonColorString = QString("background-color: %1").arg(ui->flag->getCurrentColor().name());
                ui->colorPaletteButton->setStyleSheet(buttonColorString);
                updateCursor();
            });
    connect(ui->undo,
            &QPushButton::clicked,
            ui->flag,
            &FillableFlag::undo);
    connect(ui->redo,
            &QPushButton::clicked,
            ui->flag,
            &FillableFlag::redo);
    connect(ui->doneButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });

    ui->flag->addLayer(QImage(":/FlagTemplates/Flag Border.png"), Qt::white, true);
    ui->flag->setAutoFill(false);

    connect(ui->flag,
            &FillableFlag::clicked,
            this,
            [this] (QPoint pos) {
                if (selectedSymbol.isNull()) {
                    ui->flag->fillAtPoint(pos);
                    return;
                }
                QImage layer = QImage(1000, 750, QImage::Format_ARGB32);
                layer.fill(QColor(0, 0, 0, 0));
                QPainter painter(&layer);

                pos.rx() -= 500;
                pos.ry() -= 375;
                painter.drawImage(pos, selectedSymbol);

                ui->flag->addLayer(layer, ui->flag->getCurrentColor());
                update();
            });

    connect(ui->choice1,
            &QPushButton::clicked,
            this,
            [=] {
                setSelectedSymbol(":/FlagTemplates/weirdShapeMiddle.png");
            });
    connect(ui->choice2,
            &QPushButton::clicked,
            this,
            [=] {
                setSelectedSymbol(":/FlagTemplates/flowerMiddle.png");
            });
    connect(ui->choice3,
            &QPushButton::clicked,
            this,
            [=] {
                setSelectedSymbol(":/FlagTemplates/triangleMiddle.png");
            });
    connect(ui->choice4,
            &QPushButton::clicked,
            this,
            [=] {
                setSelectedSymbol(":/FlagTemplates/tigerMiddle.png");
            });
    connect(ui->choice5,
            &QPushButton::clicked,
            this,
            [=] {
                setSelectedSymbol(":/FlagTemplates/circleMiddle.png");
            });
    connect(ui->choice6,
            &QPushButton::clicked,
            this,
            [=] {
                setSelectedSymbol(":/FlagTemplates/polygonMiddle.png");
            });
    connect(ui->choice7,
            &QPushButton::clicked,
            this,
            [=] {
                selectedSymbol = QImage();
                updateCursor();
            });
}

KeepSimpleActivity::~KeepSimpleActivity()
{
    delete ui;
}

void KeepSimpleActivity::setSelectedSymbol(QString path) {
    selectedSymbol = QImage(path);
    updateCursor();
}

void KeepSimpleActivity::resizeEvent(QResizeEvent*) {
    updateCursor();
}

void KeepSimpleActivity::updateCursor() {
    if (selectedSymbol.isNull()) {
        setCursor(QCursor());
        return;
    }
    QImage img = selectedSymbol.scaledToWidth(selectedSymbol.width() * ui->flag->getScale(), Qt::SmoothTransformation);
    QPainter layerPainter(&img);
    layerPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);

    QColor color = ui->flag->getCurrentColor();
    layerPainter.setBrush(color);
    layerPainter.setPen(color);

    layerPainter.drawRect(img.rect());

    color = QColor(0, 0, 0, 0);
    layerPainter.setBrush(color);
    layerPainter.setPen(color);

    layerPainter.drawRect(img.width() / 2 - 1, img.height() / 2 - 6, 2, 12);
    layerPainter.drawRect(img.width() / 2 - 6, img.height() / 2 - 1, 12, 2);

    setCursor(QCursor(QPixmap::fromImage(img)));
}
