#include "basicquiz.h"
#include "ui_basicquiz.h"
#include <QRandomGenerator>

BasicQuiz::BasicQuiz(
    QString question,
    QVector<QString> correctFlags,
    QVector<QString> wrongFlags,
    QWidget *successScene,
    int currentStreak,
    int targetStreak,
    MainWindow *parent
) :
    QWidget(parent),
    ui(new Ui::BasicQuiz),
    successScene(successScene)
{
    ui->setupUi(this);
    ui->question->setText(question);
    QRandomGenerator rng;

    auto onCorrect = [=] () mutable {
        currentStreak++;
        QWidget *tmp = successScene;
        successScene = nullptr;
        if (currentStreak >= targetStreak) {
            parent->switchScene(tmp);
        } else {
            parent->switchScene(
                new BasicQuiz(question, correctFlags, wrongFlags, tmp, currentStreak, targetStreak, parent)
                );
        }
    };
    auto onWrong = [=] () mutable {
        QWidget *tmp = successScene;
        successScene = nullptr;
        parent->switchScene(
            new BasicQuiz(question, correctFlags, wrongFlags, tmp, 0, targetStreak, parent)
        );
    };

    if (rng.bounded(1) == 0) {
        // flag1 is the right answer
        ui->flag1->setIcon(QIcon(":/" + correctFlags.at(rng.bounded(correctFlags.length()))));
        ui->flag2->setIcon(QIcon(":/" + wrongFlags.at(rng.bounded(wrongFlags.length()))));
        connect(ui->flag1,
                &QPushButton::clicked,
                this,
                onCorrect);
        connect(ui->flag2,
                &QPushButton::clicked,
                this,
                onWrong);
    } else {
        // flag2 is the right answer
        ui->flag1->setIcon(QIcon(":/" + wrongFlags.at(rng.bounded(wrongFlags.length()))));
        ui->flag2->setIcon(QIcon(":/" + correctFlags.at(rng.bounded(correctFlags.length()))));
        connect(ui->flag1,
                &QPushButton::clicked,
                this,
                onWrong);
        connect(ui->flag2,
                &QPushButton::clicked,
                this,
                onCorrect);
    }
}

BasicQuiz::~BasicQuiz()
{
    delete ui;
    if (successScene) {
        delete successScene;
    }
}
