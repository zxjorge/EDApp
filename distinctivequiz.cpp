#include "distinctivequiz.h"
#include "qrandom.h"
#include "ui_distinctivequiz.h"
#include "flagConstants.h"

DistinctiveQuiz::DistinctiveQuiz(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::DistinctiveQuiz)
{
    ui->setupUi(this);
  //  ui->flag1->setStyleSheet("border-image: url(:/Flags/gh.png)");


    ui->hint->setVisible(false);
    ui->selectChoice->setVisible(false);
    ui->colorCode->setText("Blue: Selected\nGreen: Correct Selection\nRed: Incorrect Selection\nYellow: Missed Correct Selection");

    updateStatLabels();

    ui->colorCode->setVisible(false);
  //  QSize size(ui->flag1->width(),ui->flag1->height());
  //  ui->flag1->setIconSize(size);
    flagButtons.append(ui->flag1);
    flagButtons.append(ui->flag2);
    flagButtons.append(ui->flag3);
    flagButtons.append(ui->flag4);

    for(int i = 0; i < flagButtons.size(); i++){
        flagSelected.append(false);
        flagCorrect.append(false);
    }

    setUpQuestion();


    connect(ui->flag1,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::flag1Clicked);

    connect(ui->flag2,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::flag2Clicked);

    connect(ui->flag3,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::flag3Clicked);

    connect(ui->flag4,
            &QPushButton::clicked,
            this,
            &DistinctiveQuiz::flag4Clicked);

}

DistinctiveQuiz::~DistinctiveQuiz()
{
    delete ui;
}

void DistinctiveQuiz::flag1Clicked(){
    changeButtonSelectColor(0);
}

void DistinctiveQuiz::flag2Clicked(){
    changeButtonSelectColor(1);
}

void DistinctiveQuiz::flag3Clicked(){
    changeButtonSelectColor(2);
}

void DistinctiveQuiz::flag4Clicked(){
    changeButtonSelectColor(3);
}

void DistinctiveQuiz::changeButtonSelectColor(int i){
    if(flagSelected.at(i) && answerStage){
        flagButtons.at(i)->setStyleSheet("background-color:light gray");
        flagSelected[i] = false;
    }
    else if(answerStage){
        flagButtons.at(i)->setStyleSheet("background-color:rgb(0,100,255)");
        flagSelected[i] = true;
    }
}

void DistinctiveQuiz::on_next_clicked()
{
    if(answerStage){
        if(!flagSelected.contains(true)){
            ui->selectChoice->setVisible(true);
        }else{
            for(int i = 0; i < flagButtons.size(); i++){
                if(flagSelected.at(i)){
                    if(flagCorrect.at(i)){
                        flagButtons.at(i)->setStyleSheet("background-color:rgb(0,255,0)");
                        correct += 1;
                    }
                    else{
                       flagButtons.at(i)->setStyleSheet("background-color:rgb(255,0,0)");
                       incorrect += 1;
                    }
                }
                else if(flagCorrect.at(i)){
                     flagButtons.at(i)->setStyleSheet("background-color:rgb(255,255,0)");
                     missedCorrect += 1;
                }
            }
            answerStage = false;
            ui->next->setText("Next Question");
            ui->selectChoice->setVisible(false);
            questions += 1;
            updateStatLabels();
        }
    }else if (!answerStage){
        setUpQuestion();
        ui->next->setText("Check Answers");
    }
}

void DistinctiveQuiz::setUpQuestion(){
    for(int i = 0; i < flagButtons.size(); i++){
        flagButtons.at(i)->setIcon(QIcon());
        flagButtons.at(i)->setStyleSheet("background-color:light gray");
        flagSelected[i] = false;
        flagCorrect[i] = false;
    }

    answerStage = true;
    ui->hint->setVisible(false);
    ui->hintButton->setText("Show Hint");

    QRandomGenerator rng = QRandomGenerator::securelySeeded();
   // int distinctiveOrRelated = rng.bounded(2);
    int symbolPicker = rng.bounded(3);
    QString display1 = "url(:/Flags/";
    QString display2 = "url(:/Flags/";
    if(symbolPicker == 0){
        display1 += CHRISTIANITY_FLAGS.at(rng.bounded(CHRISTIANITY_FLAGS.size()));
        display2 += CHRISTIANITY_FLAGS.at(rng.bounded(CHRISTIANITY_FLAGS.size()));

        while(display1 == display2) {
            display2 = "url(:/Flags/";
            display2 += CHRISTIANITY_FLAGS.at(rng.bounded(CHRISTIANITY_FLAGS.size()));
        }
        setUpButtons(CHRISTIANITY_FLAGS, display1,display2);
        ui->hint->setText("Choose flags that:\nContain Christian symbols");
    }
    else if(symbolPicker == 1){
        display1 += ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));
        display2 += ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));

        while(display1 == display2) {
            display2 = "url(:/Flags/";
            display2 += ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));
        }

        setUpButtons(ISLAM_FLAGS, display1,display2);
        ui->hint->setText("Choose flags that:\nContain Islamic symbols");
    }
    else{
        display1 += UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));
        display2 += UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));

        while(display1 == display2) {
            display2 = "url(:/Flags/";
            display2 += UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));
        }

        setUpButtons(UNION_JACK_FLAGS,display1,display2);
         ui->hint->setText("Choose flags that have a Union Jack");
    }

    display1+=")";
    display2+=")";
    ui->displayFlag1->setStyleSheet("border-image: " + display1);
    ui->displayFlag2->setStyleSheet("border-image: " + display2);
}

void DistinctiveQuiz::setUpButtons(QVector<QString> symbolList,QString display1, QString display2){
    QRandomGenerator rng = QRandomGenerator::securelySeeded();
    QVector<int> buttonsAssigned;
    QVector<QString> flagsUsed;
    int numOfSymbolFlags;
    // Choosing how many buttons will be a correct answer
    if(symbolList.size() >= 6){
        numOfSymbolFlags = rng.bounded(1,5);
    }else{
        numOfSymbolFlags = rng.bounded(1, symbolList.size() - 1);
    }

    for(int i = 0; i < numOfSymbolFlags;i++){
        int buttonWithMatchingFlag;
        QString flagForButton;

        buttonWithMatchingFlag = rng.bounded(4);
        // Ensures the same button is not assigned again.
        while(buttonsAssigned.contains(buttonWithMatchingFlag))
            buttonWithMatchingFlag = rng.bounded(4);

        flagForButton = symbolList.at(rng.bounded(symbolList.size()));

        // Ensures that the flag icon for the button will not match any of the displays.
        while(display1.contains(flagForButton) || display2.contains(flagForButton) || flagsUsed.contains(flagForButton)){
            flagForButton = symbolList.at(rng.bounded(symbolList.size()));
        }
        flagsUsed.append(flagForButton);
        QIcon flagIcon(":/Flags/" + flagForButton);
        QSize size(100,100);
        flagButtons.at(buttonWithMatchingFlag)->setIcon(flagIcon);
        flagButtons.at(buttonWithMatchingFlag)->setIconSize(size);
        flagCorrect[buttonWithMatchingFlag] = true;
        buttonsAssigned.append(buttonWithMatchingFlag);
    }

    QString randomFlag;

    //Used to ensure multiple buttons do not have the same flag.
    QVector<QString> randomFlags;
    for(int i = 0; i < flagButtons.size(); i++){
        randomFlag = "";
        if(!buttonsAssigned.contains(i)){

            //Ensures that if the current category is picked, a different flag is chosen.
            //Makes sure to check for lists that have overlapping flags
            while(randomFlag == "" || symbolList.contains(randomFlag) || randomFlags.contains(randomFlag)){
                int listPicker = rng.bounded(9);

                if(listPicker == 0)
                    randomFlag = BASIC_COLOR_FLAGS.at(rng.bounded(BASIC_COLOR_FLAGS.size()));
                else if(listPicker == 1)
                    randomFlag = FLAGCONSTANTS_H::SIMPLE_FLAGS.at(rng.bounded(SIMPLE_FLAGS.size()));
                else if(listPicker == 2)
                    randomFlag = FLAGCONSTANTS_H::MEANINGFUL_FLAGS.at(rng.bounded(MEANINGFUL_FLAGS.size()));
                else if(listPicker == 3)
                    randomFlag = FLAGCONSTANTS_H::NO_LETTER_OR_SEAL_FLAGS.at(rng.bounded(NO_LETTER_OR_SEAL_FLAGS.size()));
                else if (listPicker == 4)
                    randomFlag = LETTERED_FLAGS.at(rng.bounded(LETTERED_FLAGS.size()));
                else if(listPicker == 5)
                    randomFlag = COMPLEX_COLOR_FLAGS.at(rng.bounded(COMPLEX_COLOR_FLAGS.size()));
                else if(listPicker == 6)
                    randomFlag = ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));
                else if(listPicker == 7)
                    randomFlag = CHRISTIANITY_FLAGS.at(rng.bounded(CHRISTIANITY_FLAGS.size()));
                else if(listPicker == 8)
                    randomFlag = UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));
            }
            randomFlags.append(randomFlag);
            QIcon flagIcon(":/Flags/" + randomFlag);
            QSize size(100,100);
            flagButtons.at(i)->setIcon(flagIcon);
            flagButtons.at(i)->setIconSize(size);
            flagCorrect[i] = false;

        }
    }
}

void DistinctiveQuiz::on_hintButton_clicked()
{
    if(ui->hint->isVisible()){
        ui->hint->setVisible(false);
        ui->hintButton->setText("Show Hint");
    }else{
        ui->hint->setVisible(true);
        ui->hintButton->setText("Hide Hint");
    }
}


void DistinctiveQuiz::on_ColorCodeButton_clicked()
{
    if(ui->colorCode->isVisible()){
        ui->colorCode->setVisible(false);
        ui->ColorCodeButton->setText("Show Color Code Information");
    }else{
        ui->colorCode->setVisible(true);
        ui->ColorCodeButton->setText("Hide Color Code Information");
    }
}

void DistinctiveQuiz::updateStatLabels(){
    QString statText = "Completed Questions: " + QString::number(questions);
    ui->totalQuestions->setText(statText);

    statText = "Total Correct: " + QString::number(correct);
    ui->totalCorrect->setText(statText);

    statText = "Total Incorrect: " + QString::number(incorrect);
    ui->totalIncorrect->setText(statText);

    statText = "Total Missed Correct: " + QString::number(missedCorrect);
    ui->totalMissedCorrect->setText(statText);
}
