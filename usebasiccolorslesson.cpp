#include "usebasiccolorslesson.h"
#include "ui_usebasiccolorslesson.h"
#include <QPushButton>

/**
 * @brief UseBasicColorsLesson::UseBasicColorsLesson
 * @param parent
 */
UseBasicColorsLesson::UseBasicColorsLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::UseBasicColorsLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    QPushButton* NextButton1 = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("nextButton"));
    QPushButton* NextButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("nextButton_2"));
    QPushButton* BackButton = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("backButton"));
    QPushButton* mainMenuButton = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("mainMenu"));
    QPushButton* mainMenuButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("mainMenu_2"));

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
