/**
 * KeepSimpleActivity.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses KeepSimpleActivity.h header file and implements all its methods.
 * Reviewed by: Brayden Newsom
 */
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
    parent->getSaves()->Save("KeepSimpleLesson");
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

    ui->flag->addLayer(QImage(":/FlagTemplates/Flag Border.png"), Qt::white, true);

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

    connect(ui->choice5,
            &QPushButton::clicked,
            this,
            [=] {
                ui->flag->addLayer(QImage(":/FlagTemplates/treeMiddleLeft.png"));
                update();
            });
    connect(ui->choice6,
            &QPushButton::clicked,
            this,
            [=] {
                ui->flag->addLayer(QImage(":/FlagTemplates/polygonMiddle.png"));
                update();
            });
    connect(ui->choice7,
            &QPushButton::clicked,
            this,
            [=] {
                ui->flag->addLayer(QImage(":/FlagTemplates/flowerMiddleRight.png"));
                update();
            });
    connect(ui->choice8,
            &QPushButton::clicked,
            this,
            [=] {
                ui->flag->addLayer(QImage(":/FlagTemplates/treeMiddleRight.png"));
                update();
            });
}

KeepSimpleActivity::~KeepSimpleActivity()
{
    delete ui;
}
