#ifndef MEANINGFULSYMBOLISMLESSON_H
#define MEANINGFULSYMBOLISMLESSON_H

#include <QStackedWidget>

namespace Ui {
class MeaningfulSymbolismLesson;
}

class MeaningfulSymbolismLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit MeaningfulSymbolismLesson(QWidget *parent = nullptr);
    ~MeaningfulSymbolismLesson();

private slots:
    void NextClicked();
    void BackClicked();


private:
    Ui::MeaningfulSymbolismLesson *ui;
};

#endif // MEANINGFULSYMBOLISMLESSON_H
