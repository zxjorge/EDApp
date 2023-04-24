/**
 * definition.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by definition.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the definition of vexillology scene
 * Reviewed by: Sahil Karki
 */
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

private slots:
    /**
     * Called when the Ok button is clicked
     */
    void OkClicked();

private:
    Ui::Definition *ui;
    MainWindow *mainWindow;
};

#endif // DEFINITION_H
