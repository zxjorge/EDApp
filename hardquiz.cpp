#include "hardquiz.h"
#include "ui_hardquiz.h"

hardquiz::hardquiz(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::hardquiz)
{
    ui->setupUi(this);
}

hardquiz::~hardquiz()
{
    delete ui;
}
