#include "folderio.h"
#include "mainwindow.h"
#include <direct.h>
#include <fstream>
#include <windows.h>

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
    if (_mkdir(reinterpret_cast<const CHAR*>(directory.utf16())) != 0)
    {
        std::cout << "Make Directory fail" << std::endl;
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

bool FolderIO::checkForDirect(QString directory)
{
    MainWindow mainwindow;
    std::vector<std::string> path=get_directories(mainwindow.getMainDirectory().toStdString());
           for (auto i = path.begin(); i != path.end(); ++i)
           {
               std::cout << *i << ' '<<std::endl;
               if((*i)==directory.toStdString())
                   return true;
           }
           return false;
}


