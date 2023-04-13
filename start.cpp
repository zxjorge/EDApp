#include "start.h"
#include "ui_start.h"
#include <QStackedWidget>

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
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &Start::backClicked);
}

/**
 * @brief Start::~Start
 */
Start::~Start()
{
    delete ui;
}

/**
 * @brief Start::backClicked
 */
void Start::backClicked(){
    QStackedWidget *stackedWidget = qobject_cast<QStackedWidget*>(parentWidget());
    if (stackedWidget) {
        stackedWidget->setCurrentIndex(stackedWidget->currentIndex() - 1);
    }
}
