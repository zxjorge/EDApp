#include "flagcoloringpuzzle.h"
#include "ui_flagcoloringpuzzle.h"

FlagColoringPuzzle::FlagColoringPuzzle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlagColoringPuzzle)
{
    ui->setupUi(this);
}

FlagColoringPuzzle::~FlagColoringPuzzle()
{
    delete ui;
}
