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
    explicit FillableFlag(QVector<QImage> layers, QWidget *parent = nullptr);
    ~FillableFlag();

public slots:
    void fillAtPoint(QPoint point, QColor color);

private:
    Ui::FillableFlag *ui;
    QVector<QImage> layers;
    QVector<QColor> layerColors;

    void paintEvent(QPaintEvent *event) override;
};

#endif // FILLABLEFLAG_H
