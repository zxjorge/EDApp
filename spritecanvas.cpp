/**
 * spritecanvas.cpp made by Najmingle for A7: Sprite Editor Implementation - CS 3505 Spring 2023
 * This cpp file uses spritecanvas.h header file and implements all its methods.
 * Reviewed by: Arkein Singh
 */
#include "spritecanvas.h"
#include "ui_spritecanvas.h"
#include <iostream>
#include <cmath>
#include <QPainter>

SpriteCanvas::SpriteCanvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpriteCanvas),
    sprite(QImage(1000, 500, QImage::Format_RGB32)),
    drawUtils(nullptr)
{
    sprite.fill(Qt::white);
    ui->setupUi(this);
}

SpriteCanvas::~SpriteCanvas()
{
    delete ui;
}

void SpriteCanvas::setDrawUtils(DrawUtils* drawUtils) {
    this->drawUtils = drawUtils;
    onToolChanged();
    connect(drawUtils,
        &DrawUtils::toolUpdated,
        this,
        &SpriteCanvas::onToolChanged);
}

void SpriteCanvas::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    float scale;
    if (getDimensionLimit() == DimensionLimit::WIDTH) {
        scale = (float)width() / sprite.width();
        canvasOffsetX = 0;
        canvasOffsetY = (height() - sprite.height() * scale) / 2;
    } else {
        scale = (float)height() / sprite.height();
        canvasOffsetX = (width() - sprite.width() * scale) / 2;
        canvasOffsetY = 0;
    }

    painter.drawImage(
        canvasOffsetX,
        canvasOffsetY,
        sprite.scaled(
            sprite.width() * scale,
            sprite.height() * scale,
            Qt::IgnoreAspectRatio,
            Qt::FastTransformation
        )
    );
}

DimensionLimit SpriteCanvas::getDimensionLimit() {
    if ((float)width() / height() < (float)sprite.width() / sprite.height()) {
        return DimensionLimit::WIDTH;
    } else {
        return DimensionLimit::HEIGHT;
    }
}

float SpriteCanvas::getPixelSize() {
    if (getDimensionLimit() == DimensionLimit::WIDTH) {
        return (float)width() / sprite.width();
    } else {
        return (float)height() / sprite.height();
    }
}

QPoint SpriteCanvas::getScaledMousePoint(QMouseEvent* event) {
    QPointF point = event->position();
    point.rx() = point.x() - canvasOffsetX;
    point.ry() = point.y() - canvasOffsetY;
    point /= getPixelSize();

    // 0.5 offset to pixel centers instead of corners
    point.rx() = point.x() - 0.5;
    point.ry() = point.y() - 0.5;
    return point.toPoint();
}

void SpriteCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) {
        return;
    }

    QPoint pos = getScaledMousePoint(event);
    drawUtils->drawPointOnImage(sprite, pos);
    lastMousePos = pos;
    update();
}

void SpriteCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() != Qt::LeftButton) {
        return;
    }

    QPoint pos = getScaledMousePoint(event);
    drawUtils->drawLineOnImage(sprite, lastMousePos, pos);
    lastMousePos = pos;
    update();
}
void SpriteCanvas::onToolChanged() {
    QCursor brushCursor;

    switch (drawUtils->getSelectedToolType()) {
        case ToolType::BRUSH: {
            QPixmap brushPixmap(":/Icons/brush_icon.png");
            QPixmap scaledBrushPixmap = brushPixmap.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            brushCursor = QCursor(scaledBrushPixmap, scaledBrushPixmap.width() / 8, scaledBrushPixmap.height()/1.1);
            break;
        }
        case ToolType::FILL: {
            QPixmap brushPixmap(":/Icons/filltool_icon.png");
            QPixmap scaledBrushPixmap = brushPixmap.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            brushCursor = QCursor(scaledBrushPixmap, scaledBrushPixmap.width()/8, scaledBrushPixmap.height()/1.1);
            break;
        }
        case ToolType::ERASER: {
            QPixmap brushPixmap(":/Icons/erase_icon.png");
            QPixmap scaledBrushPixmap = brushPixmap.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            brushCursor = QCursor(scaledBrushPixmap, scaledBrushPixmap.width() / 6, scaledBrushPixmap.height() / 1.2);
            break;
        }
    }
    setCursor(brushCursor);
}

void SpriteCanvas::saveFlag(QString filename) {
    if (!filename.endsWith(".png")) {
        filename += ".png";
    }
    if (!sprite.save(filename)) {
        qDebug() << "Unable to save to " << filename << Qt::endl;
    }
}

void SpriteCanvas::setImage(QImage image) {
    sprite = image;
}
