#include "basicquiz.h"
#include "ui_basicquiz.h"
#include <QRandomGenerator>

BasicQuiz::BasicQuiz(
    QString question,
    QVector<QString> correctFlags,
    QVector<QString> wrongFlags,
    QWidget *successScene,
    MainWindow *parent,
    int currentStreak,
    int targetStreak
) :
    QWidget(parent),
    ui(new Ui::BasicQuiz)
{
    ui->setupUi(this);
    ui->question->setText(question);
    successScene->hide();
    QRandomGenerator rng = QRandomGenerator::securelySeeded();

    auto onCorrect = [=] () mutable {
        currentStreak++;
        QWidget *tmp = successScene;
        successScene = nullptr;
        if (currentStreak >= targetStreak) {
            tmp->show();
            parent->switchScene(tmp);
        } else {
            parent->switchScene(
                new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, currentStreak, targetStreak)
                );
        }
    };
    auto onWrong = [=] () mutable {
        QWidget *tmp = successScene;
        successScene = nullptr;
        parent->switchScene(
            new BasicQuiz(question, correctFlags, wrongFlags, tmp, parent, 0, targetStreak)
        );
    };

    if (rng.bounded(2) == 0) {
        // flag1 is the right answer
        ui->flag1->setIcon(QIcon(":/Flags/" + correctFlags.at(rng.bounded(correctFlags.length()))));
        ui->flag2->setIcon(QIcon(":/Flags/" + wrongFlags.at(rng.bounded(wrongFlags.length()))));
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
        ui->flag1->setIcon(QIcon(":/Flags/" + wrongFlags.at(rng.bounded(wrongFlags.length()))));
        ui->flag2->setIcon(QIcon(":/Flags/" + correctFlags.at(rng.bounded(correctFlags.length()))));
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
}
