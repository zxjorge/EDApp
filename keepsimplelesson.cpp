/**
 * KeepSimpleLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses KeepSimpleLesson.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "keepsimplelesson.h"
#include "basicquiz.h"
#include "ui_keepsimplelesson.h"
#include <QPushButton>
#include "flagwidget.h"
#include "flagconstants.h"
#include "flagcoloringpuzzle.h"

/**
 * @brief KeepSimpleLesson::KeepSimpleLesson Constructor for KeepSimpleLesson
 * @param parent widget that is used to help handle memory and resources.
 */
KeepSimpleLesson::KeepSimpleLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::KeepSimpleLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::BackClicked);
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
 * @brief KeepSimpleLesson::~KeepSimpleLesson destructor for KeepSimpleLesson
 */
KeepSimpleLesson::~KeepSimpleLesson()
{
    delete ui;
}

/**
 * @brief KeepSimpleLesson::NextClicked Slot that handles what happens when the next button is clicked in the UI
 */
void KeepSimpleLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }

}

/**
 * @brief KeepSimpleLesson::BackClicked Slot that handles what happens when the back button is clicked in the UI
 */
void KeepSimpleLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);

}










