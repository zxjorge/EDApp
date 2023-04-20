/**
 * NoLetteringOrSealsLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'No Lettering Or Seals' lesson being taught
 * Reviewed by: Sahil Karki
 */
#ifndef NOLETTERINGORSEALSLESSON_H
#define NOLETTERINGORSEALSLESSON_H
#include "mainmenu.h"
#include <QStackedWidget>

namespace Ui {
class NoLetteringOrSealsLesson;
}

class NoLetteringOrSealsLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit NoLetteringOrSealsLesson(MainWindow *parent = nullptr);
    ~NoLetteringOrSealsLesson();

private slots:
    void NextClicked();
    void BackClicked();

private:
    Ui::NoLetteringOrSealsLesson *ui;
    MainWindow *mainWindow;

};

#endif // NOLETTERINGORSEALSLESSON_H
