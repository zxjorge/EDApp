#ifndef BEDISTINCTIVEORRELATEDACTIVITY_H
#define BEDISTINCTIVEORRELATEDACTIVITY_H
#include <QWidget>
#include "mainwindow.h"
#include "qlabel.h"
#include "qpushbutton.h"

namespace Ui {
class BeDistinctiveOrRelatedActivity;
}

class BeDistinctiveOrRelatedActivity : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief BeDistinctiveOrRelatedActivity
     * @param parent
     */
    explicit BeDistinctiveOrRelatedActivity(MainWindow *parent = nullptr);

    /**
     * @brief BeDistinctiveOrRelatedActivity::~BeDistinctiveOrRelatedActivity
     */
    ~BeDistinctiveOrRelatedActivity();

signals:
    /**
     * @brief SendActivityDetails
     * @param questions
     * @param correct
     * @param incorrect
     * @param missedCorrect
     */
    void SendActivityDetails(int questions, int correct, int incorrect, int missedCorrect);

public slots:

    /**
     * @brief BeDistinctiveOrRelatedActivity::Reset
     */
    void Reset();


private:
    Ui::BeDistinctiveOrRelatedActivity *ui;
    MainWindow *mainWindow;
    QVector<QPushButton*> flagButtons;
    QVector<QLabel*> flagScores;
    QVector<bool> flagSelected;
    QVector<bool> flagCorrect;
    const int targetScore = 5;
    bool answerStage = true;
    int correct;
    int incorrect;
    int missedCorrect;
    int questions;
    int score;


    /**
     * @brief BeDistinctiveOrRelatedActivity::setUpButtons
     * @param symbolList
     * @param display1
     * @param display2
     */
    void SetUpButtons(QVector<QString> symbolList, QString display1, QString display2);

    /**
     * @brief BeDistinctiveOrRelatedActivity::changeButtonSelectColor
     * @param i
     */
    void ChangeButtonSelectColor(int i);

private slots:
    /**
     * @brief BeDistinctiveOrRelatedActivity::Flag1Clicked
     */
    void Flag1Clicked();

    /**
     * @brief BeDistinctiveOrRelatedActivity::Flag2Clicked
     */
    void Flag2Clicked();

    /**
     * @brief BeDistinctiveOrRelatedActivity::Flag3Clicked
     */
    void Flag3Clicked();

    /**
     * @brief BeDistinctiveOrRelatedActivity::Flag4Clicked
     */
    void Flag4Clicked();

    /**
     * @brief BeDistinctiveOrRelatedActivity::NextClicked
     */
    void NextClicked();

    /**
     * @brief BeDistinctiveOrRelatedActivity::SetUpQuestion
     */
    void SetUpQuestion();

    /**
     * @brief BeDistinctiveOrRelatedActivity::HintClicked
     */
    void HintClicked();
};

#endif // BEDISTINCTIVEORRELATEDACTIVITY_H
