#ifndef MSACTIVITY_H
#define MSACTIVITY_H
#include <QWidget>
#include <QString>
#include "mainwindow.h"


namespace Ui {
class MSActivity;
}

class MSActivity : public QWidget
{
    Q_OBJECT

public:
    explicit MSActivity(MainWindow *parent = nullptr);
    ~MSActivity();

private:
    Ui::PromptToFlag *ui;
    MainWindow *mainWindow;
    QMap<int, QString> prompts;
};

#endif // MSACTIVITY_H
