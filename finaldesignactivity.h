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
