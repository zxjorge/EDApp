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

private slots:
    void buttonClicked();

private:
    Ui::PlayerGreeting *ui;
    MainWindow *mainWindow;
    Saves saves;
};

#endif // PLAYERGREETING_H
