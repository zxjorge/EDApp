/**
 * MeaningfulSymbolismLesson.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses MeaningfulSymbolismActivity.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "meaningfulsymbolismactivity.h"
#include "ui_meaningfulsymbolismactivity.h"
#include <QRandomGenerator>
#include <QDebug>

/**
 * @brief MeaningfulSymbolismActivity::MeaningfulSymbolismActivity
 * @param parent
 */
MeaningfulSymbolismActivity::MeaningfulSymbolismActivity(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::MeaningfulSymbolismActivity),
    mainWindow(parent)
{
    ui->setupUi(this);
    currentIndex = 0;
    AnsweredQuestions = 0;
    correctAns = 0;
    maxGames = 5;
    prompts.append("The red background symbolizes revolution and bloodshed. The golden star represents the five main classes in Vietnamese society — intellectuals, farmers, workers, entrepreneurs, and soldiers.");
    prompts.append("The disc represents the sun rising over the country, and its red color is intended to represent the blood that the people of this country shed during their war of independence. The green field represents the land's natural bounty.");
    prompts.append("The white color of the saltire and central disk symbolized peace. The remaining areas were red, for the independence struggle and the nation's suffering and green, for hopes placed on future development.");
    prompts.append("A green field with a centered cross of three bands: the vertical part is: yellow, black, and white, and the horizontal part is: yellow, black, and white, and the red disk superimposed at the center of the cross bearing a purple Sisserou Parrot facing the hoist-side encircled by ten green five-pointed stars.");
    prompts.append("The white represents peace; the green, star, and crescent represent Islam; and the red symbolizes the blood of those killed fighting for independence.");
    prompts.append("The green color in the flag stands for the agriculture and livestock of the country, while the blue represents the sea's bounty. The red represents the bloodshed in the struggle for this country's independence, with the 30 leaves in the wreath representing the thirty years spent in the struggle.");
    prompts.append("Its circular arrangement of white flower petals, set prominently against a bright red background, is supposed to embody the rights and freedoms enjoyed under the “one country, two systems” principle.");
    prompts.append("The blue stripes represent the two oceans that surround the country, while the white band represents peace. The coat of arms includes the resplendent quetzal, which is this country's national bird and a symbol of liberty in Central America.");
    prompts.append("The flag of this country is composed of a red saltire on a white field. In the upper quadrant, the badge of Jersey is surmounted by a yellow \"Plantagenet crown.\"");
    prompts.append("For this country's people, the flag's coloring represents a vision of their country's landscape. The colors stand for three of the elements that make up the island. Red is the fire produced by the island's volcanoes, white recalls the ice and snow that covers Iceland, and blue is for the island's mountains.");
    prompts.append("The design consists of a white crescent with four white five-pointed stars inside a green triangle. The flag has four stripes representing the four main islands of the nation: yellow for Mohéli, white for Mayotte, red for Anjouan, and blue for Grande Comore. The four stars on the flag also symbolize the four islands. The star and crescent, as well as the color green on the flag, symbolizes their main religion, Islam.");
    prompts.append("On this flag, the yellow frigatebird symbolizes command over the sea, freedom, and dance patterns. The blue and white wavy bands represent the Pacific Ocean, which surrounds this country, and the sun refers to this country's position astride the Equator.");
    prompts.append("The red star represents communism, the red panels represent patriotism, the white stripe is unification and culture, with the blue stripe representing unity.");
    prompts.append("The color red was chosen to represent the bloodshed in the quest for the nation's freedom. The color black symbolizes the dark days when the region was occupied by Italy. Finally, the color green represents wealth, prosperity, and the nation's agriculture. The star and crescent symbolize Islam.");
    prompts.append("The red stripe represented the Spaniards that joined in the quest for this country's Independence. Today, those meanings have shifted somewhat. In the modern age, the green represents hope and victory, the white represents unity, and the red pays tribute to the national heroes who have fought for this country over the years. In the middle is the national symbol of this country which depicts a golden eagle perched on a prickly pear cactus devouring a rattlesnake.");
    prompts.append("On this flag, red symbolizes all of the blood lost by people fighting for this country to become a republic, and green symbolizes hope for the future. In the middle of this flag, there is a yellow armillary sphere and a red shield. The armillary sphere is an astronomical device that was used to navigate the oceans during the Age of Exploration. On the shield, there are 7 yellow castles and a white interior with 5 smaller blue shields. On each of the blue shields, there are 5 white dots. The shield itself represents past victories. The 7 castles represent the 7 castles that this country took back from the Moors. The 5 smaller blue shields represent the 5 Moorish kings who were killed by the first King of this country. The 5 white dots within each blue shield represent the 5 wounds of Christ.");

    correctAnswers.append(":/Flags/vn.png");
    correctAnswers.append(":/Flags/bd.png");
    correctAnswers.append(":/Flags/bi.png");
    correctAnswers.append(":/Flags/dm.png");
    correctAnswers.append(":/Flags/dz.png");
    correctAnswers.append(":/Flags/er.png");
    correctAnswers.append(":/Flags/hk.png");
    correctAnswers.append(":/Flags/gt.png");
    correctAnswers.append(":/Flags/je.png");
    correctAnswers.append(":/Flags/is.png");
    correctAnswers.append(":/Flags/km.png");
    correctAnswers.append(":/Flags/ki.png");
    correctAnswers.append(":/Flags/kp.png");
    correctAnswers.append(":/Flags/ly.png");
    correctAnswers.append(":/Flags/mx.png");
    correctAnswers.append(":/Flags/pt.png");

    for (int i = 0; i < 15; ++i) {
        numbers[i] = i;
    }

    std::srand(std::time(0));
    // Fisher-Yates shuffle algorithm
    for (int i = 15 - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);  // Generate a random index
        std::swap(numbers[i], numbers[j]);     // Swap elements at i and j
    }

    connect(ui->CheckNext, &QPushButton::clicked, this, &MeaningfulSymbolismActivity::CheckAnswer);

    // Connect the clicked() signal of each button to a slot
    connect(ui->ans1, &QPushButton::clicked, this, [=]() {
        if (lastClickedButton && lastClickedButton != ui->ans1) {
            lastClickedButton->setStyleSheet(""); // Revert color of previous button
        }
        lastClickedButton = ui->ans1; // Save reference of clicked button
        buttonIndex = 0;
        ui->CheckNext->blockSignals(false);
        ui->ans1->setStyleSheet("background-color: blue;"); // Set background color to blue
    });

    connect(ui->ans2, &QPushButton::clicked, this, [=]() {
        if (lastClickedButton && lastClickedButton != ui->ans2) {
            lastClickedButton->setStyleSheet(""); // Revert color of previous button
        }
        lastClickedButton = ui->ans2; // Save reference of clicked button
        buttonIndex = 1;
        ui->CheckNext->blockSignals(false);
        ui->ans2->setStyleSheet("background-color: blue;"); // Set background color to blue
    });

    connect(ui->ans3, &QPushButton::clicked, this, [=]() {
        if (lastClickedButton && lastClickedButton != ui->ans3) {
            lastClickedButton->setStyleSheet(""); // Revert color of previous button
        }
        lastClickedButton = ui->ans3; // Save reference of clicked button
        buttonIndex = 2;
        ui->CheckNext->blockSignals(false);
        ui->ans3->setStyleSheet("background-color: blue;"); // Set background color to blue
    });

    connect(ui->ans4, &QPushButton::clicked, this, [=]() {
        if (lastClickedButton && lastClickedButton != ui->ans4) {
            lastClickedButton->setStyleSheet(""); // Revert color of previous button
        }
        lastClickedButton = ui->ans4; // Save reference of clicked button
        buttonIndex = 3;
        ui->CheckNext->blockSignals(false);
        ui->ans4->setStyleSheet("background-color: blue;"); // Set background color to blue
    });

    FirstQuestion();
}

/**
 * @brief MeaningfulSymbolismActivity::~MeaningfulSymbolismLActivity
 */
MeaningfulSymbolismActivity::~MeaningfulSymbolismActivity()
{
    delete ui;
}

void MeaningfulSymbolismActivity::InitializeQuestion(){
    currentIndex++;
    QVector<QString> icons;
    selectedIndex = numbers[currentIndex];
    ui->promptLabel->setText(prompts.at(selectedIndex));
    icons.append(correctAnswers.at(selectedIndex));

    while (icons.size() < 4) {
        int randomNumber = QRandomGenerator::global()->bounded(15); // Generate a random number between 0 and 14
        if (randomNumber != selectedIndex && !icons.contains(correctAnswers.at(randomNumber))) {
            icons.append(correctAnswers.at(randomNumber));
        }
    }

    for (int i = icons.size() - 1; i > 0; --i) {
        int j = QRandomGenerator::global()->bounded(i + 1); // Generate a random index between 0 and i
        icons.swapItemsAt(i, j); // Swap the elements at index i and j
    }

    QIcon icon(icons.at(0));
    ui->ans1->setIcon(icon);

    icon = QIcon (icons.at(1));
    ui->ans2->setIcon(icon);

    icon = QIcon (icons.at(2));
    ui->ans3->setIcon(icon);

    icon = QIcon (icons.at(3));
    ui->ans4->setIcon(icon);


    ui->ans1->setIconSize(QSize(150, 150));
    ui->ans2->setIconSize(QSize(150, 150));
    ui->ans3->setIconSize(QSize(150, 150));
    ui->ans4->setIconSize(QSize(150, 150));
    SavedIcons = icons;
    ui->CheckNext->blockSignals(true);
}

void MeaningfulSymbolismActivity::FirstQuestion(){
    selectedIndex = numbers[currentIndex];
    ui->promptLabel->setText(prompts.at(selectedIndex));
    QVector<QString> icons;
    icons.append(correctAnswers.at(selectedIndex));

    while (icons.size() < 4) {
        int randomNumber = QRandomGenerator::global()->bounded(15); // Generate a random number between 0 and 14
        if (randomNumber != selectedIndex && !icons.contains(correctAnswers.at(randomNumber))) {
            icons.append(correctAnswers.at(randomNumber));
        }
    }

    for (int i = icons.size() - 1; i > 0; --i) {
        int j = QRandomGenerator::global()->bounded(i + 1); // Generate a random index between 0 and i
        icons.swapItemsAt(i, j); // Swap the elements at index i and j
    }


    QIcon icon(icons.at(0));
    ui->ans1->setIcon(icon);

    icon = QIcon (icons.at(1));
    ui->ans2->setIcon(icon);

    icon = QIcon (icons.at(2));
    ui->ans3->setIcon(icon);

    icon = QIcon (icons.at(3));
    ui->ans4->setIcon(icon);

    ui->ans1->setIconSize(QSize(150, 150));
    ui->ans2->setIconSize(QSize(150, 150));
    ui->ans3->setIconSize(QSize(150, 150));
    ui->ans4->setIconSize(QSize(150, 150));
    SavedIcons = icons;
    ui->CheckNext->blockSignals(true);
}

void MeaningfulSymbolismActivity::CheckAnswer(){
    AnsweredQuestions++;
    disconnect(ui->CheckNext, &QPushButton::clicked, this, &MeaningfulSymbolismActivity::CheckAnswer);
    if(SavedIcons.at(buttonIndex) == correctAnswers.at(selectedIndex)){
         lastClickedButton->setStyleSheet("background-color: green;");
        correctAns++;
    }
    else{
         lastClickedButton->setStyleSheet("background-color: red;");
    }

    ui->ans1->blockSignals(true);
    ui->ans2->blockSignals(true);
    ui->ans3->blockSignals(true);
    ui->ans4->blockSignals(true);

    ui->CheckNext->setText("Next Question");
    ui->progressBar->setValue(100 * correctAns / maxGames);
    connect(ui->CheckNext, &QPushButton::clicked, this, &MeaningfulSymbolismActivity::NextQuestion);
}

void MeaningfulSymbolismActivity::NextQuestion(){
    if(AnsweredQuestions < maxGames){
    disconnect(ui->CheckNext, &QPushButton::clicked, this, &MeaningfulSymbolismActivity::NextQuestion);
    InitializeQuestion();
    ui->CheckNext->setText("Check Answer");
    lastClickedButton->setStyleSheet(""); // Revert color of previous button

    ui->ans1->blockSignals(false);
    ui->ans2->blockSignals(false);
    ui->ans3->blockSignals(false);
    ui->ans4->blockSignals(false);

    connect(ui->CheckNext, &QPushButton::clicked, this, &MeaningfulSymbolismActivity::CheckAnswer);
    }else{
    emit SendScore(correctAns);
    }
 }

void MeaningfulSymbolismActivity::Reset(){
    lastClickedButton->setStyleSheet(""); // Revert color of previous button
    AnsweredQuestions=0;
    correctAns = 0;
    InitializeQuestion();
}






