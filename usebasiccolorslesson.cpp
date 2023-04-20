#include "usebasiccolorslesson.h"
#include "basicquiz.h"
#include "flagcoloringpuzzle.h"
#include "flagconstants.h"
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
    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &UseBasicColorsLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &UseBasicColorsLesson::NextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &UseBasicColorsLesson::BackClicked);
    connect(ui->mainMenu,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });
    connect(ui->mainMenu_2,
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
    } else {
        mainWindow->switchScene(new BasicQuiz(
            "Which flag has less colors?",
            SIMPLE_FLAGS,
            MEANINGFUL_FLAGS,
            new FlagColoringPuzzle(mainWindow),
            mainWindow
            ));
    }
}

/**
 * @brief UseBasicColorsLesson::BackClicked
 */
void UseBasicColorsLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
