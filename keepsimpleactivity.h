#ifndef KEEPSIMPLEACTIVITY_H
#define KEEPSIMPLEACTIVITY_H

#include "drawutils.h"
#include <QWidget>

namespace Ui {
class KeepSimpleActivity;
}

class KeepSimpleActivity : public QWidget
{
    Q_OBJECT

public:
    explicit KeepSimpleActivity(QWidget *parent = nullptr);
    ~KeepSimpleActivity();

private:
    Ui::KeepSimpleActivity *ui;
    DrawUtils drawUtils;
};

#endif // KEEPSIMPLEACTIVITY_H
