#include "mainwindow.h"
#include "folderio.h"
#include "ui_mainwindow.h"
#include <Windows.h>
#include <shellapi.h>
#include "string"
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "filesystem"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap waexPix(":/pictures/waExportHeaderLogo.png");
    ui->WAEX_logo->setPixmap(waexPix);
    ui->WAEX_logo_2->setPixmap(waexPix);
}

QString MainWindow::getMainDirectory()
{
    return mainDirectory;
}

MainWindow::~MainWindow()
{
    delete ui;
}


/////////////////////////////////////
///////        Functions  ///////////
////////////////////////////////////


//This funtion opens a directory in windows File Explorer
void    MainWindow::openDirectory(QString input)
{
    long result = (long)ShellExecute(0, 0, reinterpret_cast<const WCHAR*>(input.utf16()), 0, 0, SW_NORMAL);
}







//Changes the selection of the shipment
void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->stackedSelection->setCurrentIndex(ui->comboBox->currentIndex());
}


//open folder of the specified PO# or creates it if it does not exist
void MainWindow::on_openFolder_clicked()
{
    FolderIO fIo;

    if(mainDirectory==nullptr) //If the maindirectory isn't selected ask user to select it
    {
        std::cout<<"Error folder not selected"<<std::endl;
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Error", "Main directory not selected, select now?", QMessageBox::Yes|QMessageBox::No).exec())
        {
            mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
        }
    }
    else if (!fIo.checkForDirect(mainDirectory,ui->POInput->text())) //If the main directory is selected check the PO# that is input
    {
        std::cout<<"This directory doe not exist"<<std::endl;
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "ERROR", "This file doesn't exist, create it now?", QMessageBox::Yes|QMessageBox::No).exec())
        {
            std::cout<<"Yes was selected"<<std::endl;
            //std::cout<<"Directory to be created: "<<mainDirectory.toStdString()+"/"+ui->POInput->text().toStdString()<<std::endl;
            fIo.createDirectory(mainDirectory+"/"+ui->POInput->text());
        }
    }


    //Opens the designated file
    else
    {
        openDirectory(mainDirectory+"/"+ui->POInput->text());
    }
}


void MainWindow::on_actionOpen_triggered()
{
    mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    std::cout<<mainDirectory.toStdString()<<std::endl;
    //myModel->openFile(fileName);

}

void MainWindow::on_mexP_Spreadsheets_upload_clicked()
{
    //Get the excell file location
    QString filePath= QFileDialog::getOpenFileName(this,
                                                   tr("Open Spreadsheets"), "",
                                                   tr("Excel Spreadsheet (*.xlsx);; All Files(*)"));

    //Checks if the file exists already in the directory
    if (QFile::exists(mainDirectory+"/"+ui->POInput->text()+"/Spreadsheets.xlsx"))
    {
        QMessageBox::information(0,"Error","Error: This file is already loaded.");
        return;
    }
    //copy Syntax
    //copy(from,to)
    FolderIO fIo;
    fIo.copyFile(filePath,mainDirectory+"/"+ui->POInput->text(),"Spreadsheets.xlsx");
    //QFile::copy(filePath, +"/Spreadsheets.xlsx");//This copies the file with the new name

    /*
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"error",file.errorString());
        return;
    }
    QTextStream in(&file); //Reads in the file
    */


}

void MainWindow::on_saveButton_clicked()
{
    std::cout<<"Save Button Pushed- Initiating Save"<<std::endl;
    FolderIO fIo;
    if(!(fIo.createIndexFile(mainDirectory+"/"+ui->POInput->text(),ui->POInput->text(),"Quinton Cline Test")))
    {
        std::cout<<"Index file creation failed"<<std::endl;
    }

}

void MainWindow::on_POInput_returnPressed()
{

}
