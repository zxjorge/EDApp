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
