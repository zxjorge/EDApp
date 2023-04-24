#ifndef FILLABLEFLAG_H
#define FILLABLEFLAG_H

#include <QWidget>

enum ActionType { ADD_LAYER, FILL };

class Action {
public:
    Action() {
        this->actionType = ActionType::ADD_LAYER;
    }
    Action(QColor oldColor, int layerIndex) {
        this->actionType = ActionType::FILL;
        this->oldColor = oldColor;
        this->layerIndex = layerIndex;
    }

    ActionType actionType;

    QColor oldColor;
    int layerIndex;
};

class UndoneAction {
public:
    UndoneAction(QColor oldColor, QImage oldLayer) {
        this->actionType = ActionType::ADD_LAYER;
        this->oldColor = oldColor;
        this->oldLayer = oldLayer;
    }
    UndoneAction(QColor oldColor, int layerIndex) {
        this->actionType = ActionType::FILL;
        this->oldColor = oldColor;
        this->layerIndex = layerIndex;
    }

    ActionType actionType;

    QColor oldColor;
    int layerIndex;

    QImage oldLayer;
};

namespace Ui {
class FillableFlag;
}

class FillableFlag : public QWidget
{
    Q_OBJECT

public:
    explicit FillableFlag(QWidget *parent = nullptr);
    ~FillableFlag();

    void setCurrentColor(QColor color);
    QColor getCurrentColor();
    void addLayer(QImage img, QColor color = Qt::black);

signals:
    void correctColorCount();
    void incorrectColorCount();

public slots:
    void fillAtPoint(QPoint point);
    void undo();
    void redo();

private:
    Ui::FillableFlag *ui;
    QVector<QImage> layers;
    QVector<QColor> layerColors;
    QColor currentColor;
    QVector<Action> actions;
    QVector<UndoneAction> undoneActions;

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    QPoint getScaledMousePoint(QMouseEvent* event);
    int getColorCount();
};

#endif // FILLABLEFLAG_H
