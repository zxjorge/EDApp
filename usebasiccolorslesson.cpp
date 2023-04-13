#include "usebasiccolorslesson.h"
#include "ui_usebasiccolorslesson.h"
#include <QPushButton>

/**
 * @brief UseBasicColorsLesson::UseBasicColorsLesson
 * @param parent
 */
UseBasicColorsLesson::UseBasicColorsLesson(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::UseBasicColorsLesson)
{
    ui->setupUi(this);
    QPushButton* NextButton1 = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("nextButton"));
    QPushButton* NextButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("nextButton"));
    QPushButton* BackButton = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("backButton"));
    connect(NextButton1,
            &QPushButton::clicked,
            this,
            &UseBasicColorsLesson::NextClicked);
    connect(NextButton2,
            &QPushButton::clicked,
            this,
            &UseBasicColorsLesson::NextClicked);
    connect(BackButton,
            &QPushButton::clicked,
            this,
            &UseBasicColorsLesson::BackClicked);
}
}

/**
 * @brief UseBasicColorsLesson::~UseBasicColorsLesson
 */
UseBasicColorsLesson::~UseBasicColorsLesson()
{
    delete ui;
}

/**
 * @brief UseBasicColorsLesson::NextClicked
 */
void UseBasicColorsLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }

}

/**
 * @brief UseBasicColorsLesson::BackClicked
 */
void UseBasicColorsLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
