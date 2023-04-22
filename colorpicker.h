#ifndef COLORPICKER_H
#define COLORPICKER_H
#include <QColor>
#include <QWidget>

namespace Ui {
class ColorPicker;
}

class ColorPicker : public QWidget
{
    Q_OBJECT

public:
    explicit ColorPicker(QWidget *parent = nullptr);
    ~ColorPicker();

private slots:
    void UpdateColor();
    void OnColorButtonClicked();

signals:
    void ColorPicked(QColor &color);

private:
    Ui::ColorPicker *ui;
    QColor SelectedColor;
};

#endif // COLORPICKER_H
