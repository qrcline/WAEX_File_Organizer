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

ArchiveCheck::ArchiveCheck(QString directoryinput,Ui::MainWindow* ui)
{
   directory=directoryinput;
   uiPointer=ui;
}


QString ArchiveCheck::checkForArchive()
{
    FolderIO fIo;
      std::vector<std::string> foldersToCheck=fIo.get_directories(directory.toStdString());
      std::cout<<foldersToCheck.size()<<std::endl;


//       for(int i=0; i<=100;i+=5)
//       {
//            uiPointer->archivePBar->setValue(i);
//            Sleep(100);
//       }

        auto temp=foldersToCheck.size();
        float step =100/temp;
        std::cout<<"The step is: "<<step<<std::endl;

      //Main loop that interates over the PO# files
      for(unsigned int i=0;i<foldersToCheck.size();i++)
      {
          std::cout<<foldersToCheck[i]<<std::endl ;
          step+=step;
          uiPointer->archivePBar->setValue(step);
          fIo.get_reqFiles(QString::fromStdString(foldersToCheck[i]));
          //Gets the files in a specific PO#file
//          std::vector<std::string> filesReturn=fIo.list_files_vector((directory+"/"+QString::fromStdString(foldersToCheck[i])));
//          //Iterates over the files in the directory
//          for(unsigned int z=0;z<filesReturn.size();i++)
//          {

//          }


      }



      return "Sucess";

}
