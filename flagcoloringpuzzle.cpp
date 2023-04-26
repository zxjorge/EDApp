/**
 * FlagColoringPuzzle.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses FlagColoringPuzzle.h header file and implements all its methods.
 * Reviewed by: Brayden Newsom
 */
#include "flagcoloringpuzzle.h"
#include "ui_flagcoloringpuzzle.h"
#include "mainmenu.h"
#include <QColorDialog>
#include <QRandomGenerator>
#include "flagconstants.h"
#include "saves.h"

FlagColoringPuzzle::FlagColoringPuzzle(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::FlagColoringPuzzle),
    mainWindow(parent)
{
    ui->setupUi(this);
    parent->getSaves()->Save("UseBasicColorsLesson");
    connect(ui->colorPaletteButton,
            &QPushButton::clicked,
            this,
            [this] {
                ui->flag->setCurrentColor(QColorDialog::getColor(ui->flag->getCurrentColor(), this, "Choose a Color"));
                QString buttonColorString = QString("background-color: %1").arg(ui->flag->getCurrentColor().name());
                ui->colorPaletteButton->setStyleSheet(buttonColorString);
            });
    connect(ui->flag,
            &FillableFlag::correctColorCount,
            this,
            [this] {
                ui->doneButton->setEnabled(true);
                ui->doneButton->setText("Done!");
            });
    connect(ui->flag,
            &FillableFlag::incorrectColorCount,
            this,
            [this] {
                ui->doneButton->setEnabled(false);
                ui->doneButton->setText("You have too many colors!");
            });
    connect(ui->doneButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });
    connect(ui->undo,
            &QPushButton::clicked,
            ui->flag,
            &FillableFlag::undo);
    connect(ui->redo,
            &QPushButton::clicked,
            ui->flag,
            &FillableFlag::redo);

    QRandomGenerator rng = QRandomGenerator::securelySeeded();

    ui->flag->addLayer(QImage(":/FlagTemplates/Flag Border.png"), Qt::white, true);
    ui->flag->addLayer(QImage(":/FlagTemplates/" + CENTER_FLAG_TEMPLATES[rng.bounded(CENTER_FLAG_TEMPLATES.length())]), Qt::black, true);

    QSet<QString> seen;

    for (int i = 1; i < 5; i++) {
        QString selected;

        do {
            int index = rng.bounded(CORNER_FLAG_TEMPLATES.length());
            selected = CORNER_FLAG_TEMPLATES[index];
        }
        while (seen.contains(selected));

        seen.insert(selected);
        ui->flag->addLayer(
            QImage(":/FlagTemplates/" + selected),
            QColor(255 * i / 5, 255 * i / 5, 255 * i / 5),
            true
        );
    }
}

FlagColoringPuzzle::~FlagColoringPuzzle()
{
    delete ui;
}
