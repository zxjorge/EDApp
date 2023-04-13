#include "start.h"
#include "ui_start.h"

/**
 */

/**
 * @brief Start::Start
 * @param parent
 */
Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
}

/**
 * @brief Start::~Start
 */
Start::~Start()
{
    delete ui;
}
