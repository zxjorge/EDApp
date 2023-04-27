#include "bedistinctiveorrelatedactivity.h"
#include "ui_bedistinctiveorrelatedactivity.h"
#include "qdir.h"
#include "qrandom.h"
#include "flagConstants.h"
#include "mainmenu.h"

BeDistinctiveOrRelatedActivity::BeDistinctiveOrRelatedActivity(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::BeDistinctiveOrRelatedActivity),
    mainWindow(parent)
{
    ui->setupUi(this);

    answerStage = true;
    correct = 0;
    incorrect = 0;
    missedCorrect = 0;
    questions = 0;
    score = 0;
    ui->progressBar->setValue(0);
    ui->progressBar->setStyleSheet("text-align:center");
    ui->hint->setVisible(false);

    flagButtons.append(ui->flag1);
    flagButtons.append(ui->flag2);
    flagButtons.append(ui->flag3);
    flagButtons.append(ui->flag4);

    flagScores.append(ui->flag1Score);
    flagScores.append(ui->flag2Score);
    flagScores.append(ui->flag3Score);
    flagScores.append(ui->flag4Score);

    for(int i = 0; i < flagButtons.size(); i++){
        flagSelected.append(false);
        flagCorrect.append(false);
    }

    SetUpQuestion();

    connect(ui->flag1,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedActivity::Flag1Clicked);

    connect(ui->flag2,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedActivity::Flag2Clicked);

    connect(ui->flag3,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedActivity::Flag3Clicked);

    connect(ui->flag4,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedActivity::Flag4Clicked);

    connect(ui->hintButton,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedActivity::HintClicked);

    connect(ui->next,
            &QPushButton::clicked,
            this,
            &BeDistinctiveOrRelatedActivity::NextClicked);
}

BeDistinctiveOrRelatedActivity::~BeDistinctiveOrRelatedActivity()
{
    delete ui;
}

void BeDistinctiveOrRelatedActivity::Flag1Clicked(){
    ChangeButtonSelectColor(0);
}

void BeDistinctiveOrRelatedActivity::Flag2Clicked(){
    ChangeButtonSelectColor(1);
}

void BeDistinctiveOrRelatedActivity::Flag3Clicked(){
    ChangeButtonSelectColor(2);
}

void BeDistinctiveOrRelatedActivity::Flag4Clicked(){
    ChangeButtonSelectColor(3);
}

void BeDistinctiveOrRelatedActivity::ChangeButtonSelectColor(int i){
    if(flagSelected.at(i) && answerStage){
        flagButtons.at(i)->setStyleSheet("background-color:rgb(210, 210, 210)");
        flagSelected[i] = false;
    }
    else if(answerStage){
        flagButtons.at(i)->setStyleSheet("background-color:rgb(0,100,255)");

        flagSelected[i] = true;
    }
}

void BeDistinctiveOrRelatedActivity::NextClicked()
{
    if(answerStage){
        if(!flagSelected.contains(true)){
        }else{
            int scoreChange = ui->progressBar->value();
            for(int i = 0; i < flagButtons.size(); i++){
                if(flagSelected.at(i)){
                    if(flagCorrect.at(i)){
                        flagButtons.at(i)->setStyleSheet("background-color:rgb(0,255,0)");
                        flagScores.at(i)->setText("    +" + QString::number(100/targetScore) + "%");
                        scoreChange += 100/targetScore;
                        correct += 1;
                        score += 1;
                    }
                    else{
                        flagButtons.at(i)->setStyleSheet("background-color:rgb(255,0,0)");
                        flagScores.at(i)->setText("    -" + QString::number(100/targetScore) + "%");
                        scoreChange -= 100/targetScore;
                        incorrect += 1;
                        if(score > 0)
                            score -= 1;
                    }
                }
                else if(flagCorrect.at(i)){
                    flagButtons.at(i)->setStyleSheet("background-color:rgb(255,255,0)");
                    flagScores.at(i)->setText("    +0%");
                    missedCorrect += 1;
                }
            }

            answerStage = false;
            if(score >= targetScore){
                ui->progressBar->setValue(100);
                ui->next->setText("Complete Quiz");
            }
            else{
                ui->next->setText("Next Question");
                ui->progressBar->setValue(scoreChange);
            }
            questions += 1;
        }
    }else if (!answerStage){
        if(correct >= targetScore){
            emit SendActivityDetails(questions, correct, incorrect, missedCorrect);
        }else{
            for(QLabel* scoreLabel : flagScores){
                scoreLabel -> setText("");
            }
            SetUpQuestion();
            ui->next->setText("Check Answers");
        }
    }
}

void BeDistinctiveOrRelatedActivity::SetUpQuestion(){
    for(int i = 0; i < flagButtons.size(); i++){
        flagButtons.at(i)->setIcon(QIcon());
        flagButtons.at(i)->setStyleSheet("background-color:  rgb(210, 210, 210)");
        flagSelected[i] = false;
        flagCorrect[i] = false;
    }

    answerStage = true;
    ui->hint->setVisible(false);
    ui->hintButton->setText("Show Hint");

    QRandomGenerator rng = QRandomGenerator::securelySeeded();
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
        SetUpButtons(CHRISTIANITY_FLAGS, display1,display2);
        ui->hint->setText("Choose flags that:\nContain Christian symbols\nA cross or cross constellation");
    }
    else if(symbolPicker == 1){
        display1 += ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));
        display2 += ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));

        while(display1 == display2) {
            display2 = "url(:/Flags/";
            display2 += ISLAM_FLAGS.at(rng.bounded(ISLAM_FLAGS.size()));
        }

        SetUpButtons(ISLAM_FLAGS, display1,display2);
        ui->hint->setText("Choose flags that:\nContain Islamic symbols\nA crescent moon or arabic text");
    }
    else{
        display1 += UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));
        display2 += UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));

        while(display1 == display2) {
            display2 = "url(:/Flags/";
            display2 += UNION_JACK_FLAGS.at(rng.bounded(UNION_JACK_FLAGS.size()));
        }

        SetUpButtons(UNION_JACK_FLAGS,display1,display2);
        ui->hint->setText("Choose flags that have a Union Jack");
    }

    display1+=")";
    display2+=")";
    ui->displayFlag1->setStyleSheet("border-image: " + display1);
    ui->displayFlag2->setStyleSheet("border-image: " + display2);
}

void BeDistinctiveOrRelatedActivity::SetUpButtons(QVector<QString> symbolList,QString display1, QString display2){
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
        QSize size(150,150);
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
            QIcon flagIcon;
            //Ensures that if the current category is picked, a different flag is chosen.
            //Makes sure to check for lists that have overlapping flags
            while(randomFlag == "" || symbolList.contains(randomFlag) || randomFlags.contains(randomFlag) || flagIcon.isNull()){
                flagIcon = QIcon();
                QDir dir(":/Flags");
                // Retrieve the list of files in the resource folder
                QStringList fileList = dir.entryList(QDir::Files);

                int flagPicker = rng.bounded(fileList.size() -1);

                randomFlag = fileList[flagPicker];
                flagIcon.addFile(":/Flags/" + randomFlag);

            }
            randomFlags.append(randomFlag);
            QSize size(150,150);
            flagButtons.at(i)->setIcon(flagIcon);
            flagButtons.at(i)->setIconSize(size);
            flagCorrect[i] = false;

        }
    }
}

void BeDistinctiveOrRelatedActivity::HintClicked()
{
    if(ui->hint->isVisible()){
        ui->hint->setVisible(false);
        ui->hintButton->setText("Show Hint");
    }else{
        ui->hint->setVisible(true);
        ui->hintButton->setText("Hide Hint");
    }
}

void BeDistinctiveOrRelatedActivity::Reset(){
    for(QLabel* scoreLabel : flagScores){
        scoreLabel -> setText("");
    }
    SetUpQuestion();
    answerStage = true;
    correct = 0;
    incorrect = 0;
    missedCorrect = 0;
    questions = 0;
    score = 0;
    ui->progressBar->setValue(0);
    ui->progressBar->setStyleSheet("text-align:center");
    ui->hint->setVisible(false);
}
