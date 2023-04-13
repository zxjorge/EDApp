#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    connect(ui->startButton,
            &QPushButton::clicked,
            this,
            &MainWindow::startButtonClicked);
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
void MainWindow::startButtonClicked(){
    ui->stackedWidget->setCurrentIndex(1); // switch to second page

}






