#include "FlagWidget.h"
#include <QPainter>

FlagWidget::FlagWidget(QWidget *parent) : QWidget(parent), m_world(nullptr), m_flagBody(nullptr)
{
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

}

void FlagWidget::setFlagImage(const QPixmap &pixmap)
{
    m_flagPixmap = pixmap;
}

void FlagWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    painter.drawPixmap(rect(), m_flagPixmap);

    // trying to use box2d here to color/paint the area
    if (m_world != nullptr && m_flagBody != nullptr) {
        b2Vec2 position = m_flagBody->GetPosition();
        float32 angle = m_flagBody->GetAngle();
        QTransform transform;
        transform.translate(position.x, -position.y);
        transform.rotateRadians(-angle);
        painter.setTransform(transform);
        painter.drawPixmap(QRectF(-10, -10, 20, 20), m_flagPixmap, m_flagPixmap.rect());
    }
}

void FlagWidget::animateFlag()
{
    b2Vec2 gravity(0.0f, -9.81f);
    m_world = new b2World(gravity);

    // static ground body - needed to do animation
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = m_world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // dynamic body
    b2BodyDef flagBodyDef;
    flagBodyDef.type = b2_dynamicBody;
    flagBodyDef.position.Set(0.0f, 0.0f);
    m_flagBody = m_world->CreateBody(&flagBodyDef);
    b2PolygonShape flagBox;
    flagBox.SetAsBox(1.0f, 1.0f);
    m_flagBody->CreateFixture(&flagBox, 1.0f);


    b2Vec2 force(50.0f, 0.0f);
    b2Vec2 point(0.0f, 0.0f);
    m_flagBody->ApplyForce(force, point, true);
}


