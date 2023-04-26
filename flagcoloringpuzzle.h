/**
 * flagcoloringpuzzle.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by flagcoloringpuzzle.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the flag coloring puzzle in the keep simple activity
 * Reviewed by: Arkein Singh
 */
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
