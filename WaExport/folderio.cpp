#include "folderio.h"
#include "mainwindow.h"
#include <direct.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <QDateTime>

FolderIO::FolderIO()
{

}

//Copies a file from one directory to another and changes the name
void FolderIO::copyFile(QString source, QString destination, QString destinationName)
{
    QFile::copy(source, destination+"/"+destinationName);//This copies the file with the new destination name

}

void FolderIO::createDirectory(QString directory)
{
    directory.replace("/","\\");
    //std::cout<<"Directory to be created: "<<directory.toStdString().c_str()<<std::endl;
    if (_mkdir(directory.toStdString().c_str()) != 0)
    {
        std::cout << "Make Directory fail" << std::endl;
    }
    else {
        {
            std::cout<<"Directory created sucessfully."<<std::endl;
        }
    }
}

std::vector<std::string> get_directories(const std::string& s)
{
    std::vector<std::string> r;
    for (auto& p : std::experimental::filesystem::recursive_directory_iterator(s))
        if (p.status().type() == std::experimental::filesystem::file_type::directory)
            r.push_back(p.path().string());
    return r;
}

bool FolderIO::checkForDirect(QString mainDirectory,QString directory)
{
    MainWindow mainwindow;
    std::cout<<"Entering direct check main Direct:"<<mainDirectory.toStdString()<<std::endl;
    std::vector<std::string> path=get_directories(mainDirectory.toStdString());
    for (auto i = path.begin(); i != path.end(); ++i)
    {

        QString checkDirec= mainDirectory+'\\'+directory;
        checkDirec.replace("/","\\");
        std::cout << *i << ' '<<checkDirec.toStdString()<<std::endl;
        if((*i)==checkDirec.toStdString().c_str())
            return true;
    }
    return false;
}

bool createIndexFile(QString destDirec,QString poNum, QString customer)
{

    //Creates the template File
    std::string filePath = destDirec.toStdString() + "/index.waex.index"; //Creates the file to be created at the file path
    const char *path = filePath.c_str(); //Encodes into char pointer
    std::ofstream outfile(path);		//Creates the file
    if(outfile.fail())
    {
        return false;
    }

    //Write what you want to the file
    outfile << "PO#:*"+poNum.toStdString() << std::endl;
    outfile << "Customer:*"+customer.toStdString() << std::endl;
    //outfile << "Date created:*"+QDate::currentDate(dd.MM.yyyy).toString() << std::endl;

    /*
    //Find the files in the directory and list in the index file
    MainWindow mainwindow;
    std::vector<std::string> path=get_directories(destDirec.toStdString());
    for (auto i = path.begin(); i != path.end(); ++i)
    {

        QString checkDirec= mainDirectory+'\\'+directory;
        checkDirec.replace("/","\\");
        std::cout << *i << ' '<<checkDirec.toStdString()<<std::endl;
        if((*i)==checkDirec.toStdString().c_str())
            return true;
    }

    */

    //Close the file
    outfile.close();
    return true;
}


