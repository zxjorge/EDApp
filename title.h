/**
 * title.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by title.cpp and has methods, signals, and slots to display the title screen.
 * This class handles the UI aspects, logic, and data for the title screen.
 * Reviewed by: Arkein Singh
 */
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
    /**
     * @brief Title::Title Constructor for Title
     * @param parent widget that is used to help handle memory and resources.
     */
    explicit Title(MainWindow *parent = nullptr);

    /**
     * @brief Title::Title Constructor for Title
     * @param parent widget that is used to help handle memory and resources.
     */
    ~Title();

    /**
     * @brief Title::paintEvent Randomly selects flags and paints them to display on the title page.
     * @param Pointer to paint event
     */
    void paintEvent(QPaintEvent *event);

private slots:
    /**
     * @brief Title::onButtonpressed Handles switching the scenes to a definiton of Vexology when the user clicks the "A what?" button
     */
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
    /**
     * @brief Title::timerEvent Updates the painting based on QTimer
     * @param pointer to QTimerEvent
     */
    void timerEvent(QTimerEvent *event);

};

#endif // TITLE_H
