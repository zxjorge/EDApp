/**
 * FlagStrip.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by FlagStrip.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the flag animation that appears on the title screen.
 * Reviewed by: Najman Husaini
 */
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

    /**
     * @brief setTimeOffset set the timer offset
     * @param offset This is the offset time
     */
    void setTimeOffset(int offset);

    /**
     * @brief setFlags sets the flags to be displayed on the strip
     * @param flags These are the flags to be displayed
     */
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
