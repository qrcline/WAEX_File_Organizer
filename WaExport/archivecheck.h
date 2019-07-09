#ifndef ARCHIVECHECK_H
#define ARCHIVECHECK_H

#include "folderio.h"
#include "folderio.h"
#include "mainwindow.h"
#include <direct.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <QDateTime>
#include <dirent.h>
#include <sys/types.h>
#include <sstream>
#include <QFile>
#include <QTextCodec>

class ArchiveCheck
{
public:
    ArchiveCheck(QString directory,Ui::MainWindow* ui,myTableModel* tableModel);


public slots:
    QString checkForArchive(int&totalErrors,int&filesAffected);
private:
    QString directory=nullptr;
    Ui::MainWindow* uiPointer;
    myTableModel* tableModelPointer;


protected:
};

#endif // ARCHIVECHECK_H
