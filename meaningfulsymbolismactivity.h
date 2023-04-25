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
    void InitializeQuestion();
    void CheckAnswer();
    void NextQuestion();

public slots:
    void Reset();

signals:
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
