#include "meaningfulsymbolismactivity.h"
#include "ui_meaningfulsymbolismactivity.h"

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

    for (int i = 0; i < 15; ++i) {
        numbers[i] = i;
    }

    std::srand(std::time(0));
    // Fisher-Yates shuffle algorithm
    for (int i = 15 - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);  // Generate a random index
        std::swap(numbers[i], numbers[j]);     // Swap elements at i and j
    }

    connect(ui->newPrompt, &QPushButton::clicked, this, &MeaningfulSymbolismActivity::DisplayPrompt);
    DisplayPrompt();
}

/**
 * @brief MeaningfulSymbolismActivity::~MeaningfulSymbolismLActivity
 */
MeaningfulSymbolismActivity::~MeaningfulSymbolismActivity()
{
    delete ui;
}

void MeaningfulSymbolismActivity::DisplayPrompt(){
    ui->promptLabel->setText(prompts.at(numbers[currentIndex]));
    currentIndex = (currentIndex + 1)%15 ;
}





