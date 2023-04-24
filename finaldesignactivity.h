/**
 * finaldesignactivity.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by finaldesignactivity.cpp and has methods, signals, and slots to handle
 * This class handles the UI aspects, logic, and data for the final flag design activity
 * Reviewed by: Najman Activity
 */
#ifndef FINALDESIGNACTIVITY_H
#define FINALDESIGNACTIVITY_H

#include "drawutils.h"
#include <QWidget>

namespace Ui {
class FinalDesignActivity;
}

class FinalDesignActivity : public QWidget
{
    Q_OBJECT

public:
    explicit FinalDesignActivity(QWidget *parent = nullptr);
    ~FinalDesignActivity();

private:
    Ui::FinalDesignActivity *ui;
    DrawUtils drawUtils;
};

#endif // FINALDESIGNACTIVITY_H
