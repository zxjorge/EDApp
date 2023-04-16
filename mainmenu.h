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
    explicit MainMenu(MainWindow *parent = nullptr);
    ~MainMenu();

public slots:
    void SwitchToMainMenu();


private:
    Ui::MainMenu *ui;
    MainWindow *mainWindow;


};

#endif // MAINMENU_H
