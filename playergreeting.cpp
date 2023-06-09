/**
 * playergreeting.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses playergreeting.h header file and implements all its methods.
 * Reviewed by: Brayden Newsom
 */
#include "playergreeting.h"
#include "mainmenu.h"
#include "mainwindow.h"
#include "ui_playergreeting.h"
#include <qpixmap.h>
PlayerGreeting::PlayerGreeting(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::PlayerGreeting),
    mainWindow(parent)
{
    ui->setupUi(this);
    ui->imageLabel->setPixmap(QPixmap(":/vexbot/vexbotCheer.png"));
    ui->label->setText("Welcome " + mainWindow->getSaves()->getUsername() + " to the world of flags. My name is vexbot. I am a Vexillologist. I take it you're interested in flags?");
    connect(ui->pushButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MainMenu(mainWindow));
            });

}

PlayerGreeting::~PlayerGreeting()
{
    delete ui;
}

