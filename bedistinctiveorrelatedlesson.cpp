/**
 * BeDistinctiveOrRelatedLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses BeDistinctiveOrRelatedLesson.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "bedistinctiveorrelatedlesson.h"
#include "ui_bedistinctiveorrelatedlesson.h"
#include <QPushButton>

/**
 * @brief BeDistinctiveOrRelatedLesson::BeDistinctiveOrRelatedLesson Constructor for BeDistinctiveOrRelatedLesson
 * @param parent widget that is used to help handle memory and resources.
 */
BeDistinctiveOrRelatedLesson::BeDistinctiveOrRelatedLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::BeDistinctiveOrRelatedLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedLesson::NextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedLesson::BackClicked);
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
 * @brief BeDistinctiveOrRelatedLesson::~BeDistinctiveOrRelatedLesson destructor for BeDistinctiveOrRelatedLesson
 */
BeDistinctiveOrRelatedLesson::~BeDistinctiveOrRelatedLesson()
{
    delete ui;
}


/**
 * @brief BeDistinctiveOrRelatedLesson::NextClicked Slot that handles what happens when the next button is clicked in the UI
 */
void BeDistinctiveOrRelatedLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }

}

/**
 * @brief BeDistinctiveOrRelatedLesson::BackClicked Slot that handles what happens when the back button is clicked in the UI
 */
void BeDistinctiveOrRelatedLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
