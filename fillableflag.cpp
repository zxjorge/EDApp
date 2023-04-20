#include "fillableflag.h"
#include "ui_fillableflag.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRandomGenerator>

FillableFlag::FillableFlag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FillableFlag),
    currentColor(Qt::white)
{
    ui->setupUi(this);
}

FillableFlag::~FillableFlag()
{
    delete ui;
}

void FillableFlag::fillAtPoint(QPoint point) {
    for (int i = layers.length() - 1; i > 0; i--) {
        if (layers.at(i).pixelColor(point).alpha() > 0) {
            layerColors.replace(i, currentColor);
            if (getColorCount() <= MAX_COLOR_COUNT) {
                emit correctColorCount();
            } else {
                emit incorrectColorCount();
            }
            update();
            return;
        }
    }
    layerColors.replace(0, currentColor);

    if (getColorCount() <= MAX_COLOR_COUNT) {
        emit correctColorCount();
    } else {
        emit incorrectColorCount();
    }

    update();
}

void FillableFlag::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    for (int i = 0; i < layers.length(); i++) {
        QImage img = layers.at(i).scaledToWidth(width());
        QPainter layerPainter(&img);
        layerPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);

        QColor color = layerColors.at(i);
        layerPainter.setBrush(color);
        layerPainter.setPen(color);

        layerPainter.drawRect(img.rect());
        painter.drawImage(0, 0, img);
    }
}

QPoint FillableFlag::getScaledMousePoint(QMouseEvent* event) {
    QPointF point = event->position();
    point.rx() = point.x();
    point.ry() = point.y();
    point /= (float)width() / layers.at(0).width();

    // 0.5 offset to pixel centers instead of corners
    point.rx() = point.x() - 0.5;
    point.ry() = point.y() - 0.5;
    return point.toPoint();
}

/**
 * @brief SpriteCanvas::mousePressEvent this method is responsible for handling what happens when something is drawn on the spriteCanvas.
 * It updates the canvas based on the current drawing tool and the position of the mouse cursor.
 * @param event this QMouseEvent is used to check if the left button of the mouse is being clicked or not and to get the position.
 */
void FillableFlag::mousePressEvent(QMouseEvent *event)
{
    fillAtPoint(getScaledMousePoint(event));
    update();
}

QColor FillableFlag::getCurrentColor() {
    return currentColor;
}

void FillableFlag::setCurrentColor(QColor color) {
    currentColor = color;
}

int FillableFlag::getColorCount() {
    QSet<QRgb> uniqueColors;

    for (QColor &color : layerColors) {
        uniqueColors.insert(color.rgb());
    }

    return uniqueColors.count();
}

void FillableFlag::addLayer(QImage img, QColor color) {
    layers.push_back(img);
    layerColors.push_back(color);
}
