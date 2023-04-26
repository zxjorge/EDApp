/**
 * KeepSimpleLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses KeepSimpleLesson.h header file and implements all its methods.
 * Reviewed by: Arkein Singh
 */
#include "keepsimplelesson.h"
#include "basicquiz.h"
#include "keepsimpleactivity.h"
#include "ui_keepsimplelesson.h"
#include <QPushButton>
#include "mainmenu.h"
#include "flagconstants.h"


KeepSimpleLesson::KeepSimpleLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::KeepSimpleLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(ui->nextButton_3,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(ui->nextButton_4,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);

    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::BackClicked);
    connect(ui->backButton_2,
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
    connect(ui->mainMenu_3,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });

    connect(ui->speak1,
            &QPushButton::clicked,
            this,
            [this] {
                if(player->isPlaying()){
                    player->stop();
                }

                player->setSource(QUrl("qrc:/Audio/ks1.mp3"));
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

                player->setSource(QUrl("qrc:/Audio/ks2.mp3"));
                audioOutput->setVolume(100);
                player->play();
            });

    connect(ui->speak3,
            &QPushButton::clicked,
            this,
            [this] {
                if(player->isPlaying()){
                    player->stop();
                }

                player->setSource(QUrl("qrc:/Audio/ks3.mp3"));
                audioOutput->setVolume(100);
                player->play();
            });
    setCurrentIndex(0);
}


KeepSimpleLesson::~KeepSimpleLesson()
{
    delete ui;
}


void KeepSimpleLesson::NextClicked(){
    if(player->isPlaying()){
        player->stop();
    }

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    } else {
        mainWindow->switchScene(new BasicQuiz(
            "Which flag is simpler?",
            SIMPLE_FLAGS,
            COMPLEX_COLOR_FLAGS,
            new KeepSimpleActivity(mainWindow),
            mainWindow
            ));
    }
}

void KeepSimpleLesson::BackClicked(){
    if(player->isPlaying()){
        player->stop();
    }

    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}










