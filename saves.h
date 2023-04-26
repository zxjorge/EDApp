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
    QJsonArray savedLessonsArray;

    /**
     * @brief username QString that is the players username
     */
    QString username = "";

public:
    /**
     * @brief Saves::Save Adds the completed lesson to the QJsonArray of already completed lessons
     * @param lessonToSave lesson that has been completed and is ready to save
     */
    void Save(QString lessonToSave, QString username);

    /**
     * @brief Saves::loadFromFile Reads the saved file and stores all savedLessons into the savedLessonsArray
     */
    void loadFromFile();

    /**
     * @brief Saves::getNumberOfLessonsSaved Gets the number of lessons that have been completed
     * @return int number of saved lessons
     */
    int getNumberOfLessonsSaved();

    /**
     * @brief Saves::getUsername Gets the players username
     * @return the player username
     */
    QString getUsername();

    /**
     * @brief Saves::setUsername Sets the given username to the username member variable
     * @param username players username
     */
    void setUsername(QString username);

    /**
     * @brief Saves::getSavedLessonsArray Returns the array of saved lessons
     * @return QJsonArray of savedLessons
     */
    const QJsonArray *getSavedLessonsArray();


};

#endif // SAVES_H
