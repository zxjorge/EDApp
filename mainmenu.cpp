/**
 * Title.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses mainmenu.h header file and implements all its methods.
 * Reviewed by: Brayden newsom
 */
#include "mainmenu.h"
#include "finaldesignactivity.h"
#include "ui_mainmenu.h"
#include <QPushButton>
#include <QPixmap>
#include "bedistinctiveorrelatedlesson.h"
#include "keepsimplelesson.h"
#include "meaningfulsymbolismlesson.h"
#include "usebasiccolorslesson.h"
#include "saves.h"
#include <QLabel>
#include <QDebug>

MainMenu::MainMenu(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    mainWindow(parent)
{

    ui->setupUi(this);
    int lessonsCompleted = parent->getSaves()->getNumberOfLessonsSaved();
    if(lessonsCompleted == 4){
        ui->DesignButton->setEnabled(true);
        ui->DesignButton->setStyleSheet("color: rgb(67, 200, 200);"
                                        "border-image: url(:/Icons/banner.jpg);");
    }

    const QJsonArray* completeLessons = parent->getSaves()->getSavedLessonsArray();

    if (completeLessons->contains("KeepSimpleLesson")) {
        QLabel * pLabel = new QLabel(ui->KISButton);
        QPixmap pixmap(":/Icons/check.png");
        pLabel->setPixmap(pixmap);
        pLabel->setAttribute(Qt::WA_TranslucentBackground);
        pLabel->show();
    }
    if (completeLessons->contains("UseBasicColorsLesson")) {
        QLabel * pLabel = new QLabel(ui->U23Button);
        QPixmap pixmap(":/Icons/check.png");
        pLabel->setPixmap(pixmap);
        pLabel->setAttribute(Qt::WA_TranslucentBackground);
        pLabel->show();
    }
    if (completeLessons->contains("MeaningfulSymbolismLesson")) {
        QLabel * pLabel = new QLabel(ui->UMSButton);
        QPixmap pixmap(":/Icons/check.png");
        pLabel->setPixmap(pixmap);
        pLabel->setAttribute(Qt::WA_TranslucentBackground);
        pLabel->show();
    }
    if (completeLessons->contains("BeDistinctiveOrRelatedLesson")) {
        QLabel * pLabel = new QLabel(ui->BDRButton);
        QPixmap pixmap(":/Icons/check.png");
        pLabel->setPixmap(pixmap);
        pLabel->setAttribute(Qt::WA_TranslucentBackground);
        pLabel->show();
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

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::SwitchToMainMenu(){
    mainWindow->switchScene(this);
}


