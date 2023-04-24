#include "finaldesignactivity.h"
#include "mainmenu.h"
#include "ui_finaldesignactivity.h"
#include <QColorDialog>
#include <QMessageBox>

const QString flagFilename = "final_flag.png";


FinalDesignActivity::FinalDesignActivity(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::FinalDesignActivity),
    drawUtils(DrawUtils()),
    mainWindow(parent)
{
    ui->setupUi(this);
    ui->canvas->setDrawUtils(&drawUtils);

    QImage image;
    if (image.load(flagFilename)) {
        ui->canvas->setImage(image);
    }

    connect(ui->colorPaletteButton,
            &QPushButton::clicked,
            this,
            [this] {
                drawUtils.setColor(QColorDialog::getColor(drawUtils.getColor(), this, "Choose a Color"));
                QString buttonColorString = QString("background-color: %1").arg(drawUtils.getColor().name());
                ui->colorPaletteButton->setStyleSheet(buttonColorString);
            });
    connect(ui->doneButton,
            &QPushButton::clicked,
            this,
            [this] {
                ui->canvas->saveFlag(flagFilename);
                QMessageBox::information(mainWindow, "Saved", "Your flag was saved to final_flag.png!");
                mainWindow->switchScene(new MainMenu(mainWindow));
            });

    connect(ui->sizeSlider,
            &QAbstractSlider::valueChanged,
            this,
            [this] {
                ui->sizeBox->setValue(ui->sizeSlider->value());
                drawUtils.setBrushSize(ui->sizeSlider->value());
            });
    connect(ui->sizeBox,
            &QSpinBox::textChanged,
            this,
            [this] {
                ui->sizeSlider->setValue(ui->sizeBox->value());
                drawUtils.setBrushSize(ui->sizeBox->value());
            });

    connect(ui->brushButton,
            &QPushButton::clicked,
            this,
            [this] {
                drawUtils.setSelectedToolType(ToolType::BRUSH);
            });
    connect(ui->fillButton,
            &QPushButton::clicked,
            this,
            [this] {
                drawUtils.setSelectedToolType(ToolType::FILL);
            });
    connect(ui->eraserButton,
            &QPushButton::clicked,
            this,
            [this] {
                drawUtils.setSelectedToolType(ToolType::ERASER);
            });
}

FinalDesignActivity::~FinalDesignActivity()
{
    delete ui;
}
