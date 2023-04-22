#include "distinctivequiz.h"
#include "qrandom.h"
#include "ui_distinctivequiz.h"
#include "flagConstants.h"

DistinctiveQuiz::DistinctiveQuiz(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::DistinctiveQuiz)
{
    ui->setupUi(this);
  //  ui->flag1->setStyleSheet("border-image: url(:/Flags/gh.png)");


    QRandomGenerator rng = QRandomGenerator::securelySeeded();
    QIcon bIcon(":/Flags/gh.png");
    ui->flag1->setIcon(bIcon);
    QSize size(ui->flag1->width(),ui->flag1->height());
    ui->flag1->setIconSize(size);

    int distinctiveOrRelated = rng.bounded(2);
    int symbolPicker = rng.bounded(3);
    QString display1 = "url(:/Flags/";
    QString display2 = "url(:/Flags/";
    while(display1 == display2){
        if(symbolPicker == 0){
            display1 += CHRISTIANITY_FLAGS.at(rng.bounded(CHRISTIANITY_FLAGS.size()));
            display2 += CHRISTIANITY_FLAGS.at(rng.bounded(CHRISTIANITY_FLAGS.size()));
        }
        else if(symbolPicker == 1){
            display1 += ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));
            display2 += ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));
        }
        else{
            display1 += UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));
            display2 += UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));
        }
    }
    display1+=")";
    display2+=")";
    ui->displayFlag1->setStyleSheet("border-image: " + display1);
    ui->displayFlag2->setStyleSheet("border-image: " + display2);



    connect(ui->flag1,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::flag1Clicked);

    connect(ui->flag2,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::flag2Clicked);

    connect(ui->flag3,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::flag3Clicked);

    connect(ui->flag4,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::flag4Clicked);

    connect(ui->next,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::on_next_clicked);

}

DistinctiveQuiz::~DistinctiveQuiz()
{
    delete ui;
}

void DistinctiveQuiz::flag1Clicked(){
    if(flag1Selected){
        ui->flag1->setStyleSheet("background-color:light gray");
        flag1Selected = false;
    }
    else{
        ui->flag1->setStyleSheet("background-color:rgb(0,100,255)");
        flag1Selected = true;
    }
}

void DistinctiveQuiz::flag2Clicked(){
    if(flag2Selected){
        ui->flag2->setStyleSheet("background-color:light gray");
        flag2Selected = false;
    }
    else{
        ui->flag2->setStyleSheet("background-color:rgb(0,100,255)");
        flag2Selected = true;
    }
}

void DistinctiveQuiz::flag3Clicked(){
    if(flag3Selected){
        ui->flag3->setStyleSheet("background-color:light gray");
        flag3Selected = false;
    }
    else{
        ui->flag3->setStyleSheet("background-color:rgb(0,100,255)");
        flag3Selected = true;
    }
}

void DistinctiveQuiz::flag4Clicked(){
    if(flag4Selected){
        ui->flag4->setStyleSheet("background-color:light gray");
        flag4Selected = false;
    }
    else{
        ui->flag4->setStyleSheet("background-color:rgb(0,100,255)");
        flag4Selected = true;
    }
}

void DistinctiveQuiz::on_next_clicked()
{

}

