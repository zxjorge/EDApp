#include "noletteringorsealslesson.h"
#include "ui_noletteringorsealslesson.h"
#include <QPushButton>

NoLetteringOrSealsLesson::NoLetteringOrSealsLesson(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::NoLetteringOrSealsLesson)
{
    ui->setupUi(this);
    QPushButton* NextButton1 = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("nextButton"));
    QPushButton* NextButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("nextButton"));
    QPushButton* BackButton = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("backButton"));
    connect(NextButton1,
            &QPushButton::clicked,
            this,
            &NoLetteringOrSealsLesson::NextClicked);
    connect(NextButton2,
            &QPushButton::clicked,
            this,
            &NoLetteringOrSealsLesson::NextClicked);
    connect(BackButton,
            &QPushButton::clicked,
            this,
            &NoLetteringOrSealsLesson::BackClicked);
}

NoLetteringOrSealsLesson::~NoLetteringOrSealsLesson()
{
    delete ui;
}


/**
 * @brief NoLetteringOrSealsLesson::NextClicked
 */
void NoLetteringOrSealsLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

/**
 * @brief NoLetteringOrSealsLesson::BackClicked
 */
void NoLetteringOrSealsLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
