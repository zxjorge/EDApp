#ifndef DISTINCTIVEQUIZ_H
#define DISTINCTIVEQUIZ_H

#include <QStackedWidget>
#include "mainwindow.h"

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
    bool flag1Selected = false;
    bool flag2Selected = false;
    bool flag3Selected = false;
    bool flag4Selected = false;

private slots:
    void flag1Clicked();
    void flag2Clicked();
    void flag3Clicked();
    void flag4Clicked();
    void on_next_clicked();
};

#endif // DISTINCTIVEQUIZ_H
