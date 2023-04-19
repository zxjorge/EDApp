#include "bedistinctiveorrelatedlesson.h"
#include "ui_bedistinctiveorrelatedlesson.h"
#include <QPushButton>

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

BeDistinctiveOrRelatedLesson::~BeDistinctiveOrRelatedLesson()
{
    delete ui;
}

/**
 * @brief BeDistinctiveOrRelatedLesson::NextClicked
 */
void BeDistinctiveOrRelatedLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }

}

/**
 * @brief BeDistinctiveOrRelatedLesson::BackClicked
 */
void BeDistinctiveOrRelatedLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}
