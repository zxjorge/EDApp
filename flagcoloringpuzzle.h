#ifndef FLAGCOLORINGPUZZLE_H
#define FLAGCOLORINGPUZZLE_H

#include <QWidget>

namespace Ui {
class FlagColoringPuzzle;
}

class FlagColoringPuzzle : public QWidget
{
    Q_OBJECT

public:
    explicit FlagColoringPuzzle(QWidget *parent = nullptr);
    ~FlagColoringPuzzle();

private:
    Ui::FlagColoringPuzzle *ui;
};

#endif // FLAGCOLORINGPUZZLE_H
