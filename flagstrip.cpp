#include "flagstrip.h"
#include "qrandom.h"
#include "ui_flagstrip.h"
#include <QPainter>
#include "flagConstants.h"

const int SPEED = 50;
const int FLAG_WIDTH = 1000;
const double SCALE = 0.15;
const int FLAG_SPACING = 50;

FlagStrip::FlagStrip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlagStrip)
{
    ui->setupUi(this);
    elapsedTimer.start();
    loadFlags(CHRISTIANITY_FLAGS);
    loadFlags(SIMPLE_FLAGS);
    loadFlags(MEANINGFUL_FLAGS);

    QRandomGenerator rng = QRandomGenerator::securelySeeded();
    for (int i = 0; i < flags.length(); i++) {
        flags.swapItemsAt(rng.bounded(flags.length()), rng.bounded(flags.length()));
    }
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
        painter.drawPixmap(leftmostX + i * flagWidthSpaced, 0, flags.at(flagIndex));
    }
}

void FlagStrip::loadFlags(QVector<QString> flagNames) {
    for (QString &flagName : flagNames) {
        flags.append(QPixmap(":/Flags/" + flagName).scaledToWidth(FLAG_WIDTH * SCALE));
    }
}

void FlagStrip::setTimeOffset(int timeOffset) {
    this->timeOffset = timeOffset;
}
