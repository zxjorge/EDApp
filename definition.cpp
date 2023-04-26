/**
 * Definition.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file uses Definition.h header file and implements all its methods.
 * Reviewed by: Brayden Newsom
 */
#include "definition.h"
#include "playergreeting.h"
#include "ui_definition.h"
#include "bsod.h"
#include <QPushButton>
#include "mainmenu.h"
#include "username.h"

Definition::Definition(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Definition),
    mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->no,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new Bsod(mainWindow));
            });

    connect(ui->ok,
            &QPushButton::clicked,
            this,
            &Definition::OkClicked);
}

Definition::~Definition()
{
    delete ui;
}

void Definition::OkClicked()
{
    if(mainWindow->getSaves()->getUsername() != "")
        mainWindow->switchScene(new PlayerGreeting(mainWindow));
    else{
        mainWindow->switchScene(new Username(mainWindow));
    }
}

