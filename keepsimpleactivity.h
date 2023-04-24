#ifndef KEEPSIMPLEACTIVITY_H
#define KEEPSIMPLEACTIVITY_H

#include "drawutils.h"
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class KeepSimpleActivity;
}

class KeepSimpleActivity : public QWidget
{
    Q_OBJECT

public:
    explicit KeepSimpleActivity(MainWindow *parent = nullptr);
    ~KeepSimpleActivity();

private:
    Ui::KeepSimpleActivity *ui;
    DrawUtils drawUtils;
    MainWindow *mainWindow;
};

#endif // KEEPSIMPLEACTIVITY_H
