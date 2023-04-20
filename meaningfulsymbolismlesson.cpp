/**
 * MeaningfulSymbolismLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses MeaningfulSymbolismLesson.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "meaningfulsymbolismlesson.h"
#include "ui_meaningfulsymbolismlesson.h"
#include <QPushButton>

/**
 * @brief MeaningfulSymbolismLesson::MeaningfulSymbolismLesson Constructor for MeaningfulSymbolismLesson
 * @param parent widget that is used to help handle memory and resources.
 */
MeaningfulSymbolismLesson::MeaningfulSymbolismLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::MeaningfulSymbolismLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::NextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::BackClicked);

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
 * @brief MeaningfulSymbolismLesson::~MeaningfulSymbolismLesson destructor for MeaningfulSymbolismLesson
 */
MeaningfulSymbolismLesson::~MeaningfulSymbolismLesson()
{
    delete ui;
}

/**
 * @brief MeaningfulSymbolismLesson::NextClicked Slot that handles what happens when the next button is clicked in the UI
 */
void MeaningfulSymbolismLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

/**
 * @brief MeaningfulSymbolismLesson::BackClicked Slot that handles what happens when the back button is clicked in the UI
 */
void MeaningfulSymbolismLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}




