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
    int flagWidth = 150;
    int flagHeight = 75;
    int flagSpacing = 200;
    int flagY = 325;
    QVector<QImage> flagsToDraw;
    QVector<QImage> oldFlagsToDraw;
    QVector<int> flagsX;
    QVector<int> flagsResX;
    const int numOfFlags = 4;

protected:
    void timerEvent(QTimerEvent *event);

};

#endif // TITLE_H
