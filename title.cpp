/**
 * Title.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses Title.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "title.h"
#include "mainmenu.h"
#include "qdiriterator.h"
#include "saves.h"
#include "ui_title.h"
#include <QPushButton>
#include "definition.h"
#include <QPixmap>
#include <QTimer>


Title::Title(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Title),
    mainWindow(parent)
{
    ui->setupUi(this);
    connect(&updateTimer,
            &QTimer::timeout,
            this,
            [this] {
                update();
            });
    updateTimer.setTimerType(Qt::PreciseTimer);
    updateTimer.start(16);

    if (parent->getSaves()->getNumberOfLessonsSaved() > 0) {
        ui->pushButton->setText("Let's go already!");
    }

    connect(ui->pushButton,
            &QPushButton::pressed,
            this,
            &Title::onButtonpressed);

    ui->flagStrip2->setTimeOffset(500);

    QVector<QPixmap> flags;
    QDirIterator it(":/Flags/");
    while (it.hasNext()) {
        QString flagName = it.next();
        // Skip nationalFlags.jpg
        if (flagName.contains("national")) {
            continue;
        }
        flags.append(QPixmap(flagName).scaledToWidth(FLAG_WIDTH * SCALE, Qt::SmoothTransformation));
    }

    ui->flagStrip1->setFlags(flags);
    ui->flagStrip2->setFlags(flags);
}

void Title::onButtonpressed() {
    if (mainWindow->getSaves()->getNumberOfLessonsSaved() > 0) {
        mainWindow->switchScene(new MainMenu(mainWindow));
    } else {
        mainWindow->switchScene(new Definition(mainWindow));
    }
}

Title::~Title()
{
    delete ui;
}
