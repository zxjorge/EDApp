/**
 * BeDistinctiveOrRelatedLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses BeDistinctiveOrRelatedLesson.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "bedistinctiveorrelatedlesson.h"
#include "ui_bedistinctiveorrelatedlesson.h"
#include <QPushButton>
#include <QUrl>
#include <QAudioOutput>
#include "distinctivequiz.h"
#include "mainmenu.h"


BeDistinctiveOrRelatedLesson::BeDistinctiveOrRelatedLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::BeDistinctiveOrRelatedLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedLesson::NextClicked);
    connect(ui->nextButton_3,
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

    connect(ui->speak,
            &QPushButton::clicked,
            this,
            [this] {
                if(player->isPlaying()){
                    player->stop();
                }

                player->setSource(QUrl("qrc:/Audio/bdsr1.mp3"));
                audioOutput->setVolume(100);
                player->play();
            });

    connect(ui->speak2,
            &QPushButton::clicked,
            this,
            [this] {
                if(player->isPlaying()){
                    player->stop();
                }

                player->setSource(QUrl("qrc:/Audio/bdsr2.mp3"));
                audioOutput->setVolume(100);
                player->play();
            });

    connect(ui->nextButton_3,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new DistinctiveQuiz(mainWindow));
            });
}

BeDistinctiveOrRelatedLesson::~BeDistinctiveOrRelatedLesson()
{
    delete ui;
}

void BeDistinctiveOrRelatedLesson::NextClicked(){
    if(player->isPlaying()){
        player->stop();
    }
    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

void BeDistinctiveOrRelatedLesson::BackClicked(){
    if(player->isPlaying()){
        player->stop();
    }
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}

