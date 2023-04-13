#ifndef USEBASICCOLORSLESSON_H
#define USEBASICCOLORSLESSON_H

#include <QStackedWidget>

namespace Ui {
class UseBasicColorsLesson;
}

class UseBasicColorsLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit UseBasicColorsLesson(QWidget *parent = nullptr);
    ~UseBasicColorsLesson();

private slots:
    void NextClicked();
    void BackClicked();

private:
    Ui::UseBasicColorsLesson *ui;
};

#endif // USEBASICCOLORSLESSON_H
