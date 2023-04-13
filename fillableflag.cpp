#include "fillableflag.h"
#include "ui_fillableflag.h"
#include <QPainter>

FillableFlag::FillableFlag(QVector<QImage> layers, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FillableFlag),
    layers(layers),
    layerColors(QVector<QColor>(layers.length()))
{
    for (QColor &col : layerColors) {
        col = Qt::white;
    }
    ui->setupUi(this);
}

FillableFlag::~FillableFlag()
{
    delete ui;
}

void FillableFlag::fillAtPoint(QPoint point, QColor color) {
    for (int i = layers.length() - 1; i > 0; i--) {
        if (layers.at(i).pixelColor(point).alpha() > 0) {
            layerColors.replace(i, color);
            update();
            return;
        }
    }
    layerColors.replace(0, color);
    update();
}

void FillableFlag::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    for (int i = 0; i < layers.length(); i++) {
        QBrush brush = painter.brush();
        brush.setColor(layerColors.at(i));
        painter.setBrush(brush);
        painter.drawImage(0, 0, layers.at(i));
    }
}
