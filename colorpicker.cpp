#include "colorpicker.h"
#include "ui_colorpicker.h"
#include <QColor>

ColorPicker::ColorPicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorPicker)
{
    ui->setupUi(this);

    // Connect the slider value change events to the color selection slots
    connect(ui->redSlider, &QSlider::valueChanged, this, &ColorPicker::UpdateColor);
    connect(ui->greenSlider, &QSlider::valueChanged, this, &ColorPicker::UpdateColor);
    connect(ui->blueSlider, &QSlider::valueChanged, this, &ColorPicker::UpdateColor);
    connect(ui->brightnessSlider, &QSlider::valueChanged, this, &ColorPicker::UpdateColor);
    connect(ui->ColorButton, &QPushButton::clicked, this, &ColorPicker::OnColorButtonClicked);
    // Set the initial color
    UpdateColor();
}

/**
 * @brief ColorPicker::~ColorPicker
 */
ColorPicker::~ColorPicker()
{
    delete ui;
}

/**
 * @brief ColorPicker::UpdateColor
 */
void ColorPicker::UpdateColor(){
    // Retrieve the RGB values from the sliders
    int red = ui->redSlider->value();
    int green = ui->greenSlider->value();
    int blue = ui->blueSlider->value();
    int bright = ui->brightnessSlider->value();
    // Update the color label with the selected color
    QColor color = QColor::fromRgb(red, green, blue);
    color.setHsv(color.hue(), color.saturation(), bright);
    ui->ColorButton->setStyleSheet(QString("background-color: %1;").arg(color.name()));
    // Store the selected color
    SelectedColor = color;
}

/**
 * @brief ColorPicker::OnColorButtonClicked
 */
void ColorPicker::OnColorButtonClicked(){
    emit ColorPicked(SelectedColor);
}

