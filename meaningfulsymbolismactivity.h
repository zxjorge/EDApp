#ifndef MEANINGFULSYMBOLISMACTIVITY_H
#define MEANINGFULSYMBOLISMACTIVITY_H
#include "mainwindow.h"
#include <QWidget>
#include <QVector>
#include <QString>

namespace Ui {
class MeaningfulSymbolismActivity;
}

class MeaningfulSymbolismActivity : public QWidget
{
    Q_OBJECT

public:
    explicit MeaningfulSymbolismActivity(MainWindow *parent = nullptr);
    ~MeaningfulSymbolismActivity();

private:
    Ui::MeaningfulSymbolismActivity *ui;
    MainWindow *mainWindow;
    QVector<QString> prompts;
    QVector<QString> correctAnswers;
    int numbers[15];
    int currentIndex;
    void DisplayPrompt();
};

#endif // MEANINGFULSYMBOLISMACTIVITY_H
