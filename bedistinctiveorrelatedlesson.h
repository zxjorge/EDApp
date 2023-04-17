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
