/**
 * MeaningfulSymbolismActivity.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by MeaningfulSymbolismActivity.cpp and has methods, signals, and slots.
 * This class handles the UI aspects, logic, and data for the Meaninful Symbolism lesson's activity.
 * Reviewed by: Sahil Karki
 */
#ifndef MEANINGFULSYMBOLISMACTIVITY_H
#define MEANINGFULSYMBOLISMACTIVITY_H
#include "mainwindow.h"
#include <QWidget>
#include <QVector>
#include <QString>
#include <QPointer>
#include <QPushButton>
#include <QIcon>


namespace Ui {
class MeaningfulSymbolismActivity;
}

class MeaningfulSymbolismActivity : public QWidget
{
    Q_OBJECT

public:
    explicit MeaningfulSymbolismActivity(MainWindow *parent = nullptr);
    ~MeaningfulSymbolismActivity();

private slots:
    /**
     * @brief InitializeQuestion Initializes the question that shows up as the prompt for the activity.
     */
    void InitializeQuestion();

    /**
     * @brief CheckAnswer Checks if the flags selected by the user are the right answer.
     */
    void CheckAnswer();

    /**
     * @brief NextQuestion Handles what the next question / prompt will be
     */
    void NextQuestion();

public slots:  
    /**
     * @brief Reset resets all the stats, and also calls initializeQuestion.
     */
    void Reset();

signals:
    /**
     * @brief SendScore signal that is emitted to send the score
     * @param score player's score
     */
    void SendScore(int score);


private:
    Ui::MeaningfulSymbolismActivity *ui;
    MainWindow *mainWindow;
    QVector<QString> prompts;
    QVector<QString> correctAnswers;
    int numbers[15];
    int currentIndex;
    int maxGames;
    int correctAns;
    void FirstQuestion();
    QPointer<QPushButton> lastClickedButton;
    QVector<QString> SavedIcons;
    int selectedIndex;
    int buttonIndex;
    int AnsweredQuestions;
};

#endif // MEANINGFULSYMBOLISMACTIVITY_H
