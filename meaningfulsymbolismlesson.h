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
