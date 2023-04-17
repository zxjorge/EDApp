#ifndef KEEPSIMPLELESSON_H
#define KEEPSIMPLELESSON_H
#include "mainmenu.h"
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
    void animateFlag();
};

#endif // KEEPSIMPLELESSON_H
