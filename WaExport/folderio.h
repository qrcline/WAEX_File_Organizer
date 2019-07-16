#ifndef FOLDERIO_H
#define FOLDERIO_H
#include "filesystem"


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Windows.h>
#include <shellapi.h>
#include "string"
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>



class FolderIO
{
public:
    FolderIO();
    void copyFile(QString source, QString destination, QString destinationName);
    void createDirectory(QString directory);
    bool checkForDirect(QString mainDirectory, QString directory);
    bool createIndexFile(QString destDirec,QString poNum, QString customer,QString notes,std::ostringstream requiredFiles);
    int doesFileExist(QString filetToCheck,std::vector<std::string> filesVec );
    std::ostringstream list_files(QString path);
    std::vector<std::string> list_files_vector(QString path);
    QString getNotes(QString directory);
    QString getTemplate(QString directory);
    std::vector<std::string> get_directories(const std::string &mainDirec);
    std::vector<std::string> get_reqFiles(QString mainDirec, bool& error);
    bool createLink(QString source, QString destination);
};

#endif // FOLDERIO_H
