/**
 * mainwindow.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by mainwindow.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the main window of the application
 * Reviewed by: Najman Husaini
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "saves.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Saves* getSaves();

public slots:
    /**
     * @brief switchScene Changes the central widget to be the given widget
     */
    void switchScene(QWidget *nextScene);

private:
    Ui::MainWindow *ui;
    Saves saves;
};
#endif // MAINWINDOW_H
