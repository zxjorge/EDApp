#include "basicquiz.h"
#include "ui_basicquiz.h"
#include <QRandomGenerator>
#include <Box2d/Box2d.h>
#include <QTimer>
#include <QPainter>


BasicQuiz::BasicQuiz(QString question,
    QVector<QString> correctFlags,
    QVector<QString> wrongFlags,
    QWidget *successScene,
    MainWindow *parent,
    int currentStreak,
    int targetStreak) :
    QWidget(parent),
    ui(new Ui::BasicQuiz),
    world(b2Vec2(9.8f, 9.8f))
{
    ui->setupUi(this);
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 20.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.

    /*b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(ui->flag1->x() + ui->flag1->width() / 2, ui->flag1->y() + ui->flag1->height() / 2);
    body = world.CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(ui->flag1->width() / 2, ui->flag1->height() / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f; // Set the density of the body
    fixtureDef.friction = 0.3f; // Set the friction coefficient of the body
    fixtureDef.restitution = 0.5f; // Set the restitution coefficient of the body
    body->CreateFixture(&fixtureDef);
    */

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(ui->flag1->x() + ui->flag1->width() / 2, ui->flag1->y() + ui->flag1->height() / 2);
    body = world.CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(ui->flag1->width() / 2, ui->flag1->height() / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f; // Set the density of the body
    fixtureDef.friction = 0.3f; // Set the friction coefficient of the body
    fixtureDef.restitution = 0.5f; // Set the restitution coefficient of the body
    body->CreateFixture(&fixtureDef);


    // Set an initial downward velocity to the body
    //b2Vec2 velocity(0.0f, -10.0f);
    //body->SetLinearVelocity(velocity);
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


        // Create a dynamic body with a rectangle shape
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(ui->flag1->x() + ui->flag1->width() / 2, ui->flag1->y() + ui->flag1->height() / 2);
        b2Body* body = world.CreateBody(&bodyDef);
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
            float32 timeStep = 1.0f / 2.0f;
            int32 velocityIterations = 6;
            int32 positionIterations = 2;
            world.Step(timeStep, velocityIterations, positionIterations);

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

        /**b2Vec2 gravity(0.0f, -9.81f);
        b2World world(gravity);

        QPointF buttonPos = ui->flag1->pos();
        b2BodyDef buttonDef;
        buttonDef.type = b2_dynamicBody;
        buttonDef.position.Set(buttonPos.x(), -buttonPos.y());
        b2Body* buttonBody = world.CreateBody(&buttonDef);
        buttonBody->SetUserData(ui->flag1);

        QSizeF buttonSize = ui->flag1->size();
        b2PolygonShape buttonShape;
        buttonShape.SetAsBox(buttonSize.width() / 2.0f, buttonSize.height() / 2.0f);
        b2FixtureDef buttonFixtureDef;
        buttonFixtureDef.shape = &buttonShape;
        buttonFixtureDef.density = 1.0f;
        buttonFixtureDef.friction = 0.3f;
        buttonFixtureDef.restitution = 0.5f;
        buttonBody->CreateFixture(&buttonFixtureDef);

        world.Step(1.0f / 60.0f, 6, 2);
        for (b2Body* body = world.GetBodyList(); body != nullptr; body = body->GetNext()) {
            if (body->GetType() == b2_dynamicBody) {
                QPushButton* button = static_cast<QPushButton*>(body->GetUserData());
                if (button != nullptr) {
                    // Update position of the button
                    QPointF pos(body->GetPosition().x, -body->GetPosition().y);
                    button->setGeometry(QRect(pos.toPoint(), button->size()));

                    // Update rotation of the button
                    QTransform transform;
                    transform.translate(button->width() / 2.0, button->height() / 2.0);
                    transform.rotateRadians(-body->GetAngle());
                    transform.translate(-button->width() / 2.0, -button->height() / 2.0);
                    button->setMask(transform.map(button->mask()));
                }
            }
        }*/

       // parent->switchScene(
         //  new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, 0, targetStreak)
        //);
    };

    auto onWrong2 = [=] () mutable {

        // Define the ground body.


        // Define the dynamic body. We set its position and call the body factory.

        printf("Init world\n");

        connect(&timer, &QTimer::timeout, this, &BasicQuiz::updateWorld);
        timer.start(10);
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

void BasicQuiz::paintEvent(QPaintEvent *) {
    // Create a painter
    QPainter painter(this);
    b2Vec2 position = body->GetPosition();
    QImage image = QImage(":/Flags/as.png");
    float angle = body->GetAngle();

//    printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

    //painter.drawImage((int)(position.x * 20), (int)(position.y*20), image);
    painter.drawImage(QRect(int(position.x),int(position.y * 20),500,150), image);
    //painter.drawImage(200, 200, image);
//    qDebug() << image;
    painter.end();
   }

void BasicQuiz::updateWorld() {
    // It is generally best to keep the time step and iterations fixed.
    world.Step(1.0/60.0, 6, 2);
    update();
}

BasicQuiz::~BasicQuiz()
{
    delete ui;
}
