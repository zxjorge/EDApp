#ifndef FLAGWIDGET_H
#define FLAGWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include "Box2D/Box2D.h"

class FlagWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FlagWidget(QWidget *parent = nullptr);
    void setFlagImage(const QPixmap &pixmap);
    void animateFlag();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap m_flagPixmap;
    b2World* m_world;
    b2Body* m_flagBody;
    QTimer m_timer;
};

#endif // FLAGWIDGET_H
