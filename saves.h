/**
 * saves.h made by NajMingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This header file will be used by title.cpp and has methods, to handle saving and loading user progress.
 * Reviewed by: Brayden Newsom
 */
#ifndef SAVES_H
#define SAVES_H
#include "QtCore/qjsonarray.h"

class Saves
{
private:
    /**
     * @brief savedLessonsArray QJsonArray that stores saved lessons.
     */
    QJsonArray savedLessonsArray;\
    QString username = "";

public:
    /**
     * @brief Saves::Save Adds the completed lesson to the QJsonArray of already completed lessons
     * @param lessonToSave lesson that has been completed and is ready to save
     */
    void Save(QString lessonToSave);

    /**
     * @brief Saves::loadFromFile Reads the saved file and stores all savedLessons into the savedLessonsArray
     */
    void loadFromFile();

    /**
     * @brief getNumberOfLessonsSaved gets the number of lessons that have been completed
     * @return int number of saved lessons
     */
    int getNumberOfLessonsSaved();

    void savePlayerName(QString username);

    QString getUsername();

    /**
     * @brief Saves::getSavedLessonsArray Returns the array of saved lessons
     * @return QJsonArray of savedLessons
     */
    const QJsonArray *getSavedLessonsArray();


};

#endif // SAVES_H
