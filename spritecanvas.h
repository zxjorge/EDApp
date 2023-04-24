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
    /**
     * @brief SpriteCanvas::SpriteCanvas constructor for spriteCanvas
     * @param parent
     */
    explicit SpriteCanvas(QWidget *parent = nullptr);

    /**
     * @brief SpriteCanvas::~SpriteCanvas destructor for spriteCanvas.
     */
    ~SpriteCanvas();

    /**
     * @brief SpriteCanvas::setTool sets the drawing utility model to be used
     */
    void setDrawUtils(DrawUtils* drawUtils);

    /**
     * @brief SpriteCanvas::setImage sets the sprite to the passed in image.
     * @param image image that will be drawn
     */
    void setImage(QImage image);

public slots:
    /**
     * @brief SpriteCanvas::onToolChanged changes the cursors icon depending on what tool is selected
     */
    void onToolChanged();

    /**
     * @brief SpriteCanvas::saveFlag takes a filename and saves the according flag
     * @param filename filename of a flag
     */
    void saveFlag(QString filename);

private:
    Ui::SpriteCanvas *ui;

    QImage sprite;
    QPoint lastMousePos;
    DrawUtils* drawUtils;
    int canvasOffsetX;
    int canvasOffsetY;

    /**
     * @brief SpriteCanvas::mousePressEvent this method is responsible for handling what happens when something is drawn on the spriteCanvas
     * It updates the canvas based on the current drawing tool and the position of the mouse cursor
     * @param event this QMouseEvent is used to check if the left button of the mouse is being clicked or not and to get the position
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief SpriteCanvas::mouseReleaseEvent this method is responsible for handling what happens when the mouse button is released on the sprite canvas
     */
    void mouseReleaseEvent(QMouseEvent *event) override;

    /**
     * @brief SpriteCanvas::mouseMoveEvent this method is responsible for handling what happens when the mouse is moved on the sprite canvas while the left click is being
     * held down. It updates the canvas based on the current drawing tool and the position of the mouse cursor
     * @param event this QMouseEvent is used to check if the left button of the mouse is being clicked or not and to get the position
     */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * @brief SpriteCanvas::paintEvent
     */
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief SpriteCanvas::getPixelSize returns the pixel size of the sprite canvas
     * @return a float value which represents the pixel size
     */
    float getPixelSize();

    /**
     * @brief SpriteCanvas::getScaledMousePoint convert the position of the mouse to a QPoint object which is
     * scaled based on the size of the sprite canvas' pixel size
     * @param event this QMouseEvent is used to get the current position of the mouse
     * @return the scaled position of the mouse cursor as a QPoint
     */
    QPoint getScaledMousePoint(QMouseEvent *event);

    /**
     * @brief SpriteCanvas::getDimensionLimit gets the dimensions of the sprite canvas
     * @return the width and the height of the sprite canvas
     */
    DimensionLimit getDimensionLimit();

};

#endif // SPRITECANVAS_H
