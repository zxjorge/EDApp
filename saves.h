#ifndef SAVES_H
#define SAVES_H
#include "QtCore/qjsonarray.h"
#include "QtCore/qstring.h"

class Saves
{
public:
    static void Save(QString, QString);
    static int loadFromFile(QString filename);

private:

};

#endif // SAVES_H
