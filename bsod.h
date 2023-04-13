#ifndef BSOD_H
#define BSOD_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Bsod;
}

class Bsod : public QWidget
{
    Q_OBJECT

public:
    explicit Bsod(MainWindow *parent = nullptr);
    ~Bsod();

private slots:
    void onSceneEnd();

private:
    Ui::Bsod *ui;
    MainWindow *mainWindow;
};

#endif // BSOD_H
