#include "msactivity.h"
#include "ui_msactivity.h"

/**
 * @brief MSActivity::MSActivity
 * @param parent
 */
MSActivity::MSActivity(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::MSActivity),
    mainWindow(parent)
{
    ui->setupUi(this);
    prompts[0] = "This country just gained independence from the British, but it is still part of the Commonwealth.";
    prompts[1] = "This country has a majority Muslim population.";
    prompts[2] = "This country is in Africa, and the biggest ethnic group worships the stars.";
    prompts[3] = "TThe biggest import from this country is flowers, and they live right by the red sea.";
    prompts[4] = "The colors of this country are green for its lush forests and black for its black sand beaches.";
}

/**
 * @brief MSActivity::~MSActivity
 */
MSActivity::~MSActivity()
{
    delete ui;
}

/**
 * @brief MSActivity::FillScrollArea
 */
void MSActivity::FillScrollArea(){

}

