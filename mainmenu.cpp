#include "mainmenu.h"
#include "finaldesignactivity.h"
#include "ui_mainmenu.h"
#include <QPushButton>
#include "bedistinctiveorrelatedlesson.h"
#include "keepsimplelesson.h"
#include "meaningfulsymbolismlesson.h"
#include "usebasiccolorslesson.h"
#include "saves.h"
#include <QDebug>


/**
 * @brief MainMenu::MainMenu
 * @param parent
 */
MainMenu::MainMenu(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    mainWindow(parent)
{

    ui->setupUi(this);
    int lessonsCompleted = parent->getSaves()->getNumberOfLessonsSaved();
    if(lessonsCompleted == 2){
        ui->DesignButton->setEnabled(true);
    }

    const QJsonArray* completeLessons = parent->getSaves()->getSavedLessonsArray();

    if (completeLessons->contains("KeepSimpleLesson")) {
        ui->keepSimpleLabel->setText("Complete");
    }
    if (completeLessons->contains("UseBasicColorsLesson")) {
        ui->colorsLabel->setText("Complete");
    }

    connect(ui->BDRButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new BeDistinctiveOrRelatedLesson(mainWindow));
            });

    connect(ui->KISButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new KeepSimpleLesson(mainWindow));
            });

    connect(ui->U23Button,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new UseBasicColorsLesson(mainWindow));
            });

    connect(ui->UMSButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MeaningfulSymbolismLesson(mainWindow));
            });

    connect(ui->DesignButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new FinalDesignActivity(mainWindow));
            });
}

/**
 * @brief MainMenu::~MainMenu
 */
MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::SwitchToMainMenu(){
    mainWindow->switchScene(this);
}


