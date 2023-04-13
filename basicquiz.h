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
    explicit BasicQuiz(
        QString question,
        QVector<QString> correctFlags,
        QVector<QString> wrongFlags,
        QWidget *successScene,
        int currentStreak = 0,
        int targetStreak = 5,
        MainWindow *parent = nullptr
    );
    ~BasicQuiz();
private:
    Ui::BasicQuiz *ui;
    QWidget *successScene;
};

#endif // BASICQUIZ_H
