#include "title.h"
#include "ui_title.h"
#include <QPushButton>
#include "definition.h"

Title::Title(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Title),
    mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->pushButton,
            &QPushButton::pressed,
            this,
            &Title::onButtonpressed);
}
void Title::onButtonpressed() {
    mainWindow->switchScene(new Definition(mainWindow));
}

Title::~Title()
{
    delete ui;
}
