/**
 * BeDistinctiveOrRelatedLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'Be Distinctive Or Related' lesson being taught
 * Reviewed by: Sahil Karki
 */
#ifndef BEDISTINCTIVEORRELATEDLESSON_H
#define BEDISTINCTIVEORRELATEDLESSON_H
#include "mainmenu.h"
#include <QStackedWidget>

namespace Ui {
class BeDistinctiveOrRelatedLesson;
}

class BeDistinctiveOrRelatedLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit BeDistinctiveOrRelatedLesson(MainWindow *parent = nullptr);
    ~BeDistinctiveOrRelatedLesson();

private slots:
    void NextClicked();
    void BackClicked();


private:
    Ui::BeDistinctiveOrRelatedLesson *ui;
    MainWindow *mainWindow;
};

#endif // BEDISTINCTIVEORRELATEDLESSON_H
