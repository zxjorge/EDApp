#include "noletteringorsealslesson.h"
#include "ui_noletteringorsealslesson.h"
#include <QPushButton>

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

NoLetteringOrSealsLesson::~NoLetteringOrSealsLesson()
{
    delete ui;
}


/**
 * @brief NoLetteringOrSealsLesson::NextClicked
 */
void NoLetteringOrSealsLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

/**
 * @brief NoLetteringOrSealsLesson::BackClicked
 */
void NoLetteringOrSealsLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
