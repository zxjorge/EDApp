#ifndef FLAGSTRIP_H
#define FLAGSTRIP_H

#include <QWidget>
#include <QElapsedTimer>

const int SPEED = 50;
const int FLAG_WIDTH = 1000;
const double SCALE = 0.275;
const int FLAG_SPACING = 50;

namespace Ui {
class FlagStrip;
}

class FlagStrip : public QWidget
{
    Q_OBJECT

public:
    explicit FlagStrip(QWidget *parent = nullptr);
    ~FlagStrip();

    void setTimeOffset(int offset);
    void setFlags(QVector<QPixmap> flags);
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::FlagStrip *ui;
    QElapsedTimer elapsedTimer;
    QVector<QPixmap> flags;
    int timeOffset;

    void loadFlags(QVector<QString> flagNames);
};

#endif // FLAGSTRIP_H
