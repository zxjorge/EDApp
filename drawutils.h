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
    /**
     * @brief DrawUtils::DrawUtils Constructs a default toolset
     */
    DrawUtils();

    /**
     * @brief DrawUtils::setColor Sets the color of the selected tool.
     * @param colorThe color to be set to the tool.
     */
    void setColor(QColor color);

    /**
     * @brief DrawUtils::getColor gets the color of the brush
     * @return Qcolor the color of the brush
     */
    QColor getColor();

    /**
     * @brief DrawUtils::setBrushSize Sets the size of the brush.
     * @param size The size to be set to the tool.
     */
    void setBrushSize(int size);

    /**
     * @brief DrawUtils::setSelectedToolType Sets the tool type
     * @param type The type that the tool will be set to
     */
    void setSelectedToolType(ToolType type);

    /**
     * @brief DrawUtils::drawPointOnImage Draws on a single point using the current tool.
     * @param image The image to draw on
     * @param point The point to draw at
     */
    void drawPointOnImage(QImage& image, QPoint point);

    /**
     * @brief DrawUtils::drawLineOnImage Draws along a line using the current tool.
     * @param image The image to draw on
     * @param from The starting point of the line
     * @param to The ending point of the line
     */
    void drawLineOnImage(QImage& image, QPoint from, QPoint to);

    /**
     * @brief DrawUtils::getSelectedToolType Gets the selected tool type.
     * @return The selected tool type.
     */
    ToolType getSelectedToolType();

signals:
    /**
     * @brief toolUpdated signal to declare that the tool have updated
     */
    void toolUpdated();

private:
    QPen brushPen;
    ToolType selectedToolType;

    /**
     * @brief DrawUtils::fillImageAtPosition Fills the given image at the given position
     * @param image The image to draw on
     * @param point The point to start filling in
     */
    void fillImageAtPosition(QImage& image, QPoint point);
};

#endif // DRAWUTILS_H
