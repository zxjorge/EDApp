#ifndef BASICQUIZ_H
#define BASICQUIZ_H

#include <QWidget>
//#include <QTimer>
#include "mainwindow.h"
//#include <QPainter>

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
        MainWindow *parent,
        int currentStreak = 0,
        int targetStreak = 5
    );

    ~BasicQuiz();
    //virtual void paintEvent(QPaintEvent *);



signals:

public slots:
    //void updateWorld();

private:
    Ui::BasicQuiz *ui;
//    b2Body* body = 0;
//    QTimer timer;
//    QImage image;
//    b2World world;
//    QWidget *successScene;
//    QString question;
//    QVector<QString> correctFlags;
//    QVector<QString> wrongFlags;
//    int targetStreak = 5;
    MainWindow *parent;

//    void flagAnimation(QWidget*, float, float);


};

#endif // BASICQUIZ_H
