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
    Saves::Save("UseBasicColorsLesson","Flags.data");
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

    QRandomGenerator rng = QRandomGenerator::securelySeeded();

    ui->flag->addLayer(QImage(":/FlagTemplates/Flag Border.png"), Qt::white);
    ui->flag->addLayer(QImage(":/FlagTemplates/" + CENTER_FLAG_TEMPLATES[rng.bounded(CENTER_FLAG_TEMPLATES.length())]), Qt::black);

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
            QColor(255 * i / 5, 255 * i / 5, 255 * i / 5)
        );
    }
}

FlagColoringPuzzle::~FlagColoringPuzzle()
{
    delete ui;
}
