/**
 * KeepSimpleLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'Keep It Simple' lesson being taught
 * Reviewed by: Brayden Newsom
 */
#ifndef KEEPSIMPLELESSON_H
#define KEEPSIMPLELESSON_H
#include "mainwindow.h"
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QAudioOutput>


namespace Ui {
class KeepSimpleLesson;
}

class KeepSimpleLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit KeepSimpleLesson(MainWindow *parent = nullptr);
    ~KeepSimpleLesson();

private slots:

   /**
    * @brief KeepSimpleLesson::NextClicked Slot that handles what happens when the next button is clicked in the UI
    */
    void NextClicked();

   /**
    * @brief KeepSimpleLesson::BackClicked Slot that handles what happens when the back button is clicked in the UI
    */
    void BackClicked();


private:
    Ui::KeepSimpleLesson *ui;
    MainWindow *mainWindow;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

};

#endif // KEEPSIMPLELESSON_H
