/**
 * username.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses username.h header file and implements all its methods.
 * Reviewed by: Sahil Karki
 */
#include "playergreeting.h"
#include "ui_username.h"
#include "username.h"
Username::Username(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Username),
    mainWindow(parent)
{
    ui->setupUi(this);

    connect(ui->pushButton,
            &QPushButton::clicked,
            this,
            &Username::doneClicked);

}

void Username::doneClicked()
{
    mainWindow->getSaves()->setUsername(ui->lineEdit->text());
    mainWindow->switchScene(new PlayerGreeting(mainWindow));

}

Username::~Username()
{
    delete ui;
}
