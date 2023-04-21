/**
 * UseBasicColorsLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'Use 2-3 Basic Colors' lesson being taught
 * Reviewed by: Sahil Karki
 */
#ifndef USEBASICCOLORSLESSON_H
#define USEBASICCOLORSLESSON_H
#include "mainmenu.h"
#include <QStackedWidget>

namespace Ui {
class UseBasicColorsLesson;
}

class UseBasicColorsLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit UseBasicColorsLesson(MainWindow *parent = nullptr);
    ~UseBasicColorsLesson();

private slots:
    void NextClicked();
    void BackClicked();

private:
    Ui::UseBasicColorsLesson *ui;
    MainWindow *mainWindow;
};

#endif // USEBASICCOLORSLESSON_H
