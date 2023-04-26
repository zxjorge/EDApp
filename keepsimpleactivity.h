/**
 * keepsimpleactivity.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by keepsimpleactivity.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the keep simple activity
 * Reviewed by: George Benyeogor
 */
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
    QImage selectedSymbol;

    /**
     * @brief setSelectedSymbol sets the selected symbol and updates the cursor
     * @param path path to the symbol
     */
    void setSelectedSymbol(QString path);

    void resizeEvent(QResizeEvent *event) override;

    /**
     * @brief updateCursor updates the cursor
     */
    void updateCursor();
};

#endif // KEEPSIMPLEACTIVITY_H
