#ifndef FLAGSTRIP_H
#define FLAGSTRIP_H

#include <QWidget>
#include <QElapsedTimer>

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
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::FlagStrip *ui;
    QElapsedTimer elapsedTimer;
    QVector<QPixmap> flags;
    int timeOffset;

    void loadFlags(QVector<QString> flagNames);
};

#endif // FLAGSTRIP_H
