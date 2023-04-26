/**
 * FlagStrip.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses FlagStrip.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "flagstrip.h"
#include "qrandom.h"
#include "ui_flagstrip.h"
#include <QPainter>

FlagStrip::FlagStrip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlagStrip)
{
    ui->setupUi(this);
    elapsedTimer.start();
}

FlagStrip::~FlagStrip()
{
    delete ui;
}

void FlagStrip::paintEvent(QPaintEvent*) {
    int flagWidth = FLAG_WIDTH * SCALE;
    int flagWidthSpaced = flagWidth + FLAG_SPACING;
    int flagCount = std::ceil((double)width() / flagWidthSpaced) + 2;

    double elapsed = (elapsedTimer.elapsed() + timeOffset) / 1000.0;
    int horizontalDistance = SPEED * elapsed;
    int elapsedFlags = horizontalDistance / flagWidthSpaced;

    int offset = horizontalDistance % flagWidthSpaced;

    int leftmostX = offset - flagWidthSpaced;

    QPainter painter(this);
    for (int i = 0; i < flagCount; i++) {
        int flagIndex = i - elapsedFlags;
        if (flagIndex < 0) {
            flagIndex = flags.length() - flagIndex;
        }
        flagIndex %= flags.length();
        const QPixmap &flag = flags.at(flagIndex);
        int y = (height() - flag.height()) / 2;
        painter.drawPixmap(leftmostX + i * flagWidthSpaced, y, flag);
    }
}

void FlagStrip::setTimeOffset(int timeOffset) {
    this->timeOffset = timeOffset;
}

void FlagStrip::setFlags(QVector<QPixmap> flags) {
    this->flags = flags;

    QRandomGenerator* rng = QRandomGenerator::global();
    for (int i = 0; i < flags.length(); i++) {
        flags.swapItemsAt(rng->bounded(flags.length()), rng->bounded(flags.length()));
    }
}
