#include "playergreeting.h"
#include "ui_username.h"
#include "username.h"
#include "mainmenu.h"
Username::Username(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Username),
    mainWindow(parent)
{
    ui->setupUi(this);

    connect(ui->pushButton,
            &QPushButton::clicked,
            this,
            &Username::nextClicked);

}

void Username::nextClicked()
{
    mainWindow->getSaves()->savePlayerName(ui->lineEdit->text());
    mainWindow->switchScene(new PlayerGreeting(mainWindow));

}

Username::~Username()
{
    delete ui;
}
