#include "playergreeting.h"
#include "mainmenu.h"
#include "mainwindow.h"
#include "ui_playergreeting.h"

PlayerGreeting::PlayerGreeting(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::PlayerGreeting),
    mainWindow(parent)
{
    ui->setupUi(this);

    ui->label->setText("Welcome " + mainWindow->getSaves()->getUsername() + " to the world of flags. My name is vexbot. I am a Vexillologist. I take it you're interested in flags?");


    connect(ui->pushButton,
            &QPushButton::clicked,
            this,
            &PlayerGreeting::buttonClicked);

}

void PlayerGreeting::buttonClicked()
{
    mainWindow->switchScene(new MainMenu(mainWindow));
}

PlayerGreeting::~PlayerGreeting()
{
    delete ui;
}

