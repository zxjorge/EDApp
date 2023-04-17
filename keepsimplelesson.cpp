#include "keepsimplelesson.h"
#include "ui_keepsimplelesson.h"
#include <QPushButton>
#include "Box2D/Box2D.h"

KeepSimpleLesson::KeepSimpleLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::KeepSimpleLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    QPushButton* NextButton1 = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("nextButton"));
    QPushButton* NextButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("nextButton_2"));
    QPushButton* BackButton = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("backButton"));
    QPushButton* mainMenuButton = qobject_cast<QPushButton*>(widget(0)->findChild<QPushButton*>("mainMenu"));
    QPushButton* mainMenuButton2 = qobject_cast<QPushButton*>(widget(1)->findChild<QPushButton*>("mainMenu_2"));

    connect(NextButton1,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(NextButton2,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(BackButton,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::BackClicked);


    connect(mainMenuButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });

    connect(mainMenuButton2,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });

}

/**
 * @brief KeepSimpleLesson::~KeepSimpleLesson
 */
KeepSimpleLesson::~KeepSimpleLesson()
{
    delete ui;
}

/**
 * @brief KeepSimpleLesson::NextClicked
 */
void KeepSimpleLesson::NextClicked(){

    int nextIndex = currentIndex() + 1;
    if (nextIndex < count()) {
        setCurrentIndex(nextIndex);
    }

}

/**
 * @brief KeepSimpleLesson::BackClicked
 */
void KeepSimpleLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);
    animateFlag();
}

void KeepSimpleLesson::animateFlag() {
    // First, load your flag image into a QPixmap object
    QPixmap flag_img(":/Flags/ae.png");

    // Set the label's pixmap to the flag image
    ui->label_6->setPixmap(flag_img);

    // Create a Box2D world object
    b2Vec2 gravity(0.0f, -9.81f);
    b2World* world = new b2World(gravity);

    // Create a static ground body
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Create a dynamic flag body
    b2BodyDef flagBodyDef;
    flagBodyDef.type = b2_dynamicBody;
    flagBodyDef.position.Set(0.0f, 0.0f);
    b2Body* flagBody = world->CreateBody(&flagBodyDef);
    b2PolygonShape flagBox;
    flagBox.SetAsBox(1.0f, 1.0f);
    flagBody->CreateFixture(&flagBox, 1.0f);

    // Apply a force to the flag body to make it fall
    b2Vec2 force(0.0f, -100.0f);
    b2Vec2 point(0.0f, 0.0f);
    flagBody->ApplyForce(force, point, true);

}
