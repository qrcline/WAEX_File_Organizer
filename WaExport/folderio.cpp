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
    if (_mkdir(directory.toStdString().c_str()) != 0)
    {
        std::cout << "Make Directory fail" << std::endl;
    }
    else
    {
        std::cout<<"Directory created sucessfully."<<std::endl;
    }
}

std::vector<std::string> get_directories(const std::string& mainDirec)
{
    //Returns a vector of all the directories in the mainDirec
    //Input: mainDirec- the directory to search in
    //Ouput: string vector-includes the directories in the mainDirec
    std::vector<std::string> r;
    for (auto& p : std::experimental::filesystem::recursive_directory_iterator(mainDirec))
        if (p.status().type() == std::experimental::filesystem::file_type::directory)
            r.push_back(p.path().string());
    return r;
}


std::ostringstream FolderIO::list_files(QString path) {

    //Lists all files in a given directory
    //Input: path-the directory/folder
    //Ouput: ostringstream- stringstream of the files all on new lines
    struct dirent *entry;
    DIR *dir = opendir(path.toStdString().c_str());

    if (dir == nullptr) {
        //return std::nullptr_t;
    }
    std::ostringstream files;
    files<<"Files in directory: "<<std::endl;
    while ((entry = readdir(dir)) != nullptr) {
        files<< entry->d_name << std::endl;
    }
    closedir(dir);
    //std::cout<<files;
    return files;
}

////////////////
std::vector<std::string> FolderIO::list_files_vector(QString path) {

    //Lists all files in a given directory
    //Input: path-the directory/folder
    //Ouput: ostringstream- stringstream of the files all on new lines
    struct dirent *entry;
    DIR *dir = opendir(path.toStdString().c_str());

    if (dir == nullptr) {
        //return std::nullptr_t;
    }
      std::vector<std::string> filesReturn;
    while ((entry = readdir(dir)) != nullptr) {
        filesReturn.push_back(entry->d_name);
        //files<< entry->d_name << std::endl;
    }
    closedir(dir);
    //std::cout<<files;
    return filesReturn;
}



bool FolderIO::checkForDirect(QString mainDirectory,QString directory)
{
    //Chekcs if a specified directory exists in the mainDirectory
    //Input: directory-The directory to check for, mainDirectory-The directory to check in
    //Output: bool-True if the directroy exists in the mainDirectory

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


bool FolderIO::createIndexFile(QString destDirec,QString poNum, QString customer,QString notes)
{

   /*Creates the index file that is used for checking/ indexinf of the folder
    *Inputs:
    *   destDirec-The directory will the index file will be created
    *   poNum- The PO# of the file
    *   customer-The customer of the order/file
    *Ouputs:
    *   bool- True if the file was created sucessfully
    */
    std::string filePath = destDirec.toStdString() + "/"+poNum.toStdString()+".waex.index"; //Creates the file to be created at the file path
    const char *path = filePath.c_str(); //Encodes into char pointer
    std::ofstream outfile(path);		//Creates the file
    if(outfile.fail())
    {
        return false;
    }

    //Write what you want to the file
    outfile << "This is an index file for WAEX filing system.\nThis file should not be edited directely by the user." << std::endl;
    outfile << "PO#:*"+poNum.toStdString() << std::endl;
    outfile << "Customer:*"+customer.toStdString() << std::endl;
    //outfile << "Date created:*"+QDate::currentDate(dd.MM.yyyy).toString() << std::endl;
    outfile<<list_files(destDirec+"/").str();
    outfile<<"Notes: "<<std::endl;
    outfile<<notes.toStdString()<<std::endl;



    //Close the file
    outfile.close();
    return true;
}

bool FolderIO::doesFileExist(QString fileToCheck,std::vector<std::string> filesVec)
{
    /*Checks if a fileToChekc exists in checkDirec
     *Inputs:
     *  QString checkDirec-the directory to check in
     *  QString fileToChekc-the file to check for
     *Outputs:
     *  bool:True if the file exists in the directory
     */

    for (auto i = filesVec.begin(); i != filesVec.end(); ++i)
    {

        if((*i)==fileToCheck.toStdString().c_str())
            return true;
    }
    return false;
}


