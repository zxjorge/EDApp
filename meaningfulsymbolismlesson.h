/**
 * MeaningfulSymbolismLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'Meaningful Symbolism' lesson being taught.
 * Reviewed by: George Benyeogor
 */
#ifndef MEANINGFULSYMBOLISMLESSON_H
#define MEANINGFULSYMBOLISMLESSON_H
#include "mainmenu.h"
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QAudioOutput>

namespace Ui {
class MeaningfulSymbolismLesson;
}


class MeaningfulSymbolismLesson : public QStackedWidget
{
    Q_OBJECT

public:
    /**
     * @brief MeaningfulSymbolismLesson::MeaningfulSymbolismLesson Constructor for MeaningfulSymbolismLesson
     * @param parent widget that is used to help handle memory and resources.
     */
    explicit MeaningfulSymbolismLesson(MainWindow *parent = nullptr);

    /**
     * @brief MeaningfulSymbolismLesson::~MeaningfulSymbolismLesson destructor for MeaningfulSymbolismLesson
     */
    ~MeaningfulSymbolismLesson();

signals:
    void ResetQuiz();

private slots:
    /**
     * @brief NextClicked
     */
    void NextClicked();

    /**
     * @brief MeaningfulSymbolismLesson::BackClicked Slot that handles what happens when the back button is clicked in the UI
     */
    void BackClicked();
    /**
     * @brief CaptureScore
     * @param score
     */
    void CaptureScore(int score);
    /**
     * @brief Restart
     */
    void Restart();


private:
    Ui::MeaningfulSymbolismLesson *ui;
    MainWindow *mainWindow;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // MEANINGFULSYMBOLISMLESSON_H
