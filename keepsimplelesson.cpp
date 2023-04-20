#include "keepsimplelesson.h"
#include "basicquiz.h"
#include "ui_keepsimplelesson.h"
#include <QPushButton>
#include "flagwidget.h"
#include "flagconstants.h"
#include "flagcoloringpuzzle.h"

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


    // Create a Box2D world with gravity in the downward direction


}

/**
 * @brief KeepSimpleLesson::~KeepSimpleLesson
 */
KeepSimpleLesson::~KeepSimpleLesson()
{
    delete ui;
}

/**
 * @brief KeepSimpleLesson::NextClicked
 */
void KeepSimpleLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }

}

/**
 * @brief KeepSimpleLesson::BackClicked
 */
void KeepSimpleLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);

}










