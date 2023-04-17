#ifndef DEFINITION_H
#define DEFINITION_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Definition;
}

class Definition : public QWidget
{
    Q_OBJECT

public:
    explicit Definition(MainWindow *parent = nullptr);
    ~Definition();

private:
    Ui::Definition *ui;
    MainWindow *mainWindow;
};

#endif // DEFINITION_H
