#include "saves.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QFileInfo>
#include <iostream>


const QString saveFilename = "Saves.data";


void Saves::Save(QString lessonToSave)
{
    if (savedLessonsArray.contains(lessonToSave)) {
        return;
    }
    // Get the root object of the JSON document
    QJsonObject json = QJsonObject();

    // Get the saved lessons array from the root object (if it exists)

    // Append the new lesson to the saved lessons array
    if(!savedLessonsArray.contains(lessonToSave))
        savedLessonsArray.append(lessonToSave);

    // Add the saved lessons array to the root object
    json["saved_lessons"] = savedLessonsArray;

    // Save the updated JSON document to the file
    QFile file(saveFilename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to write to save file!";
        return;
    }
    file.write(QJsonDocument(json).toJson());
    file.close();
}


void Saves::loadFromFile(){
    // Reads from file.
    QFile file(saveFilename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QJsonObject json;
    QTextStream stream( &file );
    json = QJsonDocument::fromJson(stream.readAll().toLocal8Bit()).object();
    if(json.count()!=1 || !json.keys().contains("saved_lessons")){
        qDebug() << "Error loading saved progress.";
        return;
    } else {
        savedLessonsArray = json["saved_lessons"].toArray();
    }
}

int Saves::getNumberOfLessonsSaved(){
    return savedLessonsArray.size();
}

const QJsonArray *Saves::getSavedLessonsArray() {
    return &savedLessonsArray;
}
