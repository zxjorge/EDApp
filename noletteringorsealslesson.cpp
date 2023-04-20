/**
 * NoLetteringOrSealsLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses NoLetteringOrSealsLesson.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "noletteringorsealslesson.h"
#include "ui_noletteringorsealslesson.h"
#include <QPushButton>

/**
 * @brief NoLetteringOrSealsLesson::NoLetteringOrSealsLesson Constructor for NoLetteringOrSealsLesson
 * @param parent widget that is used to help handle memory and resources.
 */
NoLetteringOrSealsLesson::NoLetteringOrSealsLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::NoLetteringOrSealsLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &NoLetteringOrSealsLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &NoLetteringOrSealsLesson::NextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &NoLetteringOrSealsLesson::BackClicked);
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
 * @brief NoLetteringOrSealsLesson::~NoLetteringOrSealsLesson destructor for NoLetteringOrSealsLesson
 */
NoLetteringOrSealsLesson::~NoLetteringOrSealsLesson()
{
    delete ui;
}


/**
 * @brief NoLetteringOrSealsLesson::NextClicked Slot that handles what happens when the next button is clicked in the UI
 */
void NoLetteringOrSealsLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

/**
 * @brief NoLetteringOrSealsLesson::BackClicked Slot that handles what happens when the back button is clicked in the UI
 */
void NoLetteringOrSealsLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
