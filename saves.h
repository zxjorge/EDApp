#ifndef SAVES_H
#define SAVES_H
#include "QtCore/qjsonarray.h"


class Saves
{
private:
    QJsonArray savedLessonsArray;
public:
    void Save(QString lessonToSave);
    void loadFromFile();
    int getNumberOfLessonsSaved();
    const QJsonArray *getSavedLessonsArray();
};

#endif // SAVES_H
