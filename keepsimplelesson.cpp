#include "keepsimplelesson.h"
#include "basicquiz.h"
#include "ui_keepsimplelesson.h"
#include <QPushButton>
#include "flagwidget.h"
#include "flagconstants.h"
#include "flagcoloringpuzzle.h"

KeepSimpleLesson::KeepSimpleLesson(MainWindow *parent) :
    QStackedWidget(parent),
    ui(new Ui::KeepSimpleLesson),
    mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(ui->nextButton_2,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::NextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &KeepSimpleLesson::BackClicked);
    connect(ui->mainMenu,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });
    connect(ui->mainMenu_2,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });

    // Assuming label_2 is a QLabel object
    QPixmap pixmap(":/Flags/ae.png"); // Load your image
    ui->label_2->setPixmap(pixmap); // Set the pixmap to the label

    // Create a Box2D world with gravity in the downward direction
    b2Vec2 gravity(0.0f, -9.8f);
    b2World* world = new b2World(gravity);

    // Create a dynamic body with a circle shape
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f); // Set the initial position of the body
    b2Body* body = world->CreateBody(&bodyDef);
    b2CircleShape shape;
    shape.m_radius = 1.0f; // Set the radius of the circle
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f; // Set the density of the body
    fixtureDef.friction = 0.3f; // Set the friction coefficient of the body
    fixtureDef.restitution = 0.5f; // Set the restitution coefficient of the body
    body->CreateFixture(&fixtureDef);

    // Set up a timer to step the Box2D world and update the position of the image
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        // Step the Box2D world
        float32 timeStep = 1.0f / 60.0f;
        int32 velocityIterations = 6;
        int32 positionIterations = 2;
        world->Step(timeStep, velocityIterations, positionIterations);

        // Update the position of the image based on the position of the Box2D body
        float32 x = body->GetPosition().x;
        float32 y = body->GetPosition().y;
        ui->label_2->move(x, y);
    });
    timer->start(16); // Start the timer with a 60 FPS update rate

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
    } else {
        mainWindow->switchScene(new BasicQuiz(
            "Which flag is simpler?",
            SIMPLE_FLAGS,
            LETTERED_FLAGS,
            new FlagColoringPuzzle(mainWindow),
            mainWindow
        ));
    }

}

/**
 * @brief KeepSimpleLesson::BackClicked
 */
void KeepSimpleLesson::BackClicked(){
    int prevIndex = currentIndex() - 1;
    setCurrentIndex(prevIndex);

}










