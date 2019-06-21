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
#include "filesystem"
#include "folderio.h"



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


void MainWindow::updateWindow()
{//This function refreshes the window
    FolderIO fIo;
    std::vector<std::string> filesVec=fIo.list_files_vector(mainDirectory+"/"+ui->POInput->text()); //Gets list of files in a directory
    if(fIo.doesFileExist("Spreadsheets.xlsx",filesVec))
        ui->noticeSpreadsheets->setText("YES");
    else ui->noticeSpreadsheets->setText("No");

    if(fIo.doesFileExist("CarrierConf.pdf",filesVec))
        ui->noticeCarrierConf->setText("YES");
    else ui->noticeCarrierConf->setText("No");

    if(fIo.doesFileExist("Invoice.pdf",filesVec))
        ui->noticeInvoice->setText("YES");
    else ui->noticeInvoice->setText("No");

    if(fIo.doesFileExist("Passing.pdf",filesVec))
        ui->noticePassing->setText("YES");
    else ui->noticePassing->setText("No");

    if(fIo.doesFileExist("PayablesCarrier.pdf",filesVec))
        ui->noticePayableCarriers->setText("YES");
    else ui->noticePayableCarriers->setText("No");

    if(fIo.doesFileExist("PayablesShipper.pdf",filesVec))
        ui->noticePayableShipper->setText("YES");
    else ui->noticePayableShipper->setText("No");

    if(fIo.doesFileExist("Pedimento.pdf",filesVec))
        ui->noticePedimento->setText("YES");
    else ui->noticePedimento->setText("No");

    if(fIo.doesFileExist("Phyto.pdf",filesVec))
        ui->noticePhyto->setText("YES");
    else ui->noticePhyto->setText("No");

    if(fIo.doesFileExist("ProduceInv.pdf",filesVec))
        ui->noticeProduceInv->setText("YES");
    else ui->noticeProduceInv->setText("No");

    if(fIo.doesFileExist("SaleConf.pdf",filesVec))
        ui->noticeSaleConf->setText("YES");
    else ui->noticeSaleConf->setText("No");

    if(fIo.doesFileExist("ShipperConf.pdf",filesVec))
        ui->noticeShipperConf->setText("YES");
    else ui->noticeShipperConf->setText("No");

    if(fIo.doesFileExist("SignedSaleConf.pdf",filesVec))
        ui->noticeSignedSaleConf->setText("YES");
    else ui->noticeSignedSaleConf->setText("No");


}



//This funtion opens a directory in windows File Explorer
void    MainWindow::openDirectory(QString input)
{
    long result = (long)ShellExecute(0, 0, reinterpret_cast<const WCHAR*>(input.utf16()), 0, 0, SW_NORMAL);
}

void MainWindow::openFolder()
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
    ui->PoLabel->setText(ui->POInput->text());
}

//Changes the selection of the shipment
void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->stackedSelection->setCurrentIndex(ui->comboBox->currentIndex());
}


//open folder of the specified PO# or creates it if it does not exist
void MainWindow::on_openFolder_clicked()
{
    openFolder();
}


void MainWindow::on_actionOpen_triggered()
{
    mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    std::cout<<mainDirectory.toStdString()<<std::endl;
    //myModel->openFile(fileName);
}



void MainWindow::on_saveButton_clicked()
{
    std::cout<<"Save Button Pushed- Initiating Save"<<std::endl;
    FolderIO fIo;
    //fIo.createIndexFile("hello","hello","hello");
    //fIo.createIndexFile((mainDirectory+"/"+ui->POInput->text()),ui->POInput->text(),"Quinton Cline Test");

    if(!(fIo.createIndexFile((mainDirectory+"/"+ui->POInput->text()),ui->POInput->text(),"Quinton Cline Test",ui->notesArea->toPlainText())))
    {
        std::cout<<"Index file creation failed"<<std::endl;
    }

    updateWindow();

}

void MainWindow::on_POInput_returnPressed()
{
    openFolder();
    updateWindow();
}


////////////////////////////
///////  Upload Slots //////
/// ////////////////////////

void MainWindow:: uploadFile(std::string fileDialog1,std::string fileDialog2,QString destFileName )
{
    //Get the excell file location
    std::string fileD2=fileDialog2+";; All Files(*)";
    QString filePath= QFileDialog::getOpenFileName(this,
                                                   tr(fileDialog1.c_str()), "",
                                                   tr(fileD2.c_str()));

    //Checks if the file exists already in the directory
    if (QFile::exists(mainDirectory+"/"+ui->POInput->text()+"/"+destFileName))
    {
        QMessageBox::information(0,"Error","Error: This file is already loaded.");
        return;
    }
    //copy Syntax
    //copy(from,to,dest name)
    FolderIO fIo;
    fIo.copyFile(filePath,mainDirectory+"/"+ui->POInput->text(),destFileName);
    updateWindow();
}

void MainWindow::on_mexP_Spreadsheets_upload_clicked()
{
    uploadFile("Open Spreadsheets","Excel Spreadsheet (*.xlsx)","Spreadsheets.xlsx");
    updateWindow();
}

void MainWindow::on_mexP_Invoice_upload_clicked()
{
    uploadFile("Open Invoice","Invoice PDF (*.pdf)","Invoice.pdf");
    updateWindow();
}

void MainWindow::on_mexP_Phyto_upload_clicked()
{
    uploadFile("Open Phyto","Phyto PDF (*.pdf)","Phyto.pdf");
    updateWindow();
}

void MainWindow::on_mexP_ShipperConf_upload_clicked()
{
    uploadFile("Open Shipper Confirmation","Shipper Confirmation PDF (*.pdf)","ShipperConf.pdf");
    updateWindow(); }

void MainWindow::on_mexP_CarrierConf_upload_clicked()
{
    uploadFile("Open Carrrier Confirmation","Carrier Confirmation (*.pdf)","CarrierConf.pdf");
    updateWindow(); }

void MainWindow::on_mexP_Passing_upload_clicked()
{
    uploadFile("Open Passing","Passing Confirmation (*.pdf)","Passing.pdf");
    updateWindow();
}

void MainWindow::on_mexP_SaleConf_upload_clicked()
{
    uploadFile("Open Sale Confirmation","Sale Confirmation (*.pdf)","SaleConf.pdf");
    updateWindow();
}

void MainWindow::on_mexP_SignedSale_upload_clicked()
{
    uploadFile("Open Signed Sale Confirmation"," Signed Sale Confirmation (*.pdf)","SignedSaleConf.pdf");
    updateWindow(); }

void MainWindow::on_mexP_Pedimento_upload_clicked()
{
    uploadFile("Open Pedimento","Pedimento (*.pdf)","Pedimento.pdf");
    updateWindow(); }

void MainWindow::on_mexP_ProduceInv_upload_clicked()
{
    uploadFile("Open Produce Invoice","Produce Invoice (*.pdf)","ProduceInv.pdf");
    updateWindow(); }

void MainWindow::on_mexP_Payable_Shipper_upload_clicked()
{
    uploadFile("Open Payables Shipper","Payables Shipper (*.pdf)","PayablesShipper.pdf");
    updateWindow();
}

void MainWindow::on_mexP_Payables_Carriers_upload_clicked()
{
    uploadFile("Open Payables Carrier","Payables Carrier (*.pdf)","PayablesCarrier.pdf");
    updateWindow();
}
