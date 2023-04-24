/**
 * Title.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses Title.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "title.h"
#include "mainmenu.h"
#include "qpainter.h"
#include "qrandom.h"
#include "saves.h"
#include "ui_title.h"
#include "flagConstants.h"
#include <QPushButton>
#include "definition.h"
#include <QPixmap>
#include<QTimer>


Title::Title(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Title),
    mainWindow(parent)
{
    ui->setupUi(this);
    QRandomGenerator rng = QRandomGenerator::securelySeeded();
    QImage flagToAdd;

    for(int i = 0; i < numOfFlags; i++){
        int listPicker = rng.bounded(9);

        if(listPicker == 0)
            flagToAdd.load(":/Flags/" + BASIC_COLOR_FLAGS.at(rng.bounded(BASIC_COLOR_FLAGS.size())));
        else if(listPicker == 1)
            flagToAdd.load(":/Flags/" + SIMPLE_FLAGS.at(rng.bounded(SIMPLE_FLAGS.size())));
        else if(listPicker == 2)
            flagToAdd.load(":/Flags/" + MEANINGFUL_FLAGS.at(rng.bounded(MEANINGFUL_FLAGS.size())));
        else if(listPicker == 3)
            flagToAdd.load(":/Flags/" + NO_LETTER_OR_SEAL_FLAGS.at(rng.bounded(NO_LETTER_OR_SEAL_FLAGS.size())));
        else if (listPicker == 4)
            flagToAdd.load(":/Flags/" + LETTERED_FLAGS.at(rng.bounded(LETTERED_FLAGS.size())));
        else if(listPicker == 5)
            flagToAdd.load(":/Flags/" + COMPLEX_COLOR_FLAGS.at(rng.bounded(COMPLEX_COLOR_FLAGS.size())));
        else if(listPicker == 6)
            flagToAdd.load(":/Flags/" + ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size())));
        else if(listPicker == 7)
            flagToAdd.load(":/Flags/" + CHRISTIANITY_FLAGS.at(rng.bounded(CHRISTIANITY_FLAGS.size())));
        else if(listPicker == 8)
            flagToAdd.load(":/Flags/" + UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size())));
        // Skip if null
        if(flagToAdd.isNull()) {
            i--;
            continue;
        }

        QImage flagScaled = flagToAdd.scaled(flagWidth, flagHeight, Qt::IgnoreAspectRatio);
        flagsToDraw.append(flagScaled);
        oldFlagsToDraw.append(flagScaled);
        flagsX.append(i * flagSpacing);
        flagsResX.append(-flagWidth);
    }
    startTimer(10);
    connect(ui->pushButton,
            &QPushButton::pressed,
            this,
            &Title::onButtonpressed);


}

void Title::paintEvent(QPaintEvent*){
    QPainter painter(this);

    QImage flagScaled;
    QImage flag;
    QRandomGenerator rng = QRandomGenerator::securelySeeded();
    flagY = this->height() / 2;
    for(int i = 0; i < numOfFlags; i++){
        flagsX[i] = flagsX[i] + sliderSpeed;
        if(flagsX[i] >= this->width() - flagWidth && flagsResX.at(i) != 0){
                if(flagsResX.at(i) == -flagWidth){

                    int listPicker = rng.bounded(9);

                    if(listPicker == 0)
                        flag.load(":/Flags/" + FLAGCONSTANTS_H::BASIC_COLOR_FLAGS.at(rng.bounded(BASIC_COLOR_FLAGS.size())));
                    else if(listPicker == 1)
                        flag.load(":/Flags/" + FLAGCONSTANTS_H::SIMPLE_FLAGS.at(rng.bounded(SIMPLE_FLAGS.size())));
                    else if(listPicker == 2)
                        flag.load(":/Flags/" + FLAGCONSTANTS_H::MEANINGFUL_FLAGS.at(rng.bounded(MEANINGFUL_FLAGS.size())));
                    else if(listPicker == 3)
                        flag.load(":/Flags/" + FLAGCONSTANTS_H::NO_LETTER_OR_SEAL_FLAGS.at(rng.bounded(NO_LETTER_OR_SEAL_FLAGS.size())));
                    else if (listPicker == 4)
                        flag.load(":/Flags/" + LETTERED_FLAGS.at(rng.bounded(LETTERED_FLAGS.size())));
                    else if(listPicker == 5)
                        flag.load(":/Flags/" + COMPLEX_COLOR_FLAGS.at(rng.bounded(COMPLEX_COLOR_FLAGS.size())));
                    else if(listPicker == 6)
                        flag.load(":/Flags/" + ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size())));
                    else if(listPicker == 7)
                        flag.load(":/Flags/" + CHRISTIANITY_FLAGS.at(rng.bounded(CHRISTIANITY_FLAGS.size())));
                    else if(listPicker == 8)
                        flag.load(":/Flags/" + UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size())));


                    if(!flag.isNull()){
                        flagScaled = flag.scaled(flagWidth, flagHeight);
                        oldFlagsToDraw[i] = flagsToDraw[i];
                        flagsToDraw[i] = flagScaled;
                    }

                }
                painter.drawImage(flagsResX[i], flagY, flagsToDraw[i]);
                painter.drawImage(flagsX[i] , flagY, oldFlagsToDraw[i]);
                flagsResX[i]+=sliderSpeed;

        }
        else if(flagsResX[i] == 0){
            flagsResX[i] = -flagWidth;
            flagsX[i] = 0;
        }else{
            painter.drawImage(flagsX[i], flagY, flagsToDraw[i]);
        }
    }

}

void Title::onButtonpressed() {
    if (mainWindow->getSaves()->getNumberOfLessonsSaved() > 0) {
        mainWindow->switchScene(new MainMenu(mainWindow));
    } else {
        mainWindow->switchScene(new Definition(mainWindow));
    }
}

void Title::timerEvent(QTimerEvent*)
{
    update();
}

Title::~Title()
{
    delete ui;
}
