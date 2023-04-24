/**
 * KeepSimpleLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'Keep It Simple' lesson being taught
 * Reviewed by: Sahil Karki
 */
#ifndef KEEPSIMPLELESSON_H
#define KEEPSIMPLELESSON_H
#include "mainwindow.h"
#include <QStackedWidget>


namespace Ui {
class KeepSimpleLesson;
}

class KeepSimpleLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit KeepSimpleLesson(MainWindow *parent = nullptr);
    ~KeepSimpleLesson();

private slots:
    void NextClicked();
    void BackClicked();

private:
    Ui::KeepSimpleLesson *ui;
    MainWindow *mainWindow;

};

#endif // KEEPSIMPLELESSON_H
