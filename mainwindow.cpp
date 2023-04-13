#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "title.h"
#include "box2d/include/box2d/b2_math.h"
/**
 *
 *
 */

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(new Title(this));
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::startButtonClicked
 */
void MainWindow::switchScene(QWidget *nextScene) {
    setCentralWidget(nextScene);
}






