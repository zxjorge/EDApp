
#ifndef USERNAME_H
#define USERNAME_H
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Username;
}

class Username : public QWidget
{
    Q_OBJECT

public:
    explicit Username(MainWindow *parent = nullptr);
    ~Username();

private slots:
    /**
     * Called when the Ok button is clicked
     */
    void nextClicked();

private:
    Ui::Username *ui;
    MainWindow *mainWindow;
    Saves saves;
};

#endif // USERNAME_H
