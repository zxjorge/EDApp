#ifndef DISTINCTIVEQUIZ_H
#define DISTINCTIVEQUIZ_H

#include <QStackedWidget>

namespace Ui {
class DistinctiveQuiz;
}

class DistinctiveQuiz : public QStackedWidget
{
    Q_OBJECT

public:
    explicit DistinctiveQuiz(QWidget *parent = nullptr);
    ~DistinctiveQuiz();

private:
    Ui::DistinctiveQuiz *ui;
};

#endif // DISTINCTIVEQUIZ_H
