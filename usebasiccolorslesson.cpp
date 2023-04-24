/**
 * UseBasicColorsLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses UseBasicColorsLesson.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "usebasiccolorslesson.h"
#include "basicquiz.h"
#include "flagcoloringpuzzle.h"
#include "flagconstants.h"
#include "mainmenu.h"
#include "ui_usebasiccolorslesson.h"
#include <QPushButton>


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


UseBasicColorsLesson::~UseBasicColorsLesson()
{
    delete ui;
}

void UseBasicColorsLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    } else {
        mainWindow->switchScene(new BasicQuiz(
            "Which flag has less colors?",
            BASIC_COLOR_FLAGS,
            COMPLEX_COLOR_FLAGS,
            new FlagColoringPuzzle(mainWindow),
            mainWindow
        ));
    }
}

void UseBasicColorsLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
