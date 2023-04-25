#ifndef DISTINCTIVEQUIZ_H
#define DISTINCTIVEQUIZ_H

#include <QStackedWidget>
#include "mainwindow.h"
#include "qlabel.h"
#include "qpushbutton.h"

namespace Ui {
class DistinctiveQuiz;
}

class DistinctiveQuiz : public QStackedWidget
{
    Q_OBJECT

public:
    /**
     * @brief DistinctiveQuiz
     * @param parent
     */
    explicit DistinctiveQuiz(MainWindow *parent);

    /**
     * @brief DistinctiveQuiz::~DistinctiveQuiz
     */
    ~DistinctiveQuiz();

private:
    Ui::DistinctiveQuiz *ui;
    QVector<QPushButton*> flagButtons;
    QVector<QLabel*> flagScores;
    QVector<bool> flagSelected;
    QVector<bool> flagCorrect;
    const int targetScore = 15;
    bool answerStage = true;
    int correct = 0;
    int incorrect = 0;
    int missedCorrect = 0;
    int questions = 0;
    int score = 0;

    /**
     * @brief DistinctiveQuiz::setUpButtons
     * @param symbolList
     * @param display1
     * @param display2
     */
    void setUpButtons(QVector<QString> symbolList, QString display1, QString display2);

    /**
     * @brief DistinctiveQuiz::changeButtonSelectColor
     * @param i
     */
    void changeButtonSelectColor(int i);

    /**
     * @brief DistinctiveQuiz::updateStatLabels
     */
    void updateStatLabels();

private slots:
    /**
     * @brief flag1Clicked
     */
    void flag1Clicked();

    /**
     * @brief flag2Clicked
     */
    void flag2Clicked();

    /**
     * @brief flag3Clicked
     */
    void flag3Clicked();

    /**
     * @brief flag4Clicked
     */
    void flag4Clicked();

    // TODO Rename from snake case to camel case

    void on_next_clicked();
    void setUpQuestion();
    void on_hintButton_clicked();
};

#endif // DISTINCTIVEQUIZ_H
