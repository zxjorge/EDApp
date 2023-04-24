#ifndef SAVES_H
#define SAVES_H
#include "QtCore/qjsonarray.h"


class Saves
{
    QJsonArray savedLessonsArray;
public:
    void Save(QString, QString);
    void loadFromFile(QString);
    int getNumberOfLessonsSaved();


};

static Saves saves = Saves();

#endif // SAVES_H
