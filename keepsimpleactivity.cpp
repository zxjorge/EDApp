#include "keepsimpleactivity.h"
#include "ui_keepsimpleactivity.h"

KeepSimpleActivity::KeepSimpleActivity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeepSimpleActivity),
    drawUtils(DrawUtils())
{
    ui->setupUi(this);
    ui->canvas->setDrawUtils(&drawUtils);
}

KeepSimpleActivity::~KeepSimpleActivity()
{
    delete ui;
}
