/**
 * MeaningfulSymbolismLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by KeepSimpleLesson.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the 'Meaningful Symbolism' lesson being taught.
 * Reviewed by: Sahil Karki
 */
#ifndef MEANINGFULSYMBOLISMLESSON_H
#define MEANINGFULSYMBOLISMLESSON_H
#include "mainmenu.h"
#include <QStackedWidget>

namespace Ui {
class MeaningfulSymbolismLesson;
}

class MeaningfulSymbolismLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit MeaningfulSymbolismLesson(MainWindow *parent = nullptr);
    ~MeaningfulSymbolismLesson();

private slots:
    void NextClicked();
    void BackClicked();


private:
    Ui::MeaningfulSymbolismLesson *ui;
    MainWindow *mainWindow;
};

#endif // MEANINGFULSYMBOLISMLESSON_H
