#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QPushButton>
#include "bedistinctiveorrelatedlesson.h"
#include "keepsimplelesson.h"
#include "meaningfulsymbolismlesson.h"
#include "noletteringorsealslesson.h"
#include "usebasiccolorslesson.h"
#include <QDebug>


/**
 * @brief MainMenu::MainMenu
 * @param parent
 */
MainMenu::MainMenu(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    mainWindow(parent)
{
    ui->setupUi(this);

    connect(ui->BDRButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new BeDistinctiveOrRelatedLesson(mainWindow));
            });

    connect(ui->KISButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new KeepSimpleLesson(mainWindow));
            });

    connect(ui->U23Button,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new UseBasicColorsLesson(mainWindow));
            });

    connect(ui->UMSButton,
            &QPushButton::clicked,
            this,
            [this] {
                mainWindow->switchScene(new MeaningfulSymbolismLesson(mainWindow));
            });
}

/**
 * @brief MainMenu::~MainMenu
 */
MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::SwitchToMainMenu(){
    mainWindow->switchScene(this);
}
