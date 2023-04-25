/**
 * UseBasicColorsLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'Use 2-3 Basic Colors' lesson being taught
 * Reviewed by: Sahil Karki
 */
#ifndef USEBASICCOLORSLESSON_H
#define USEBASICCOLORSLESSON_H
#include "mainwindow.h"
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QAudioOutput>

namespace Ui {
class UseBasicColorsLesson;
}

class UseBasicColorsLesson : public QStackedWidget
{
    Q_OBJECT

public:

    /**
     * @brief UseBasicColorsLesson::UseBasicColorsLesson Constructor for UseBasicColorsLesson
     * @param parent widget that is used to help handle memory and resources.
     */
    explicit UseBasicColorsLesson(MainWindow *parent = nullptr);

    /**
     * @brief UseBasicColorsLesson::~UseBasicColorsLesson Destructor for UseBasicColorsLesson
     */
    ~UseBasicColorsLesson();

private slots:
    /**
     * @brief UseBasicColorsLesson::NextClicked Slot that handles what happens when the next button is clicked in the UI
     */
    void NextClicked();

    /**
     * @brief UseBasicColorsLesson::BackClicked Slot that handles what happens when the back button is clicked in the UI
     */
    void BackClicked();

private:
    Ui::UseBasicColorsLesson *ui;
    MainWindow *mainWindow;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // USEBASICCOLORSLESSON_H
