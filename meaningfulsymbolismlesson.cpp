#include "meaningfulsymbolismlesson.h"
#include "ui_meaningfulsymbolismlesson.h"
#include <QPushButton>

/**
 * @brief MeaningfulSymbolismLesson::MeaningfulSymbolismLesson
 * @param parent
 */
MeaningfulSymbolismLesson::MeaningfulSymbolismLesson(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::MeaningfulSymbolismLesson)
{
    ui->setupUi(this);
    QPushButton* NextButton1 = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("nextButton"));
    QPushButton* NextButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("nextButton"));
    QPushButton* BackButton = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("backButton"));
    connect(NextButton1,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::NextClicked);
    connect(NextButton2,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::NextClicked);
    connect(BackButton,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::BackClicked);
}

MeaningfulSymbolismLesson::~MeaningfulSymbolismLesson()
{
    delete ui;
}

/**
 * @brief MeaningfulSymbolismLesson::NextClicked
 */
void MeaningfulSymbolismLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

/**
 * @brief MeaningfulSymbolismLesson::BackClicked
 */
void MeaningfulSymbolismLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
