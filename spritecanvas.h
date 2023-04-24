/**
 * spritecanvas.h made by NajMingle for A7: Sprite Editor Implementation - CS 3505 Spring 2023
 * Repurposed for A8
 * This header file will be used by spritecanvas.cpp and has methods, signals, and slots to handle
 * the logic and data for the spritecanvas, which is where the user would draw on the sprite editor UI.
 * Reviewed by: Brayden Newsom
 */
#ifndef SPRITECANVAS_H
#define SPRITECANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include "drawutils.h"

/// Represents if the canvas is restricted by width or by height
enum DimensionLimit { WIDTH, HEIGHT };

namespace Ui {
class SpriteCanvas;
}

/**
 * @brief The SpriteCanvas widget on which drawing occurs
 */
class SpriteCanvas : public QWidget
{
    Q_OBJECT

public:
    explicit SpriteCanvas(QWidget *parent = nullptr);
    ~SpriteCanvas();
    void showEraseIcon();
    void showFillIcon();
    void showBrushIcon();
    void setDrawUtils(DrawUtils* drawUtils);

public slots:
    void onToolChanged();
    void saveFlag(QString filename);

private:
    Ui::SpriteCanvas *ui;

    QImage sprite;
    QPoint lastMousePos;
    DrawUtils* drawUtils;
    int canvasOffsetX;
    int canvasOffsetY;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    float getPixelSize();
    QPoint getScaledMousePoint(QMouseEvent *event);
    DimensionLimit getDimensionLimit();

};

#endif // SPRITECANVAS_H
