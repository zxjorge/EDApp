/**
 * BeDistinctiveOrRelatedLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'Be Distinctive Or Related' lesson being taught
 * Reviewed by: Sahil Karki
 */
#ifndef BEDISTINCTIVEORRELATEDLESSON_H
#define BEDISTINCTIVEORRELATEDLESSON_H
#include "mainwindow.h"
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QAudioOutput>



namespace Ui {
class BeDistinctiveOrRelatedLesson;
}

class BeDistinctiveOrRelatedLesson : public QStackedWidget
{
    Q_OBJECT

public:
   /**
    * @brief BeDistinctiveOrRelatedLesson::BeDistinctiveOrRelatedLesson Constructor for BeDistinctiveOrRelatedLesson
    * @param parent widget that is used to help handle memory and resources.
    */
    explicit BeDistinctiveOrRelatedLesson(MainWindow *parent = nullptr);

   /**
    * @brief BeDistinctiveOrRelatedLesson::~BeDistinctiveOrRelatedLesson destructor for BeDistinctiveOrRelatedLesson
    */
    ~BeDistinctiveOrRelatedLesson();
signals:
    void ResetQuiz();

private slots:
    /**
     * @brief BeDistinctiveOrRelatedLesson::NextClicked Slot that handles what happens when the next button is clicked in the UI
     */
    void NextClicked();

    /**
     * @brief BeDistinctiveOrRelatedLesson::BackClicked Slot that handles what happens when the back button is clicked in the UI
     */
    void BackClicked();

    /**
     * @brief CaptureDetails
     * @param questions
     * @param correct
     * @param incorrect
     * @param missedCorrect
     */
    void CaptureDetails(int questions, int correct, int incorrect, int missedCorrect);

    /**
     * @brief BeDistinctiveOrRelatedLesson::Restart
     */
    void Restart();


private:
    Ui::BeDistinctiveOrRelatedLesson *ui;
    MainWindow *mainWindow;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;


};

#endif // BEDISTINCTIVEORRELATEDLESSON_H
