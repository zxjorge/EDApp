#include "definition.h"
#include "ui_definition.h"
#include "bsod.h"
#include <QPushButton>
#include "mainmenu.h"

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
    mainWindow->switchScene(new MainMenu(mainWindow));
}

