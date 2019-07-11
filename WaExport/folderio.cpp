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

FolderIO::FolderIO()
{

}

//Copies a file from one directory to another and changes the name
void FolderIO::copyFile(QString source, QString destination, QString destinationName)
{

    //Copies a file and keeps the source file extension
    QString extension=source.mid(source.lastIndexOf('.'),source.length()-source.lastIndexOf('.'));
    std::cout<<"The extension is: "+extension.toStdString()<<std::endl;
    QFile::copy(source, destination+"/"+destinationName+extension);//This copies the file with the new destination name
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

std::vector<std::string> FolderIO::get_directories(const std::string& mainDirec)
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
    //std::cout<<"Entering direct check main Direct:"<<mainDirectory.toStdString()<<std::endl;
    std::vector<std::string> path=get_directories(mainDirectory.toStdString());
    for (auto i = path.begin(); i != path.end(); ++i)
    {

        QString checkDirec= mainDirectory+'\\'+directory;
        checkDirec.replace("/","\\");
        //std::cout << *i << ' '<<checkDirec.toStdString()<<std::endl;
        if((*i)==checkDirec.toStdString().c_str())
            return true;
    }
    return false;
}


bool FolderIO::createIndexFile(QString destDirec,QString poNum, QString customer,QString notes,std::ostringstream requiredFiles)
{

   /*Creates the index file that is used for checking/ indexinf of the folder
    *Inputs:
    *   destDirec-The directory will the index file will be created
    *   poNum- The PO# of the file
    *   customer-The customer of the order/file
    *Ouputs:
    *   bool- True if the file was created sucessfully
    */
    std::string filePath = destDirec.toStdString() + "/waex.index"; //Creates the file to be created at the file path
    const char *path = filePath.c_str(); //Encodes into char pointer
    std::ofstream outfile(path);		//Creates the file
    if(outfile.fail())
    {
        return false;
    }

    //Write what you want to the file
    outfile << "This is an index file for WAEX filing system.\nThis file should not be edited directely by the user." << std::endl<<std::endl;
    outfile << "PO#:"+poNum.toStdString() << std::endl;
    //outfile << "Customer:"+customer.toStdString() << std::endl;

    //Output the files that are required based on what is checked
    //This will be a list of the names of the files
    //outfile<<"/REQSTART/"<<std::endl;
    outfile<<requiredFiles.str();
    //outfile<<"/REQEND/"<<std::endl;

    //outfile << "Date created:*"+QDate::currentDate().toString() << std::endl;
    outfile<<list_files(destDirec+"/").str();
    //std::cout<< list_files(destDirec+"/").str();
    outfile<<std::endl<<"Notes:"<<notes.toStdString()<<std::endl;



    //Close the file
    outfile.close();
    return true;
}

int FolderIO::doesFileExist(QString fileToCheck,std::vector<std::string> filesVec)
{
    /*Checks if a fileToChekc exists in checkDirec
     *Inputs:
     *  QString checkDirec-the directory to check in
     *  QString fileToChekc-the file to check for
     *Outputs:
     *  int:0 if the file does not exist, or returns the number of files
     */
    int count=0;
    for (auto i = filesVec.begin(); i != filesVec.end(); ++i)
    {

        if((*i).substr(0,fileToCheck.length())==fileToCheck.toStdString().c_str())
            count+=1;
    }
    return count;
}

QString FolderIO::getNotes(QString directory)
{   //Returs a QString of the notes from the WAEX.index file
    QFile file(directory);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return "";
        QByteArray indexFile= file.readAll();
       // std::cout <<"NOTES SECTION:"+indexFile.toStdString()<<std::endl;
        QString fileString =QString::fromStdString(indexFile.toStdString());
        int found= fileString.indexOf("Notes:");
        return fileString.mid(found+6,fileString.length());
}

QString FolderIO::getTemplate(QString directory)
{

    QFile file(directory);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return "";
       QByteArray indexFile= file.readAll();
      // std::cout <<"NOTES SECTION:"+indexFile.toStdString()<<std::endl;
       QString fileString =QString::fromStdString(indexFile.toStdString());
       int found= fileString.indexOf("Template:");
       return fileString.mid(found+9,fileString.indexOf("/TEND")-(found+9));
}

std::vector<std::string> FolderIO::get_reqFiles(QString mainDirec)
{
    std::vector<std::string> requiredFiles;
    QFile file(mainDirec+"/waex.index");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
          std::cout<<"Errro opening file"<<std::endl;
//       while(file.readLine()!="/REQSTART/")
//           std::cout<<"Next"<<std::endl;

        QTextStream in(&file);
       in.readLine();
       in.readLine();
       in.readLine();
       in.readLine();
       in.readLine();
       in.readLine();

       QString temp;

           while(!in.atEnd())
           {
               temp =in.readLine();
               if(temp.toStdString()=="/REQEND/")
               {
                   //std::cout<<"Return Section"<<std::endl;
                   return requiredFiles;
               }

               else
               {
                   //std::cout<<temp.toStdString()<<std::endl;
                   requiredFiles.push_back(temp.toStdString());
               }
           }
        std::cout<<"End Required Files"<<std::endl;
}

bool FolderIO::createLink(QString source, QString destination)
{
 destination=destination+"-Shortcut.lnk";
 return QFile:: link ( source, destination );
}


