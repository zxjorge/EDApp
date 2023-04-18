#ifndef KEEPSIMPLELESSON_H
#define KEEPSIMPLELESSON_H
#include "mainmenu.h"
#include <QStackedWidget>
#include "box2d/Box2D.h"

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
    //void update();

private:
    Ui::KeepSimpleLesson *ui;
    MainWindow *mainWindow;

};

#endif // KEEPSIMPLELESSON_H
