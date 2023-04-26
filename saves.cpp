/**
 * saves.cpp made by Najmingle for A7: Sprite Editor Implementation - CS 3505 Spring 2023
 * This cpp file uses saves.h header file and implements all its methods.
 * Reviewed by: Brayden Newsom
 */
#include "saves.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QFileInfo>
#include <iostream>


const QString saveFilename = "Saves.data";

void Saves::Save(QString lessonToSave, QString username)
{
    if (savedLessonsArray.contains(lessonToSave)) {
        return;
    }
    // Get the root object of the JSON document
    QJsonObject json = QJsonObject();

    this->username = username;
    // Add the saved lessons array to the root object
    json["username"] = username;


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
    // add back json.count()!=1
    /*if(json.keys().contains("saved_lessons")){
        qDebug() << "Error loading saved progress.";
        return;
    } else {
        username = json["username"].toString();
        savedLessonsArray = json["saved_lessons"].toArray();
    }
    */

    username = json["username"].toString();
    savedLessonsArray = json["saved_lessons"].toArray();
}

int Saves::getNumberOfLessonsSaved(){
    return savedLessonsArray.size();
}

void Saves::setUsername(QString name){
    username = name;
}

QString Saves::getUsername(){
    return username;
}

const QJsonArray *Saves::getSavedLessonsArray() {
    return &savedLessonsArray;
}
