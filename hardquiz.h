#ifndef HARDQUIZ_H
#define HARDQUIZ_H

#include <QStackedWidget>

namespace Ui {
class hardquiz;
}

class hardquiz : public QStackedWidget
{
    Q_OBJECT

public:
    explicit hardquiz(QWidget *parent = nullptr);
    ~hardquiz();

private:
    Ui::hardquiz *ui;
};

#endif // HARDQUIZ_H
