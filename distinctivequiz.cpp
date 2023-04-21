#include "distinctivequiz.h"
#include "ui_distinctivequiz.h"

DistinctiveQuiz::DistinctiveQuiz(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::DistinctiveQuiz)
{
    ui->setupUi(this);
}

DistinctiveQuiz::~DistinctiveQuiz()
{
    delete ui;
}
