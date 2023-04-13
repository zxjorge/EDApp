#include "definition.h"
#include "ui_definition.h"

Definition::Definition(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Definition),
    mainWindow(parent)
{
    ui->setupUi(this);
}

Definition::~Definition()
{
    delete ui;
}
