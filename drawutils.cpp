/**
 * spritecanvas.h made by NajMingle for A7: Sprite Editor Implementation - CS 3505 Spring 2023
 * Model for tools and drawing on images
 * Reviewed by: Najman Husaini
 */
#include "drawutils.h"
#include <algorithm>
#include <QRandomGenerator>
#include <cmath>
#include <QPainter>
#include <QSet>
#include <QQueue>

/**
 * @brief DrawUtils::DrawUtils Constructs a default toolset
 */
DrawUtils::DrawUtils() :
    brushPen(QPen(Qt::black, 10, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)),
    selectedToolType(ToolType::BRUSH)
{
}

/**
 * @brief DrawUtils::setColor Sets the color of the selected tool.
 * @param colorThe color to be set to the tool.
 */
void DrawUtils::setColor(QColor color){
    brushPen.setColor(color);
}

/**
 * @brief DrawUtils::setBrushSize Sets the size of the brush.
 * @param size The size to be set to the tool.
 */
void DrawUtils::setBrushSize(int size){
    brushPen.setWidth(size);
}

/**
 * @brief DrawUtils::setSelectedToolType Sets the tool type
 * @param type The type that the tool will be set to
 */
void DrawUtils::setSelectedToolType(ToolType type){
    selectedToolType = type;
    emit toolUpdated();
}

/**
 * @brief isValid Used for the fill tool, determinines whether or not a point will be filled.
 * @param visited A QSet of QPoints that have been checked for fill eligibility
 * @param point The point that is being checked for fill eligibility
 * @param image The QImage of the current frame
 * @param originalColor The color that the fill tool will replace
 * @return True iff the point can be filled
 */
bool isValid(QSet<QPoint>& visited, QPoint &point, QImage& image, QColor originalColor) {
    QColor currentColor = image.pixelColor(point);
    return !visited.contains(point) && currentColor == originalColor;
}

/**
 * @brief DrawUtils::fillImageAtPosition Fills the given image at the given position
 * @param image The image to draw on
 * @param point The point to start filling in
 */
void DrawUtils::fillImageAtPosition(QImage& image, QPoint point){
    QColor fillColor = brushPen.color();
    QColor originalColor = image.pixelColor(point);

    // Queue of points to be filled.
    QQueue<QPoint> fillQueue;

    // Queue of visited points.
    QSet<QPoint> visited;

    fillQueue.enqueue(point);
    visited.insert(point);

    while (!fillQueue.empty()) {
        QPoint currentPoint = fillQueue.dequeue();

        image.setPixelColor(currentPoint, fillColor);
        QPoint tmpPoint = currentPoint;
        tmpPoint.rx() -= 1;

        // The following if statements ensure the point is within the canvas boundary.
        // They also determine whether a point will be filled or not and update the queues accordingly.
        if (tmpPoint.x() >= 0 && isValid(visited, tmpPoint, image, originalColor)) {
            fillQueue.enqueue(tmpPoint);
            visited.insert(tmpPoint);
        }
        tmpPoint = currentPoint;
        tmpPoint.rx() += 1;
        if (tmpPoint.x() < image.width() && isValid(visited, tmpPoint, image, originalColor)) {
            fillQueue.enqueue(tmpPoint);
            visited.insert(tmpPoint);
        }
        tmpPoint = currentPoint;
        tmpPoint.ry() += 1;
        if (tmpPoint.y() < image.height() && isValid(visited, tmpPoint, image, originalColor)) {
            fillQueue.enqueue(tmpPoint);
            visited.insert(tmpPoint);
        }
        tmpPoint = currentPoint;
        tmpPoint.ry() -= 1;
        if (tmpPoint.y() >= 0 && isValid(visited, tmpPoint, image, originalColor)) {
            fillQueue.enqueue(tmpPoint);
            visited.insert(tmpPoint);
        }
    }
}

/**
 * @brief DrawUtils::getSelectedToolType Gets the selected tool type.
 * @return The selected tool type.
 */
ToolType DrawUtils::getSelectedToolType() {
    return selectedToolType;
}

/**
 * @brief DrawUtils::drawPointOnImage Draws on a single point using the current tool.
 * @param image The image to draw on
 * @param point The point to draw at
 */
void DrawUtils::drawPointOnImage(QImage& image, QPoint point) {
    QPen pen;
    QPainter painter(&image);

    // The following if statements determine the logic to be used depending on the selected tool.
    if(selectedToolType == ERASER){
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        pen = brushPen;
        pen.setColor(QColor(0, 0, 0, 0));
    } else if(selectedToolType == FILL) {
        fillImageAtPosition(image, point);
        return;
    } else {
        pen = brushPen;
    }
    painter.setPen(pen);
    painter.drawPoint(point);
}

/**
 * @brief DrawUtils::drawLineOnImage Draws along a line using the current tool.
 * @param image The image to draw on
 * @param from The starting point of the line
 * @param to The ending point of the line
 */
void DrawUtils::drawLineOnImage(QImage& image, QPoint from, QPoint to) {
    QPen pen;
    QPainter painter(&image);

    // The following if statements determine the logic to be used depending on the selected tool.
    if(selectedToolType == ERASER){
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        pen = brushPen;
        pen.setColor(QColor(0, 0, 0, 0));
    } else if(selectedToolType == FILL) {
        // Do nothing
        return;
    } else {
        pen = brushPen;
    }
    painter.setPen(pen);
    painter.drawLine(from, to);
}

QColor DrawUtils::getColor() {
    return brushPen.color();
}
