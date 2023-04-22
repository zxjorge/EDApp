#ifndef MSACTIVITY_H
#define MSACTIVITY_H
#include "mainwindow.h"
#include <QWidget>
#include <QMap>
#include <QString>

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
    Ui::MSActivity *ui;
    MainWindow *mainWindow;
    QMap<int, QString> prompts;
    void FillScrollArea();

};

#endif // MSACTIVITY_H
