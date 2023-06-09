/**
 * BasicQuiz.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses BasicQuiz.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "basicquiz.h"
#include "flagconstants.h"
#include "mainmenu.h"
#include "ui_basicquiz.h"
#include <QRandomGenerator>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QPainter>


const double HORIZONTAL_SPEED = 300;
const double VERTICAL_SPEED = 100;
const double SCALE = 10.0;


BasicQuiz::BasicQuiz(
    QString question,
    QVector<QString> correctFlags,
    QVector<QString> wrongFlags,
    QWidget *successScene,
    MainWindow *parent,
    int currentStreak,
    int targetStreak,
    QString lastCorrectFlag,
    QString lastWrongFlag) :
    QWidget(parent),
    ui(new Ui::BasicQuiz)
{
    ui->setupUi(this);
    ui->question->setText(question);
    successScene->hide();
    ui->progressBar->setValue(100 * currentStreak / targetStreak);


    QRandomGenerator *rng = QRandomGenerator::global();
    QString correctFlagName;

    do {
        correctFlagName = ":/Flags/" + correctFlags.at(rng->bounded(correctFlags.length()));
    } while (correctFlagName == lastCorrectFlag);

    QString wrongFlagName;

    do {
        wrongFlagName = ":/Flags/" + wrongFlags.at(rng->bounded(wrongFlags.length()));
    } while (wrongFlagName == lastWrongFlag);

    connect(ui->mainMenu,
            &QPushButton::clicked,
            this,
            [=] {
                parent->switchScene(new MainMenu(parent));
            });

    auto failAnimation = [=] (QPushButton *wrongFlag, QPushButton *correctFlag) {
        correctFlag->blockSignals(true);
        wrongFlag->blockSignals(true);

        b2World *world = new b2World(b2Vec2(0, 980.0f / SCALE));

        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0, height() / 2 / SCALE);

        // Call the body factory which allocates memory for the ground body
        // from a pool and creates the ground box shape (also from a pool).
        // The body is also added to the world.
        b2Body* groundBody = world->CreateBody(&groundBodyDef);

        // Define the ground box shape.
        b2PolygonShape groundBox;

        // The extents are the half-widths of the box.
        groundBox.SetAsBox(width() / SCALE, 10.0f / SCALE);

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(wrongFlag->x() / SCALE, wrongFlag->y() / SCALE);
        int horizontalSpeed;

        if (wrongFlag->x() > ui->verticalFrame->width() / 2) {
            horizontalSpeed = HORIZONTAL_SPEED;
        } else {
            horizontalSpeed = - HORIZONTAL_SPEED;
        }

        QRandomGenerator rng = QRandomGenerator::securelySeeded();
        bodyDef.linearVelocity.Set(horizontalSpeed / SCALE, -rng.bounded(VERTICAL_SPEED) / SCALE);
        b2Body *body = world->CreateBody(&bodyDef);

        // Add the ground fixture to the ground body.
        groundBody->CreateFixture(&groundBox, 0.0f);

        // Define the dynamic body. We set its position and call the body factory.

        // Define another box shape for our dynamic body.
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(wrongFlag->width() / 2 / SCALE, wrongFlag->height() / 4 / SCALE);

        // Define the dynamic body fixture.
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;

        // Set the box density to be non-zero, so it will be dynamic.
        fixtureDef.density = 1.0f;

        // Override the default friction.
        fixtureDef.friction = 0.0f;
        fixtureDef.restitution = 0.82;
        // Add the shape to the body.
        body->CreateFixture(&fixtureDef);

        QTimer* timer = new QTimer(this);

        connect(timer, &QTimer::timeout, this, [=] () mutable {
            // Step the Box2D world
            world->Step(1.0f/60.0f, 6, 2);

            // Update the position of the image based on the position of the Box2D body
            float32 x = body->GetPosition().x * SCALE;
            float32 y = body->GetPosition().y * SCALE;
            wrongFlag->move(x, y);

            // Run until we are off the screen
            if (y >= height() || x >= width() || x <= - wrongFlag->width()) {
                if (successScene == nullptr) {
                    return;
                }
                QWidget *tmp = successScene;
                successScene = nullptr;

                parent->switchScene(
                    new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, 0, targetStreak, correctFlagName, wrongFlagName)
                );
                timer->deleteLater();
            }

        });
        timer->start(16);
    };

    auto onWrong1 = [=] () mutable {
        failAnimation(ui->flag1, ui->flag2);
    };

    auto onWrong2 = [=] () mutable {
        failAnimation(ui->flag2, ui->flag1);
    };

    auto onCorrect = [=] () mutable {
        currentStreak++;
        QWidget *tmp = successScene;
        successScene = nullptr;

        if (currentStreak >= targetStreak) {
            tmp->show();
            parent->switchScene(tmp);
        } else {
            parent->switchScene(
                new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, currentStreak, targetStreak, correctFlagName, wrongFlagName)
            );
        }
    };

    if (rng->bounded(2) == 0) {
        // flag1 is the right answer
        ui->flag1->setIcon(QIcon(correctFlagName));
        ui->flag1Name->setText(FLAG_NAMES.at(extractCountryCode(correctFlagName)));
        ui->flag2->setIcon(QIcon(wrongFlagName));
        ui->flag2Name->setText(FLAG_NAMES.at(extractCountryCode(wrongFlagName)));

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
        ui->flag1->setIcon(QIcon(wrongFlagName));
        ui->flag1Name->setText(FLAG_NAMES.at(extractCountryCode(wrongFlagName)));
        ui->flag2->setIcon(QIcon(correctFlagName));
        ui->flag2Name->setText(FLAG_NAMES.at(extractCountryCode(correctFlagName)));

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
