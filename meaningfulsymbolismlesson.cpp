/**
 * MeaningfulSymbolismLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses MeaningfulSymbolismLesson.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "meaningfulsymbolismlesson.h"
#include "ui_meaningfulsymbolismlesson.h"
#include "meaningfulsymbolismactivity.h"
#include <QPushButton>


MeaningfulSymbolismLesson::MeaningfulSymbolismLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::MeaningfulSymbolismLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::NextClicked);
    connect(ui->nextButton_3,
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
    connect(ui->mainMenu_3,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });
    connect(ui->restart,
            &QPushButton::clicked,
            this,
            &MeaningfulSymbolismLesson::Restart);

    connect(dynamic_cast<MeaningfulSymbolismActivity*>(widget(3)),
            &MeaningfulSymbolismActivity::SendScore,
            this,
            &MeaningfulSymbolismLesson::CaptureScore);

    connect(this,
            &MeaningfulSymbolismLesson::ResetQuiz,
            dynamic_cast<MeaningfulSymbolismActivity*>(widget(3)),
            &MeaningfulSymbolismActivity::Reset);
    connect(ui->speak1,
            &QPushButton::clicked,
            this,
            [this] {
                if(player->isPlaying()){
                    player->stop();
                }

                player->setSource(QUrl("qrc:/Audio/ms1.mp3"));
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

                player->setSource(QUrl("qrc:/Audio/ms2.mp3"));
                audioOutput->setVolume(100);
                player->play();
            });

}

MeaningfulSymbolismLesson::~MeaningfulSymbolismLesson()
{
    delete ui;
}


void MeaningfulSymbolismLesson::NextClicked(){
    if(player->isPlaying()){
        player->stop();
    }

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

void MeaningfulSymbolismLesson::CaptureScore(int score){
    ui->score->setText("Congrats [user name] you got " + QString::number(score) + " out of 5 correct.");
    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }
}

void MeaningfulSymbolismLesson::BackClicked(){
    if(player->isPlaying()){
        player->stop();
    }

    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
}

void MeaningfulSymbolismLesson::Restart(){
    emit ResetQuiz();
    setCurrentIndex(0);
}




