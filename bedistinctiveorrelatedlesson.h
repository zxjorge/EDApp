#ifndef BEDISTINCTIVEORRELATEDLESSON_H
#define BEDISTINCTIVEORRELATEDLESSON_H

#include <QStackedWidget>

namespace Ui {
class BeDistinctiveOrRelatedLesson;
}

class BeDistinctiveOrRelatedLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit BeDistinctiveOrRelatedLesson(QWidget *parent = nullptr);
    ~BeDistinctiveOrRelatedLesson();

private slots:
    void NextClicked();
    void BackClicked();


private:
    Ui::BeDistinctiveOrRelatedLesson *ui;
};

#endif // BEDISTINCTIVEORRELATEDLESSON_H
