/**
 * BeDistinctiveOrRelatedLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses BeDistinctiveOrRelatedLesson.h header file and implements all its methods.
 * Reviewed by: Najman Husaini
 */
#include "bedistinctiveorrelatedlesson.h"
#include "ui_bedistinctiveorrelatedlesson.h"
#include "bedistinctiveorrelatedactivity.h"
#include <QPushButton>
#include <QUrl>
#include <QString>
#include <QAudioOutput>
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
    connect(ui->mainMenu_3,
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
            &BeDistinctiveOrRelatedLesson::NextClicked);

    connect(dynamic_cast<BeDistinctiveOrRelatedActivity*>(widget(4)),
            &BeDistinctiveOrRelatedActivity::SendActivityDetails,
            this,
            &BeDistinctiveOrRelatedLesson::CaptureDetails);

    connect(this,
            &BeDistinctiveOrRelatedLesson::ResetQuiz,
            dynamic_cast<BeDistinctiveOrRelatedActivity*>(widget(4)),
            &BeDistinctiveOrRelatedActivity::Reset);

    connect(ui->restart,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedLesson::Restart);

    setCurrentIndex(1);
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

void BeDistinctiveOrRelatedLesson::CaptureDetails(int questions, int correct, int incorrect, int missedCorrect){
    ui->congrats->setText("Congrats " + mainWindow->getSaves()->getUsername());
    QString statText = "Completed Questions: " + QString::number(questions);
    ui->CQLabel->setText(statText);
    statText = "Total Correct: " + QString::number(correct);
    ui->TCLabel->setText(statText);
    statText = "Total Incorrect: " + QString::number(incorrect);
    ui->TILabel->setText(statText);
    statText = "Total Missed: " + QString::number(missedCorrect);
    ui->TMLabel->setText(statText);
    mainWindow->getSaves()->Save("BeDistinctiveOrRelatedLesson", mainWindow->getSaves()->getUsername());
    setCurrentIndex(0);
}

void BeDistinctiveOrRelatedLesson::Restart(){
    emit ResetQuiz();
    setCurrentIndex(1);
}

