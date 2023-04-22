#include "saves.h"
#include "QtCore/qmetatype.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QFileInfo>
#include <iostream>

void Saves::Save(QString lessonToSave,QString filename )
{

        // Load the JSON document from a file (if it already exists)
        QFile file(filename);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();

        // Get the root object of the JSON document
        QJsonObject json = doc.object();


        // Get the saved lessons array from the root object (if it exists)
        QJsonArray savedLessonsArray;
        if (json.contains("saved_lessons") && json["saved_lessons"].isArray()) {
            savedLessonsArray = json["saved_lessons"].toArray();
        }

        // Append the new lesson to the saved lessons array
        if(!savedLessonsArray.contains(lessonToSave))
            savedLessonsArray.append(lessonToSave);

        // Add the saved lessons array to the root object
        json["saved_lessons"] = savedLessonsArray;

        // Save the updated JSON document to the file
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.write(QJsonDocument(json).toJson());
        file.close();

}

int Saves::loadFromFile(QString filename){
    // Reads from file.
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file!";
        // Handle the error, for example by showing an error message to the user
        return 0;
    }
    QJsonObject json;
    QTextStream stream( &file );
    json = QJsonDocument::fromJson(stream.readAll().toLocal8Bit()).object();
    if(json.count()!=1 || !json.keys().contains("saved_lessons")){
        qDebug() << "Error loading saved progress.";
          return 0;
      }
    else{
        return json["saved_lessons"].toArray().size();
    }
}


