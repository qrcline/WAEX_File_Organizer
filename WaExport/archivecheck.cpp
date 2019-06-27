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

ArchiveCheck::ArchiveCheck(QString directoryinput)
{
   directory=directoryinput;
}


QString ArchiveCheck::checkForArchive()
{
    FolderIO fIo;
      std::vector<std::string> foldersToCheck=fIo.get_directories(directory.toStdString());

      //Main loop that interates over the PO# files
      for(unsigned int i=0;i<foldersToCheck.size();i++)
      {
          //Gets the files in a specific PO#file
          std::vector<std::string> filesReturn=fIo.list_files_vector((directory+"/"+QString::fromStdString(foldersToCheck[i])));
          //Iterates over the files in the directory
          for(unsigned int z=0;z<filesReturn.size();i++)
          {

          }


      }

}
