#include "mainwindow.h"
#include "saves.h"
#include "ui_mainwindow.h"
#include "title.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    saves.loadFromFile();
    setWindowTitle("How to be a VEXPERT!");
    setCentralWidget(new Title(this));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::switchScene(QWidget *nextScene) {
    setCentralWidget(nextScene);
}

Saves* MainWindow::getSaves() {
    return &saves;
}
