#ifndef FILLABLEFLAG_H
#define FILLABLEFLAG_H

#include <QWidget>

const int MAX_COLOR_COUNT = 3;

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
    void addLayer(QImage img, QColor color);

signals:
    void correctColorCount();
    void incorrectColorCount();

public slots:
    void fillAtPoint(QPoint point);

private:
    Ui::FillableFlag *ui;
    QVector<QImage> layers;
    QVector<QColor> layerColors;
    QColor currentColor;

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    QPoint getScaledMousePoint(QMouseEvent* event);
    int getColorCount();
};

#endif // FILLABLEFLAG_H
