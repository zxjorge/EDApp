#include "flagcoloringpuzzle.h"
#include "ui_flagcoloringpuzzle.h"
#include "mainmenu.h"
#include <QColorDialog>

FlagColoringPuzzle::FlagColoringPuzzle(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::FlagColoringPuzzle),
    mainWindow(parent)
{
    ui->setupUi(this);
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
}

FlagColoringPuzzle::~FlagColoringPuzzle()
{
    delete ui;
}
