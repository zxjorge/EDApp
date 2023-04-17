#include "definition.h"
#include "ui_definition.h"
#include "bsod.h"

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
}

Definition::~Definition()
{
    delete ui;
}
