/**
 * spritecanvas.h made by NajMingle for A7: Sprite Editor Implementation - CS 3505 Spring 2023
 * Repurposed for A8 as drawutils.h, used with drawutils.cpp
 *
 * Model for tools and drawing on images
 * Reviewed by: Najman Husaini
 */
#ifndef DRAWUTILS_H
#define DRAWUTILS_H
#include "qobject.h"
#include <QColor>
#include <QBrush>
#include <QPen>

/**
 * @brief Represents all 4 tool types
 */
enum ToolType{
    BRUSH,
    FILL,
    ERASER
};

/**
 * @brief The Tool model
 */
class DrawUtils: public QObject
{
    Q_OBJECT
public:
    DrawUtils();

    void setColor(QColor color);
    QColor getColor();
    void setBrushSize(int size);
    void setSelectedToolType(ToolType type);

    void drawPointOnImage(QImage& image, QPoint point);
    void drawLineOnImage(QImage& image, QPoint from, QPoint to);

    ToolType getSelectedToolType();

signals:
    void toolUpdated();

private:
    QPen brushPen;
    ToolType selectedToolType;

    void fillImageAtPosition(QImage& image, QPoint point);
};

#endif // DRAWUTILS_H
