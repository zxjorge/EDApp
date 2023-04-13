#ifndef NOLETTERINGORSEALSLESSON_H
#define NOLETTERINGORSEALSLESSON_H

#include <QStackedWidget>

namespace Ui {
class NoLetteringOrSealsLesson;
}

class NoLetteringOrSealsLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit NoLetteringOrSealsLesson(QWidget *parent = nullptr);
    ~NoLetteringOrSealsLesson();

private slots:
    void NextClicked();
    void BackClicked();

private:
    Ui::NoLetteringOrSealsLesson *ui;
};

#endif // NOLETTERINGORSEALSLESSON_H
