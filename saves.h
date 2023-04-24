#ifndef SAVES_H
#define SAVES_H
#include "QtCore/qjsonarray.h"
#include "QtCore/qstring.h"

class Saves
{
    static QJsonArray savedLessonsArray;
public:
    static void Save(QString, QString);
    static void loadFromFile(QString);
    static int getNumberOfLessonsSaved();


};

#endif // SAVES_H
