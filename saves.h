#ifndef SAVES_H
#define SAVES_H
#include "QtCore/qjsonarray.h"


class Saves
{
    QJsonArray savedLessonsArray;
public:
    void Save(QString lessonToSave);
    void loadFromFile();
    int getNumberOfLessonsSaved();


};

#endif // SAVES_H
