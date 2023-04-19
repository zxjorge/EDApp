#include "meaningfulsymbolismlesson.h"
#include "ui_meaningfulsymbolismlesson.h"
#include <QPushButton>

/**
 * @brief MeaningfulSymbolismLesson::MeaningfulSymbolismLesson
 * @param parent
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

MeaningfulSymbolismLesson::~MeaningfulSymbolismLesson()
{
    delete ui;
}

/**
 * @brief MeaningfulSymbolismLesson::NextClicked
 */
void MeaningfulSymbolismLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

/**
 * @brief MeaningfulSymbolismLesson::BackClicked
 */
void MeaningfulSymbolismLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}




