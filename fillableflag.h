#ifndef FILLABLEFLAG_H
#define FILLABLEFLAG_H

#include <QWidget>

namespace Ui {
class FillableFlag;
}

class FillableFlag : public QWidget
{
    Q_OBJECT

public:
    explicit FillableFlag(QWidget *parent = nullptr);
    ~FillableFlag();

public slots:
    void fillAtPoint(QPoint point, QColor color);

private:
    Ui::FillableFlag *ui;
    QVector<QImage> layers;
    QVector<QColor> layerColors;

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    QPoint getScaledMousePoint(QMouseEvent* event);
};

#endif // FILLABLEFLAG_H
