/**
 * basicquiz.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by basicquiz.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for all the quizzes
 * Reviewed by: Najman Husaini
 */
#ifndef BASICQUIZ_H
#define BASICQUIZ_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class BasicQuiz;
}

class BasicQuiz : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief BasicQuiz Constructs a randomized quiz involving a right and wrong answer
     * @param question The question to display to the user
     * @param correctFlags A vector of flags that are the correct choice
     * @param wrongFlags A vector of flags that are the wrong choice
     * @param successScene The widget to switch to after the quiz completes
     * @param parent The main window
     * @param currentStreak The player's current win streak
     * @param targetStreak The win streak required to win
     */
    explicit BasicQuiz(
        QString question,
        QVector<QString> correctFlags,
        QVector<QString> wrongFlags,
        QWidget *successScene,
        MainWindow *parent,
        int currentStreak = 0,
        int targetStreak = 5,
        QString lastCorrectFlag = "",
        QString lastWrongFlag = ""
    );

    ~BasicQuiz();

private:
    Ui::BasicQuiz *ui;
    MainWindow *parent;
};

#endif // BASICQUIZ_H
