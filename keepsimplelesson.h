#ifndef KEEPSIMPLELESSON_H
#define KEEPSIMPLELESSON_H

#include <QStackedWidget>

namespace Ui {
class KeepSimpleLesson;
}

class KeepSimpleLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit KeepSimpleLesson(QWidget *parent = nullptr);
    ~KeepSimpleLesson();

private slots:
    void NextClicked();
    void BackClicked();

private:
    Ui::KeepSimpleLesson *ui;
};

#endif // KEEPSIMPLELESSON_H
