#include "archivecheck.h"
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
#include <chrono>
#include <thread>
#include <QFileInfo>

ArchiveCheck::ArchiveCheck(QString directoryinput,Ui::MainWindow* ui,myTableModel* tableModel)
{
    directory=directoryinput;
    uiPointer=ui;
    tableModelPointer=tableModel;
}


bool fileExists(QString path) {
    QFileInfo check_file(path);
    // check if path exists and if yes: Is it really a file and no directory?
    return check_file.exists() && check_file.isFile();
}

QString ArchiveCheck::checkForArchive(int&totalErrorsOutput,int&filesAffectedOutput)
{
    tableModelPointer->resetTable();//Clear the tableData vector
    uiPointer->archiveErrorList->clear();
    int folderErrors=0;
    int totalErrors=0;
    int maxErrosForFile=0;
    std::vector<QString> errorData;
    FolderIO fIo;
    std::vector<std::string> foldersToCheck=fIo.get_directories(directory.toStdString());
    //std::cout<<foldersToCheck.size()<<std::endl;

    //Setup the file to write errors/missing files to
    std::string filePath = directory.toStdString() + "/errors.csv"; //Creates the file to be created at the file path
    const char *path = filePath.c_str(); //Encodes into char pointer
    std::ofstream outfile(path);		//Creates the file
    if(outfile.fail())
    {
        return false;
    }
    outfile<<"PO#,Missing files->"<<std::endl;

    uiPointer->archivePBar->setRange(0,foldersToCheck.size());
    int step=0;

    //Main loop that interates over the PO# files
    for(unsigned int i=0;i<foldersToCheck.size();i++)
    {   int errors=0;
        bool errorChecker=false;
        //Vector that will store the required files in a vector
        std::vector<std::string> filesReq=fIo.get_reqFiles(QString::fromStdString(foldersToCheck[i]),errorChecker);
        if(errorChecker)
        {
            std::cout<<"There is an error "<<std::endl;
            uiPointer->archiveErrorList->addItem(QString::fromStdString(foldersToCheck[i]));
            folderErrors++;
            step++;
        }
        else
        {
        //Gets the files(Folders) in a specific PO#file
        std::vector<std::string> filesReturn=fIo.list_files_vector(QString::fromStdString(foldersToCheck[i]));
        //Gets the folder to check
        QString po=QString::fromStdString(foldersToCheck[i]);
        errorData.clear(); //Clear the vector
        po.remove(0,directory.length()+1);
        errorData.push_back(po); //Add the po# to the vector, this vector is sent to the table model
        step++;//Increase step for progress bar
        uiPointer->archivePBar->setValue(step);//Sets the progress bar



       QString missingFiles;//QString of the missing files, will be written to the csv file
        for(unsigned int z=0; z<filesReq.size();z++)
        {
            if(fIo.doesFileExist(QString::fromStdString(filesReq[z]),filesReturn)==0)
            {
                missingFiles.push_back(QString::fromStdString(filesReq[z])+",");
                errorData.push_back(QString::fromStdString(filesReq[z]));

                totalErrors++;
                errors++;
            }

        }
        if(errors>maxErrosForFile)
            maxErrosForFile=errors;

       //directory.replace("/","\\");


       //std::cout<<"The directory: "<<directory.toStdString()<<std::endl;
        outfile<<po.toStdString()+","+missingFiles.toStdString()<<std::endl; //Writes the list to the file
        if(totalErrors>0)
            folderErrors++;
        tableModelPointer->setColumnCount(maxErrosForFile);
        tableModelPointer->addCheckData(errorData); //Adds the missing files to the

        //Sleep(10);
        }
    }
    //std::cout<<"Total Errors:"<<totalErrors<<std::endl;

    outfile.close();
    filesAffectedOutput=folderErrors;
    totalErrorsOutput=totalErrors;
    uiPointer->ACheck_TotalFilesChecked->setText(QString::number(foldersToCheck.size()));


    return "Archive check complete, " +QString::number(totalErrors)+" total errors in "+QString::number(folderErrors)+" files.";

}
