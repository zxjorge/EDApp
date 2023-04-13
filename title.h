#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Title;
}

class Title : public QWidget
{
    Q_OBJECT

public:
    explicit Title(MainWindow *parent = nullptr);
    ~Title();

private slots:
    void onButtonpressed();

private:
    Ui::Title *ui;
    MainWindow *mainWindow;
};

#endif // TITLE_H
