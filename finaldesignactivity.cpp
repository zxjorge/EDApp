#include "finaldesignactivity.h"
#include "ui_finaldesignactivity.h"

FinalDesignActivity::FinalDesignActivity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinalDesignActivity),
    drawUtils(DrawUtils())
{
    ui->setupUi(this);
    ui->canvas->setDrawUtils(&drawUtils);
}

FinalDesignActivity::~FinalDesignActivity()
{
    delete ui;
}
