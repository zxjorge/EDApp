#include "meaningfulsymbolismlesson.h"
#include "ui_meaningfulsymbolismlesson.h"
#include <QPushButton>

/**
 * @brief MeaningfulSymbolismLesson::MeaningfulSymbolismLesson
 * @param parent
 */
MeaningfulSymbolismLesson::MeaningfulSymbolismLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::MeaningfulSymbolismLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    QPushButton* NextButton1 = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("nextButton"));
    QPushButton* mainMenuButton = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("mainMenu"));
    QPushButton* mainMenuButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("mainMenu_2"));
    QPushButton* NextButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("nextButton_2"));
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

    connect(mainMenuButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });

    connect(mainMenuButton2,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });


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




