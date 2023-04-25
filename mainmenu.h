/**
 * title.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by MainMenu.cpp and displays the menu screen using the constructor and a slot.
 * This class handles the UI aspects, logic, and data for the menu screen.
 * Reviewed by: Brayden Newsom
 */
#ifndef MAINMENU_H
#define MAINMENU_H
#include <QStackedWidget>
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief MainMenu::MainMenu Sets up the layout of the main menu. Connects menu buttons so scene will switch after being clicked.
     * @param parent widget that is used to help handle memory and resources.
     */
    explicit MainMenu(MainWindow *parent = nullptr);

    /**
     * @brief MainMenu::~MainMenu destructor of MainMenu
     */
    ~MainMenu();

public slots:
    /**
     * @brief MainMenu::SwitchToMainMenu switches scene to the main menu
     */
    void SwitchToMainMenu();


private:
    Ui::MainMenu *ui;
    MainWindow *mainWindow;


};

#endif // MAINMENU_H
