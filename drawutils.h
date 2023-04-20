/**
 * spritecanvas.h made by NajMingle for A7: Sprite Editor Implementation - CS 3505 Spring 2023
 * Model for tools and drawing on images
 * Reviewed by: Najman Husaini
 */
#ifndef DRAWUTILS_H
#define DRAWUTILS_H
#include <QColor>
#include <QBrush>
#include <QPen>

/// Represents all 4 tool types
enum ToolType{
    BRUSH,
    FILL,
    ERASER
};

/**
 * @brief The Tool model
 */
class DrawUtils
{
public:
    DrawUtils();

    void setColor(QColor color);
    void setBrushSize(int size);
    void setSelectedToolType(ToolType type);

    void drawPointOnImage(QImage& image, QPoint point);
    void drawLineOnImage(QImage& image, QPoint from, QPoint to);

    ToolType getSelectedToolType();

private:
    QPen brushPen;
    ToolType selectedToolType;

    void fillImageAtPosition(QImage& image, QPoint point);
};

#endif // DRAWUTILS_H
