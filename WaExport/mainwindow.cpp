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



    //THis is a test
    //ui->mexP_Spreadsheets->setChecked(false);
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
    if(mainDirectory==nullptr||!fIo.checkForDirect(mainDirectory,ui->POInput->text()))
        return;

    std::vector<std::string> filesVec=fIo.list_files_vector(mainDirectory+"/"+ui->POInput->text()); //Gets list of files in a directory
    int num=0;
    num=fIo.doesFileExist("Spreadsheets",filesVec);
    if(num>0)
        ui->noticeSpreadsheets->setText("YES X"+QString::number(num));
    else ui->noticeSpreadsheets->setText("No");

    if((num=fIo.doesFileExist("CarrierConf",filesVec))>0)
        ui->noticeCarrierConf->setText("YES X"+QString::number(num));
    else ui->noticeCarrierConf->setText("No");

    if((num=fIo.doesFileExist("Invoice",filesVec))>0)
        ui->noticeInvoice->setText("YES X"+QString::number(num));
    else ui->noticeInvoice->setText("No");

    if((num=fIo.doesFileExist("Passing",filesVec))>0)
        ui->noticePassing->setText("YES X"+QString::number(num));
    else ui->noticePassing->setText("No");

    if((num=fIo.doesFileExist("PayablesCarrier",filesVec))>0)
        ui->noticePayableCarriers->setText("YES X"+QString::number(num));
    else ui->noticePayableCarriers->setText("No");

    if((num=fIo.doesFileExist("PayablesShipper",filesVec))>0)
        ui->noticePayableShipper->setText("YES X"+QString::number(num));
    else ui->noticePayableShipper->setText("No");

    if((num=fIo.doesFileExist("Pedimento",filesVec))>0)
        ui->noticePedimento->setText("YES X"+QString::number(num));
    else ui->noticePedimento->setText("No");

    if((num=fIo.doesFileExist("Phyto",filesVec))>0)
        ui->noticePhyto->setText("YES X"+QString::number(num));
    else ui->noticePhyto->setText("No");

    if((num=fIo.doesFileExist("ProduceInv",filesVec))>0)
        ui->noticeProduceInv->setText("YES X"+QString::number(num));
    else ui->noticeProduceInv->setText("No");

    if((num=fIo.doesFileExist("SaleConf",filesVec))>0)
        ui->noticeSaleConf->setText("YES X"+QString::number(num));
    else ui->noticeSaleConf->setText("No");

    if((num=fIo.doesFileExist("ShipperConf",filesVec))>0)
        ui->noticeShipperConf->setText("YES X"+QString::number(num));
    else ui->noticeShipperConf->setText("No");

    if((num=fIo.doesFileExist("SignedSaleConf",filesVec))>0)
        ui->noticeSignedSaleConf->setText("YES X"+QString::number(num));
    else ui->noticeSignedSaleConf->setText("No");


    //Fill in the notes section
   ui->notesArea->setText( fIo.getNotes(mainDirectory+"/"+ui->POInput->text()+"/waex.index"));


}



//This funtion opens a directory in windows File Explorer
void    MainWindow::openDirectory(QString input)
{
    long result = (long)ShellExecute(0, 0, reinterpret_cast<const WCHAR*>(input.utf16()), 0, 0, SW_NORMAL);
}

void MainWindow::openFolder()
{
     std::cout<<"Checkpoint:1"<<std::endl;
    FolderIO fIo;

    if(mainDirectory==nullptr) //If the maindirectory isn't selected ask user to select it
    {
         std::cout<<"Checkpoint:2"<<std::endl;
        std::cout<<"Error folder not selected"<<std::endl;
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Error", "Main directory not selected, select now?", QMessageBox::Yes|QMessageBox::No).exec())
        {
             std::cout<<"Checkpoint:3"<<std::endl;
            mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
        }
        //return;
    }
    else if (!fIo.checkForDirect(mainDirectory,ui->POInput->text())) //If the main directory is selected check the PO# that is input
    {
         std::cout<<"Checkpoint:4"<<std::endl;
        std::cout<<"This directory doe not exist"<<std::endl;
        if(ui->POInput->text()=="")
        {
            QMessageBox(QMessageBox::Information, "Error", "Please input a valid PO#.").exec();
        }
        else
        {std::cout<<"Checkpoint:5"<<std::endl;



           if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "ERROR", "This file doesn't exist, create it now?", QMessageBox::Yes|QMessageBox::No).exec())
            {
                std::cout<<"Yes was selected"<<std::endl;
                //std::cout<<"Directory to be created: "<<mainDirectory.toStdString()+"/"+ui->POInput->text().toStdString()<<std::endl;
                fIo.createDirectory(mainDirectory+"/"+ui->POInput->text());
            }
        }
        std::cout<<"End of open file"<<std::endl;

    }

    //Opens the designated file
    else
    {
        std::cout<<"Checkpoint:6"<<std::endl;
        openDirectory(mainDirectory+"/"+ui->POInput->text());
    }
    ui->PoLabel->setText(ui->POInput->text());
    updateWindow();
}

//Changes the selection of the shipment
void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //ui->stackedSelection->setCurrentIndex(ui->comboBox->currentIndex());
    updateWindow();

}


//open folder of the specified PO# or creates it if it does not exist
void MainWindow::on_openFolder_clicked()
{

    openFolder();
    updateWindow();
}


void MainWindow::on_actionOpen_triggered()
{
    mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    std::cout<<mainDirectory.toStdString()<<std::endl;
    if(mainDirectory!=nullptr)
        ui->notesArea->setEnabled(true);

    //myModel->openFile(fileName);
}



void MainWindow::on_saveButton_clicked()
{
    std::cout<<"Save Button Pushed- Initiating Save"<<std::endl;
    FolderIO fIo;
    //fIo.createIndexFile("hello","hello","hello");
    //fIo.createIndexFile((mainDirectory+"/"+ui->POInput->text()),ui->POInput->text(),"Quinton Cline Test");

    if(mainDirectory!=nullptr && ui->POInput->text()!="")
    {
        if(!(fIo.createIndexFile((mainDirectory+"/"+ui->POInput->text()),ui->POInput->text(),"Quinton Cline Test",ui->notesArea->toPlainText())))
        {
            std::cout<<"Index file creation failed"<<std::endl;
        }

        updateWindow();
    }
    else if (mainDirectory==nullptr)
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Error", "Main directory not selected, select now?", QMessageBox::Yes|QMessageBox::No).exec())
        {
             std::cout<<"Checkpoint:3"<<std::endl;
            mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
        }
    }
    else if (ui->POInput->text()!="" )
    {
         QMessageBox(QMessageBox::Information, "Error", "Please input a valid PO#.").exec();
    }


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


/////////////////////////////
/// \brief MainWindow::on_mexP_Spreadsheets_stateChanged
/// \param arg1
///////Check boxes/////////////////////////
/// /////////////////////////////////
void MainWindow::on_mexP_Spreadsheets_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Spreadsheets_upload->setEnabled(false);
    else
        ui->mexP_Spreadsheets_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_Invoice_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Invoice_upload->setEnabled(false);
    else
        ui->mexP_Invoice_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_Phyto_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Phyto_upload->setEnabled(false);
    else
        ui->mexP_Phyto_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_ShipperConf_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_ShipperConf_upload->setEnabled(false);
    else
        ui->mexP_ShipperConf_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_CarrierConf_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_CarrierConf_upload->setEnabled(false);
    else
        ui->mexP_CarrierConf_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_Passing_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Passing_upload->setEnabled(false);
    else
        ui->mexP_Passing_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_SaleConf_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_SaleConf_upload->setEnabled(false);
    else
        ui->mexP_SaleConf_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_SignedSale_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_SignedSale_upload->setEnabled(false);
    else
        ui->mexP_SignedSale_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_Pedimento_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Pedimento_upload->setEnabled(false);
    else
        ui->mexP_Pedimento_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_ProduceInv_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_ProduceInv_upload->setEnabled(false);
    else
        ui->mexP_ProduceInv_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_Payable_Shipper_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Payable_Shipper_upload->setEnabled(false);
    else
        ui->mexP_Payable_Shipper_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_mexP_Payables_Carriers_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Payables_Carriers_upload->setEnabled(false);
    else
        ui->mexP_Payables_Carriers_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_reloadButton_clicked()
{
    updateWindow();
}

void MainWindow::on_POInput_editingFinished()
{
    //updateWindow();
}
