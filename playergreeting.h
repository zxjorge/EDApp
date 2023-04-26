/**
 * playergreeting.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by username.cpp to display the screen where the user is greeted
 * This class handles the UI aspects, logic, and data for the player greeting screen.
 * Reviewed by: Najman Husaini
 */
#ifndef PLAYERGREETING_H
#define PLAYERGREETING_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class PlayerGreeting;
}

class PlayerGreeting : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerGreeting(MainWindow *parent = nullptr);
    ~PlayerGreeting();

private:
    Ui::PlayerGreeting *ui;
    MainWindow *mainWindow;
    Saves saves;
};

#endif // PLAYERGREETING_H
