/**
 * BeDistinctiveOrRelatedLesson.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by colorpicker.cpp and has methods, signals, and slots to handle the users ability to
 * interact with the color picker when doing an activity.
 * Reviewed by: Sahil Karki
 */
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
