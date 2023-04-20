#ifndef PROMPTTOFLAG_H
#define PROMPTTOFLAG_H
#include <QWidget>
#include <QString>
#include "mainwindow.h"


namespace Ui {
class PromptToFlag;
}

class PromptToFlag : public QWidget
{
    Q_OBJECT

public:
    explicit PromptToFlag(MainWindow *parent = nullptr);
    ~PromptToFlag();

private:
    Ui::PromptToFlag *ui;
    MainWindow *mainWindow;
    QMap<int, QString> prompts;
};

#endif // PROMPTTOFLAG_H
