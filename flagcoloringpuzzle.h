#ifndef FLAGCOLORINGPUZZLE_H
#define FLAGCOLORINGPUZZLE_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class FlagColoringPuzzle;
}

class FlagColoringPuzzle : public QWidget
{
    Q_OBJECT

public:
    explicit FlagColoringPuzzle(MainWindow *parent = nullptr);
    ~FlagColoringPuzzle();

private slots:

private:
    Ui::FlagColoringPuzzle *ui;
    MainWindow *mainWindow;
};

#endif // FLAGCOLORINGPUZZLE_H
