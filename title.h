#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include "mainwindow.h"
#include<QPixmap>
namespace Ui {
class Title;
}

class Title : public QWidget
{
    Q_OBJECT

public:
    explicit Title(MainWindow *parent = nullptr);
    ~Title();
    void paintEvent(QPaintEvent *event);
private slots:
    void onButtonpressed();

private:
    Ui::Title *ui;
    MainWindow *mainWindow;
    const int numOfFlags = 4;
    const int flagWidth = 150;
    const int flagHeight = 75;
    const int flagSpacing = 200;
    int flagY;
    const double sliderSpeed = 1;
    QVector<QImage> flagsToDraw;
    QVector<QImage> oldFlagsToDraw;
    QVector<double> flagsX;
    QVector<double> flagsResX;


protected:
    void timerEvent(QTimerEvent *event);

};

#endif // TITLE_H
