#include "keepsimpleactivity.h"
#include "mainmenu.h"
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
    Saves::Save("UseBasicColorsLesson","Flags.data");
    connect(ui->colorPaletteButton,
            &QPushButton::clicked,
            this,
            [this] {
                ui->flag->setCurrentColor(QColorDialog::getColor(ui->flag->getCurrentColor(), this, "Choose a Color"));
                QString buttonColorString = QString("background-color: %1").arg(ui->flag->getCurrentColor().name());
                ui->colorPaletteButton->setStyleSheet(buttonColorString);
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

    ui->flag->addLayer(QImage(":/FlagTemplates/Flag Border.png"), Qt::white);
    update();
    connect(ui->choice1,
            &QPushButton::clicked,
            this,
            [=] {
                ui->flag->addLayer(QImage(":/FlagTemplates/weirdShapeMiddle.png"));
                update();
            });
    connect(ui->choice2,
            &QPushButton::clicked,
            this,
            [=] {
                ui->flag->addLayer(QImage(":/FlagTemplates/flowerMiddle.png"));
                update();
            });
    connect(ui->choice3,
            &QPushButton::clicked,
            this,
            [=] {
                ui->flag->addLayer(QImage(":/FlagTemplates/triangleMiddle.png"));
                update();
            });
    connect(ui->choice4,
            &QPushButton::clicked,
            this,
            [=] {
                ui->flag->addLayer(QImage(":/FlagTemplates/tigerMiddle.png"));
                update();
            });
}

KeepSimpleActivity::~KeepSimpleActivity()
{
    delete ui;
}
