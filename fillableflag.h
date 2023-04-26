/**
 * fillableflag.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by fillableflag.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the Flag Coloring Puzzle, and Keep Simple Activity
 * Reviewed by: George Benyeogor
 */
#ifndef FILLABLEFLAG_H
#define FILLABLEFLAG_H

#include <QWidget>

/**
 * @brief Represents the type of action the user did
 */
enum ActionType { ADD_LAYER, FILL_LAYER };

/**
 * @brief Encodes the specific action the user did
 */
class Action {
public:
    Action() {
        this->actionType = ActionType::ADD_LAYER;
    }
    Action(QColor oldColor, int layerIndex) {
        this->actionType = ActionType::FILL_LAYER;
        this->oldColor = oldColor;
        this->layerIndex = layerIndex;
    }

    ActionType actionType;

    QColor oldColor;
    int layerIndex;
};

/**
 * @brief Encodes an action that we have undone
 */
class UndoneAction {
public:
    UndoneAction(QColor oldColor, QImage oldLayer) {
        this->actionType = ActionType::ADD_LAYER;
        this->oldColor = oldColor;
        this->oldLayer = oldLayer;
    }
    UndoneAction(QColor oldColor, int layerIndex) {
        this->actionType = ActionType::FILL_LAYER;
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
    /**
     * @brief addLayer Adds a new layer to the flag
     * @param img The layer to add
     * @param color The color of the layer
     */
    void addLayer(QImage img, QColor color = Qt::black, bool untrack = false);

signals:
    /**
     * @brief correctColorCount Emitted when the right number of colors has been used (for the colors lesson)
     */
    void correctColorCount();
    /**
     * @brief incorrectColorCount Emitted when the wrong number of colors has been used (for the colors lesson)
     */
    void incorrectColorCount();

public slots:
    /**
     * @brief fillAtPoint Fills the image at the given point with the current color
     */
    void fillAtPoint(QPoint point);
    /**
     * @brief undo Reverts an action
     */
    void undo();
    /**
     * @brief redo Re-applies an undone action
     */
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
    /**
     * @brief getScaledMousePoint Returns the mouse coordinates relative to the widget
     */
    QPoint getScaledMousePoint(QMouseEvent* event);
    /**
     * @brief getColorCount Get the number of distinct colors in use
     */
    int getColorCount();
};

#endif // FILLABLEFLAG_H
