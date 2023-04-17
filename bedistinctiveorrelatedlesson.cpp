#include "bedistinctiveorrelatedlesson.h"
#include "ui_bedistinctiveorrelatedlesson.h"
#include <QPushButton>

BeDistinctiveOrRelatedLesson::BeDistinctiveOrRelatedLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::BeDistinctiveOrRelatedLesson),
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
            &BeDistinctiveOrRelatedLesson::NextClicked);
    connect(NextButton2,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedLesson::NextClicked);
    connect(BackButton,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedLesson::BackClicked);


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
