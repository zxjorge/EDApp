/**
 * bsod.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by bsod.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the Blue Screen of Death easter egg
 * Reviewed by: George Benyeogor
 */
#ifndef BSOD_H
#define BSOD_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Bsod;
}

class Bsod : public QWidget
{
    Q_OBJECT

public:
    explicit Bsod(MainWindow *parent = nullptr);
    ~Bsod();

private slots:
    /**
     * @brief onSceneEnd Called when the player exits the scene
     */
    void onSceneEnd();

private:
    Ui::Bsod *ui;
    MainWindow *mainWindow;
};

#endif // BSOD_H
