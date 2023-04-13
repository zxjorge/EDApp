#include "keepsimplelesson.h"
#include "ui_keepsimplelesson.h"
#include <QPushButton>

KeepSimpleLesson::KeepSimpleLesson(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::KeepSimpleLesson)
{
    ui->setupUi(this);
    QPushButton* NextButton1 = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("nextButton"));
    QPushButton* NextButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("nextButton"));
    QPushButton* BackButton = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("backButton"));
    connect(NextButton1,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(NextButton2,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(BackButton,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::BackClicked);

}

/**
 * @brief KeepSimpleLesson::~KeepSimpleLesson
 */
KeepSimpleLesson::~KeepSimpleLesson()
{
    delete ui;
}

/**
 * @brief KeepSimpleLesson::NextClicked
 */
void KeepSimpleLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }

}

/**
 * @brief KeepSimpleLesson::BackClicked
 */
void KeepSimpleLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
