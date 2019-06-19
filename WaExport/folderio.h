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
    bool checkForDirect(QString directory);
};

#endif // FOLDERIO_H
