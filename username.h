/**
 * username.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by username.cpp and has methods and slots to display the screen where the user can enter a username.
 * This class handles the UI aspects, logic, and data for the username screen.
 * Reviewed by: Najman Husaini
 */
#ifndef USERNAME_H
#define USERNAME_H
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Username;
}

class Username : public QWidget
{
    Q_OBJECT

public:
    explicit Username(MainWindow *parent = nullptr);
    ~Username();

private slots:
    /**
     * @brief Username::doneClicked Saves the username and moves to the scene to the player greeting scene
     */
    void doneClicked();

private:
    Ui::Username *ui;
    MainWindow *mainWindow;
};
#endif // USERNAME_H
