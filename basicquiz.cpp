#include "basicquiz.h"
#include "ui_basicquiz.h"
#include <QRandomGenerator>
#include <Box2d/Box2d.h>
#include <QTimer>

BasicQuiz::BasicQuiz(
    QString question,
    QVector<QString> correctFlags,
    QVector<QString> wrongFlags,
    QWidget *successScene,
    MainWindow *parent,
    int currentStreak,
    int targetStreak
) :
    QWidget(parent),
    ui(new Ui::BasicQuiz)
{
    ui->setupUi(this);
    ui->question->setText(question);
    successScene->hide();
    QRandomGenerator rng = QRandomGenerator::securelySeeded();

    auto onCorrect = [=] () mutable {
        currentStreak++;
        QWidget *tmp = successScene;
        successScene = nullptr;
        if (currentStreak >= targetStreak) {
            tmp->show();
            parent->switchScene(tmp);
        } else {
            parent->switchScene(
                new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, currentStreak, targetStreak)
                );
        }
    };
    auto onWrong1 = [=] () mutable {

        QWidget *tmp = successScene;
        successScene = nullptr;
        b2Vec2 gravity(0.0f, 9.8f); // change gravity direction to point upwards
        b2World* world = new b2World(gravity);

        // Create a dynamic body with a rectangle shape
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(ui->flag1->x() + ui->flag1->width() / 2, ui->flag1->y() + ui->flag1->height() / 2);
        b2Body* body = world->CreateBody(&bodyDef);
        b2PolygonShape shape;
        shape.SetAsBox(ui->flag1->width() / 2, ui->flag1->height() / 2);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f; // Set the density of the body
        fixtureDef.friction = 0.3f; // Set the friction coefficient of the body
        fixtureDef.restitution = 0.5f; // Set the restitution coefficient of the body
        body->CreateFixture(&fixtureDef);

        // Set an initial downward velocity to the body
        b2Vec2 velocity(0.0f, -10.0f);
        body->SetLinearVelocity(velocity);

        // Set up a timer to step the Box2D world and update the position of the image
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=]() {
            // Step the Box2D world
            float32 timeStep = 1.0f / 50.0f;
            int32 velocityIterations = 6;
            int32 positionIterations = 2;
            world->Step(timeStep, velocityIterations, positionIterations);

            // Update the position of the image based on the position of the Box2D body
            float32 x = body->GetPosition().x - ui->flag1->width() / 2;
            float32 y = body->GetPosition().y - ui->flag1->height() / 2;
            ui->flag1->move(x, y);
            if (y >= this->height()) {
                parent->switchScene(
                    new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, 0, targetStreak)
                );
            }
        });
        timer->start(16); // Start the timer with a 60 FPS update rate

       // parent->switchScene(
         //  new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, 0, targetStreak)
        //);
    };

    auto onWrong2 = [=] () mutable {

        QWidget *tmp = successScene;
        successScene = nullptr;
        b2Vec2 gravity(0.0f, 9.8f); // change gravity direction to point upwards
        b2World* world = new b2World(gravity);

        // Create a dynamic body with a rectangle shape
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(ui->flag2->x() + ui->flag2->width() / 2, ui->flag2->y() + ui->flag2->height() / 2);
        b2Body* body = world->CreateBody(&bodyDef);
        b2PolygonShape shape;
        shape.SetAsBox(ui->flag2->width() / 2, ui->flag2->height() / 2);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f; // Set the density of the body
        fixtureDef.friction = 0.3f; // Set the friction coefficient of the body
        fixtureDef.restitution = 0.5f; // Set the restitution coefficient of the body
        body->CreateFixture(&fixtureDef);

        // Set an initial downward velocity to the body
        b2Vec2 velocity(0.0f, -10.0f);
        body->SetLinearVelocity(velocity);

        // Set up a timer to step the Box2D world and update the position of the image
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=]() {
            // Step the Box2D world
            float32 timeStep = 1.0f / 50.0f;
            int32 velocityIterations = 6;
            int32 positionIterations = 2;
            world->Step(timeStep, velocityIterations, positionIterations);

            // Update the position of the image based on the position of the Box2D body
            float32 x = body->GetPosition().x - ui->flag2->width() / 2;
            float32 y = body->GetPosition().y - ui->flag2->height() / 2;
            ui->flag2->move(x, y);
            if (y >= this->height()) {
                parent->switchScene(
                    new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, 0, targetStreak)
                );
            }
        });
        timer->start(16); // Start the timer with a 60 FPS update rate








    };

    if (rng.bounded(2) == 0) {
        // flag1 is the right answer
        ui->flag1->setIcon(QIcon(":/Flags/" + correctFlags.at(rng.bounded(correctFlags.length()))));
        ui->flag2->setIcon(QIcon(":/Flags/" + wrongFlags.at(rng.bounded(wrongFlags.length()))));
        connect(ui->flag1,
                &QPushButton::clicked,
                this,
                onCorrect);
        connect(ui->flag2,
                &QPushButton::clicked,
                this,
                onWrong2);
    } else {
        // flag2 is the right answer
        ui->flag1->setIcon(QIcon(":/Flags/" + wrongFlags.at(rng.bounded(wrongFlags.length()))));
        ui->flag2->setIcon(QIcon(":/Flags/" + correctFlags.at(rng.bounded(correctFlags.length()))));
        connect(ui->flag1,
                &QPushButton::clicked,
                this,
                onWrong1);
        connect(ui->flag2,
                &QPushButton::clicked,
                this,
                onCorrect);
    }
}

BasicQuiz::~BasicQuiz()
{
    delete ui;
}
