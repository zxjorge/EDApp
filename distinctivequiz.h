#ifndef DISTINCTIVEQUIZ_H
#define DISTINCTIVEQUIZ_H

#include <QStackedWidget>
#include "mainwindow.h"
#include "qpushbutton.h"

namespace Ui {
class DistinctiveQuiz;
}

class DistinctiveQuiz : public QStackedWidget
{
    Q_OBJECT

public:
    explicit DistinctiveQuiz(MainWindow *parent);
    ~DistinctiveQuiz();

private:
    Ui::DistinctiveQuiz *ui;
    QVector<QPushButton*> flagButtons;
    QVector<bool> flagSelected;
    QVector<bool> flagCorrect;
    bool answerStage = true;
    int correct = 0;
    int incorrect = 0;
    int missedCorrect = 0;
    int questions = 0;
    void setUpButtons(QVector<QString> symbolList, QString display1, QString display2);

    void changeButtonSelectColor(int i);
    void updateStatLabels();
private slots:
    void flag1Clicked();
    void flag2Clicked();
    void flag3Clicked();
    void flag4Clicked();

    // TODO Rename from snake case to camel case

    void on_next_clicked();
    void setUpQuestion();


    void on_hintButton_clicked();
    void on_ColorCodeButton_clicked();
};

#endif // DISTINCTIVEQUIZ_H
