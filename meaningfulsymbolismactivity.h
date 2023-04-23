#ifndef MEANINGFULSYMBOLISMACTIVITY_H
#define MEANINGFULSYMBOLISMACTIVITY_H
#include "mainwindow.h"
#include <QWidget>
#include <QMap>
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
    QMap<int, QString> prompts;
    void FillScrollArea();

};

#endif // MEANINGFULSYMBOLISMACTIVITY_H
