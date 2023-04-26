/**
 * title.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by title.cpp and has methods, signals, and slots to display the title screen.
 * This class handles the UI aspects, logic, and data for the title screen.
 * Reviewed by: Najman Husaini
 */
#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include "mainwindow.h"
#include "qtimer.h"
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

private slots:
    /**
     * @brief Title::onButtonpressed Handles switching the scenes to a definiton of Vexology when the user clicks the "A what?" button
     */
    void onButtonpressed();

private:
    Ui::Title *ui;
    MainWindow *mainWindow;
    QTimer updateTimer;
};

#endif // TITLE_H
