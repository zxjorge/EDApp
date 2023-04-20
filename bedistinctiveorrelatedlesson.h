#ifndef BEDISTINCTIVEORRELATEDLESSON_H
#define BEDISTINCTIVEORRELATEDLESSON_H
#include "mainmenu.h"
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QAudioOutput>


namespace Ui {
class BeDistinctiveOrRelatedLesson;
}

class BeDistinctiveOrRelatedLesson : public QStackedWidget
{
    Q_OBJECT

public:
    explicit BeDistinctiveOrRelatedLesson(MainWindow *parent = nullptr);
    ~BeDistinctiveOrRelatedLesson();

private slots:
    void NextClicked();
    void BackClicked();
    void Speak1Clicked();
    void Speak2Clicked();



private:
    Ui::BeDistinctiveOrRelatedLesson *ui;
    MainWindow *mainWindow;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;


};

#endif // BEDISTINCTIVEORRELATEDLESSON_H
