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
