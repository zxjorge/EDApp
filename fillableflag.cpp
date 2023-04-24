#include "fillableflag.h"
#include "ui_fillableflag.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRandomGenerator>

const int MAX_COLOR_COUNT = 3;
const int MAX_ACTION_HISTORY = 10;

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
    if (actions.length() >= MAX_ACTION_HISTORY) {
        actions.pop_front();
    }
    undoneActions.clear();

    for (int i = layers.length() - 1; i > 0; i--) {
        if (layers.at(i).pixelColor(point).alpha() > 0) {
            actions.append(Action(layerColors[i], i));
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

    actions.append(Action(layerColors[0], 0));
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

void FillableFlag::addLayer(QImage img, QColor color, bool untrack) {
    layers.push_back(img);
    layerColors.push_back(color);

    if (untrack) {
        return;
    }

    undoneActions.clear();

    if (actions.length() >= MAX_ACTION_HISTORY) {
        actions.pop_front();
    }

    actions.append(Action());
}

void FillableFlag::undo() {
    if (actions.empty()) {
        return;
    }

    Action action = actions.back();
    actions.pop_back();

    if (action.actionType == ActionType::ADD_LAYER) {
        undoneActions.append(UndoneAction(layerColors.back(), layers.back()));
        layers.pop_back();
        layerColors.pop_back();
    } else {
        undoneActions.append(UndoneAction(layerColors[action.layerIndex], action.layerIndex));
        layerColors[action.layerIndex] = action.oldColor;
    }

    update();
}

void FillableFlag::redo() {
    if (undoneActions.empty()) {
        return;
    }

    UndoneAction action = undoneActions.back();
    undoneActions.pop_back();

    if (action.actionType == ActionType::ADD_LAYER) {
        actions.append(Action());
        layers.append(action.oldLayer);
        layerColors.append(action.oldColor);
    } else {
        actions.append(Action(layerColors[action.layerIndex], action.layerIndex));
        layerColors[action.layerIndex] = action.oldColor;
    }
    update();
}
