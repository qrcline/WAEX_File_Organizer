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
#include <sstream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap waexPix(":/pictures/waExportHeaderLogo.png");
    ui->WAEX_logo->setPixmap(waexPix);
    ui->WAEX_logo_2->setPixmap(waexPix);
    ui->progressBar_save_createFile->hide();



    //THis is a test
    //ui->mexP_Spreadsheets->setChecked(false);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox->setCurrentIndex(1);
    ui->comboBox->setCurrentIndex(0);
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
    {
        ui->noticeSpreadsheets->setText("YES X"+QString::number(num));

    }

    else
    {
        ui->noticeSpreadsheets->setText("No");
        filesRequired[0]=nullptr;
    }
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

    if((num=fIo.doesFileExist("CaftaNafta",filesVec))>0)
        ui->CaftaNafta_notice->setText("YES X"+QString::number(num));
    else ui->CaftaNafta_notice->setText("No");

    if((num=fIo.doesFileExist("CertOrigin",filesVec))>0)
        ui->CertOrigin_notice->setText("YES X"+QString::number(num));
    else ui->CertOrigin_notice->setText("No");

    if((num=fIo.doesFileExist("CustomerPO",filesVec))>0)
        ui->CustomerPO_notice->setText("YES X"+QString::number(num));
    else ui->CustomerPO_notice->setText("No");

    if((num=fIo.doesFileExist("ExpInvima",filesVec))>0)
        ui->ExpInvima_notice->setText("YES X"+QString::number(num));
    else ui->ExpInvima_notice->setText("No");

    if((num=fIo.doesFileExist("FacturaComercial",filesVec))>0)
        ui->FacturaComercial_notice->setText("YES X"+QString::number(num));
    else ui->FacturaComercial_notice->setText("No");

    if((num=fIo.doesFileExist("FreightContract",filesVec))>0)
        ui->FreightContract_notice->setText("YES X"+QString::number(num));
    else ui->FreightContract_notice->setText("No");

    if((num=fIo.doesFileExist("Harris",filesVec))>0)
        ui->Harris_notice->setText("YES X"+QString::number(num));
    else ui->Harris_notice->setText("No");

    if((num=fIo.doesFileExist("HarEmails",filesVec))>0)
        ui->HarrisEmails_notice->setText("YES X"+QString::number(num));
    else ui->HarrisEmails_notice->setText("No");

    if((num=fIo.doesFileExist("ListaEmpaque",filesVec))>0)
        ui->ListadeEmpaque_notice->setText("YES X"+QString::number(num));
    else ui->ListadeEmpaque_notice->setText("No");

    if((num=fIo.doesFileExist("OtherEmails",filesVec))>0)
        ui->OtherEmails_notice->setText("YES X"+QString::number(num));
    else ui->OtherEmails_notice->setText("No");

    if((num=fIo.doesFileExist("PayablesHarris",filesVec))>0)
        ui->Payables_Harris_notice->setText("YES X"+QString::number(num));
    else ui->Payables_Harris_notice->setText("No");

    if((num=fIo.doesFileExist("PayablesSW",filesVec))>0)
        ui->Payables_ShipperWarehouse_notice->setText("YES X"+QString::number(num));
    else ui->Payables_ShipperWarehouse_notice->setText("No");

    if((num=fIo.doesFileExist("PayablesTransloader",filesVec))>0)
        ui->Payables_Transloader_notice->setText("YES X"+QString::number(num));
    else ui->Payables_Transloader_notice->setText("No");

    if((num=fIo.doesFileExist("PayablesTruckFreight",filesVec))>0)
        ui->payables_TruckFreight_notice->setText("YES X"+QString::number(num));
    else ui->payables_TruckFreight_notice->setText("No");

    if((num=fIo.doesFileExist("Transloader",filesVec))>0)
        ui->Transloader_notice->setText("YES X"+QString::number(num));
    else ui->Transloader_notice->setText("No");


    if((num=fIo.doesFileExist("Receipt",filesVec))>0)
        ui->receipts_notice->setText("YES X"+QString::number(num));
    else ui->receipts_notice->setText("No");

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
    FolderIO fIo;

    if(mainDirectory==nullptr) //If the maindirectory isn't selected ask user to select it
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Error", "Main directory not selected, select now?", QMessageBox::Yes|QMessageBox::No).exec())
        {
            mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
        }
        //return;
    }
    else if (!fIo.checkForDirect(mainDirectory,ui->POInput->text())) //If the main directory is selected check the PO# that is input
    {
        std::cout<<"This directory doe not exist"<<std::endl;
        if(ui->POInput->text()=="")
        {
            QMessageBox(QMessageBox::Information, "Error", "Please input a valid PO#.").exec();
        }
        else
        {
            if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "ERROR", "This file doesn't exist, create it now?", QMessageBox::Yes|QMessageBox::No).exec())
            {
                std::cout<<"Yes was selected"<<std::endl;
                //std::cout<<"Directory to be created: "<<mainDirectory.toStdString()+"/"+ui->POInput->text().toStdString()<<std::endl;
                fIo.createDirectory(mainDirectory+"/"+ui->POInput->text());
            }
        }
    }

    //Opens the designated file
    else
    {
        openDirectory(mainDirectory+"/"+ui->POInput->text());
    }
    ui->PoLabel->setText(ui->POInput->text());

    //Grabbing the template from the file
    QString tempTemplate=fIo.getTemplate(mainDirectory+"/"+ui->POInput->text()+"/waex.index");
    std::cout<<"Update window, fetch template:"+tempTemplate.toStdString()<<std::endl;
    if(tempTemplate=="Mex Produce")
        ui->comboBox->setCurrentIndex(0);
    if(tempTemplate=="Domestic")
        ui->comboBox->setCurrentIndex(1);
    if(tempTemplate=="Mex Direct")
        ui->comboBox->setCurrentIndex(2);
    if(tempTemplate=="Overseas")
        ui->comboBox->setCurrentIndex(3);



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
}

std::ostringstream MainWindow::getRequiredFiles()
{
      std::ostringstream fileStream;
      ui->comboBox->currentIndex();
      std::cout<<"Get required files, current indedx: "+ui->comboBox->currentText().toStdString()<<std::endl;
         fileStream<<"Template:"+ui->comboBox->currentText().toStdString()+"/TEND"<<std::endl;
         if(ui->mexP_Spreadsheets->isChecked())
             fileStream<<"Spreadsheets"<<std::endl;
         if(ui->mexP_Invoice->isChecked())
             fileStream<<"Invoice"<<std::endl;
         if(ui->mexP_Phyto->isChecked())
             fileStream<<"Phyto"<<std::endl;
         if(ui->mexP_ShipperConf->isChecked())
             fileStream<<"ShipperConf"<<std::endl;
         if(ui->mexP_CarrierConf->isChecked())
             fileStream<<"CarrierConf"<<std::endl;
         if(ui->mexP_Passing->isChecked())
             fileStream<<"Passing"<<std::endl;
         if(ui->mexP_SaleConf->isChecked())
             fileStream<<"SaleConf"<<std::endl;
         if(ui->mexP_SignedSale->isChecked())
             fileStream<<"SignedSaleConf"<<std::endl;
         if(ui->mexP_Pedimento->isChecked())
             fileStream<<"Pedimento"<<std::endl;
         if(ui->mexP_ProduceInv->isChecked())
             fileStream<<"ProduceInv"<<std::endl;
         if(ui->mexP_Payable_Shipper->isChecked())
             fileStream<<"PayablesShipper"<<std::endl;
         if(ui->mexP_Payables_Carriers->isChecked())
             fileStream<<"PayablesCarrier"<<std::endl;
         if(ui->receipts->isChecked())
             fileStream<<"Receipt"<<std::endl;
         if(ui->ExpInvima->isChecked())
             fileStream<<"ExpInvima"<<std::endl;
         if(ui->FacturaComercial->isChecked())
             fileStream<<"FacturaComercial"<<std::endl;
         if(ui->ListadeEmpaque->isChecked())
             fileStream<<"ListaEmpaque"<<std::endl;
         if(ui->CertOrigin->isChecked())
             fileStream<<"CertOrigin"<<std::endl;
         if(ui->CaftaNafta->isChecked())
             fileStream<<"CaftaNafta"<<std::endl;
         if(ui->FreightContract->isChecked())
             fileStream<<"FreightContract"<<std::endl;
         if(ui->Transloader->isChecked())
             fileStream<<"Transloader"<<std::endl;
         if(ui->Harris->isChecked())
             fileStream<<"Harris"<<std::endl;
         if(ui->HarrisEmails->isChecked())
             fileStream<<"HarEmails"<<std::endl;
         if(ui->CustomerPO->isChecked())
             fileStream<<"CustomerPO"<<std::endl;
         if(ui->OtherEmails->isChecked())
             fileStream<<"OtherEmails"<<std::endl;
         if(ui->Payables_Transloader->isChecked())
             fileStream<<"PayablesTransloader"<<std::endl;
         if(ui->payables_TruckFreight->isChecked())
             fileStream<<"PayablesTruckFreight"<<std::endl;
         if(ui->Payables_Harris->isChecked())
             fileStream<<"PayablesHarris"<<std::endl;
         if(ui->Payables_ShipperWarehouse->isChecked())
             fileStream<<"PayablesSW"<<std::endl;


    return fileStream;
}

void MainWindow::on_saveButton_clicked()
{
    std::cout<<"Save Button Pushed- Initiating Save"<<std::endl;
   // ui->progressBar_save_createFile->show();
    FolderIO fIo;

    //Fetches the required fields based on the check boxes


    if(mainDirectory!=nullptr && ui->POInput->text()!="")
    {
        if(!(fIo.createIndexFile((mainDirectory+"/"+ui->POInput->text()),ui->POInput->text(),"Quinton Cline Test",ui->notesArea->toPlainText(),getRequiredFiles())))
        {
            std::cout<<"Index file creation failed"<<std::endl;
        }
        updateWindow();
        return;
    }
    else if (mainDirectory==nullptr)
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Error", "Main directory not selected, select now?", QMessageBox::Yes|QMessageBox::No).exec())
        {
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
    QString filePath= QFileDialog::getOpenFileName(this,tr(fileDialog1.c_str()), "",tr(fileD2.c_str()));

   //Checks if the file exists already in the directory
    FolderIO fIo;
    std::vector<std::string> filesVec=fIo.list_files_vector(mainDirectory+"/"+ui->POInput->text()); //Gets list of files in a directory
    int num=0;
    num=fIo.doesFileExist(destFileName,filesVec);

    //copy(from,to,dest name)
    fIo.copyFile(filePath,mainDirectory+"/"+ui->POInput->text(),destFileName+"_"+QString::number((num+1)));
    updateWindow();
}

void MainWindow::on_mexP_Spreadsheets_upload_clicked()
{
    uploadFile("Open Spreadsheets","Excel Spreadsheet (*.xlsx)","Spreadsheets");
    updateWindow();
}

void MainWindow::on_mexP_Invoice_upload_clicked()
{
    uploadFile("Open Invoice","Invoice PDF (*.pdf)","Invoice");
    updateWindow();
}

void MainWindow::on_mexP_Phyto_upload_clicked()
{
    uploadFile("Open Phyto","Phyto PDF (*.pdf)","Phyto");
    updateWindow();
}

void MainWindow::on_mexP_ShipperConf_upload_clicked()
{
    uploadFile("Open Shipper Confirmation","Shipper Confirmation PDF (*.pdf)","ShipperConf");
    updateWindow(); }

void MainWindow::on_mexP_CarrierConf_upload_clicked()
{
    uploadFile("Open Carrrier Confirmation","Carrier Confirmation (*.pdf)","CarrierConf");
    updateWindow(); }

void MainWindow::on_mexP_Passing_upload_clicked()
{
    uploadFile("Open Passing","Passing Confirmation (*.pdf)","Passing");
    updateWindow();
}

void MainWindow::on_mexP_SaleConf_upload_clicked()
{
    uploadFile("Open Sale Confirmation","Sale Confirmation (*.pdf)","SaleConf");
    updateWindow();
}

void MainWindow::on_mexP_SignedSale_upload_clicked()
{
    uploadFile("Open Signed Sale Confirmation"," Signed Sale Confirmation (*.pdf)","SignedSaleConf");
    updateWindow(); }

void MainWindow::on_mexP_Pedimento_upload_clicked()
{
    uploadFile("Open Pedimento","Pedimento (*.pdf)","Pedimento");
    updateWindow(); }

void MainWindow::on_mexP_ProduceInv_upload_clicked()
{
    uploadFile("Open Produce Invoice","Produce Invoice (*.pdf)","ProduceInv");
    updateWindow(); }

void MainWindow::on_mexP_Payable_Shipper_upload_clicked()
{
    uploadFile("Open Payables Shipper","Payables Shipper (*.pdf)","PayablesShipper");
    updateWindow();
}

void MainWindow::on_mexP_Payables_Carriers_upload_clicked()
{
    uploadFile("Open Payables Carrier","Payables Carrier (*.pdf)","PayablesCarrier");
    updateWindow();
}

void MainWindow::on_ExpInvima_Upload_clicked()
{

    uploadFile("Open Exportacion/INVIMA","Exportacion/INVIMA (*.pdf)","ExpInvima");
    updateWindow();
}

void MainWindow::on_receipts_upload_clicked()
{
    uploadFile("Open receipts","Receipts (*.pdf)","Receipt");
    updateWindow();
}

void MainWindow::on_FacturaComercial_upload_clicked()
{
    uploadFile("Open Factura Comercial","Factura Comercial (*.pdf)","FacturaComercial");
    updateWindow();
}

void MainWindow::on_ListadeEmpaque_upload_clicked()
{
    uploadFile("Open Lista de Empaque","Lista de Empaque (*.pdf)","ListaEmpaque");
    updateWindow();
}

void MainWindow::on_CertOrigin_upload_clicked()
{
    uploadFile("Open Certification of Origin","Certification of Origin (*.pdf)","CertOrigin");
    updateWindow();
}

void MainWindow::on_CaftaNafta_upload_clicked()
{
    uploadFile("Open CAFTA/NAFTA","CAFTA/NAFTA (*.pdf)","CaftaNafta");
    updateWindow();
}

void MainWindow::on_FreightContract_upload_clicked()
{
    uploadFile("Open Freight Contract","Freight Contract (*.pdf)","FreightContract");
    updateWindow();
}

void MainWindow::on_Transloader_upload_clicked()
{
    uploadFile("Open Transloader","Transloader (*.pdf)","Transloader");
    updateWindow();
}

void MainWindow::on_Harris_upload_clicked()
{
    uploadFile("Open Harris","Harris (*.pdf)","Harris");
    updateWindow();
}

void MainWindow::on_HarrisEmails_upload_clicked()
{
    uploadFile("Open Harris Emails","Harris Emails (*.pdf)","HarEmails");
    updateWindow();
}

void MainWindow::on_CustomerPO_upload_clicked()
{
    uploadFile("Open CustomerPO","CustomerPO (*.pdf)","CustomerPO");
    updateWindow();
}

void MainWindow::on_OtherEmails_upload_clicked()
{
    uploadFile("Open Other Emails","Other Emails (*.pdf)","OtherEmails");
    updateWindow();
}

void MainWindow::on_Payables_Transloader_upload_clicked()
{
    uploadFile("Open Payables Transloader","Payables Transloader (*.pdf)","PayablesTransloader");
    updateWindow();
}

void MainWindow::on_payables_TruckFreight_upload_clicked()
{
    uploadFile("Open Payables Truck Freight","Payables Truck Freight (*.pdf)","PayablesTruckFreight");
    updateWindow();
}

void MainWindow::on_Payables_Harris_upload_clicked()
{
    uploadFile("Open Payables Harris","Payables Harris (*.pdf)","PayablesHarris");
    updateWindow();

}

void MainWindow::on_Payables_ShipperWarehouse_upload_clicked()
{
    uploadFile("Open Payables Shipper/Warehouse","Open Payables Shipper/Warehouse (*.pdf)","PayablesSW");
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

void MainWindow::on_ExpInvima_stateChanged(int arg1)
{
    if(arg1==0)
        ui->ExpInvima_Upload->setEnabled(false);
    else
        ui->ExpInvima_Upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_FacturaComercial_stateChanged(int arg1)
{
    if(arg1==0)
        ui->FacturaComercial_upload->setEnabled(false);
    else
        ui->FacturaComercial_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_ListadeEmpaque_stateChanged(int arg1)
{
    if(arg1==0)
        ui->ListadeEmpaque_upload->setEnabled(false);
    else
        ui->ListadeEmpaque_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_CertOrigin_stateChanged(int arg1)
{
    if(arg1==0)
        ui->CertOrigin_upload->setEnabled(false);
    else
        ui->CertOrigin_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_CaftaNafta_stateChanged(int arg1)
{
    if(arg1==0)
        ui->CaftaNafta_upload->setEnabled(false);
    else
        ui->CaftaNafta_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_FreightContract_stateChanged(int arg1)
{
    if(arg1==0)
        ui->FreightContract_upload->setEnabled(false);
    else
        ui->FreightContract_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_Transloader_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Transloader_upload->setEnabled(false);
    else
        ui->Transloader_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_Harris_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Harris_upload->setEnabled(false);
    else
        ui->Harris_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_HarrisEmails_stateChanged(int arg1)
{
    if(arg1==0)
        ui->HarrisEmails_upload->setEnabled(false);
    else
        ui->HarrisEmails_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_CustomerPO_stateChanged(int arg1)
{
    if(arg1==0)
        ui->CustomerPO_upload->setEnabled(false);
    else
        ui->CustomerPO_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_OtherEmails_stateChanged(int arg1)
{
    if(arg1==0)
        ui->OtherEmails_upload->setEnabled(false);
    else
        ui->OtherEmails_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_Payables_Transloader_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Payables_Transloader_upload->setEnabled(false);
    else
        ui->Payables_Transloader_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_payables_TruckFreight_stateChanged(int arg1)
{
    if(arg1==0)
        ui->payables_TruckFreight_upload->setEnabled(false);
    else
        ui->payables_TruckFreight_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_Payables_Harris_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Payables_Harris_upload->setEnabled(false);
    else
        ui->Payables_Harris_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_Payables_ShipperWarehouse_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Payables_ShipperWarehouse_upload->setEnabled(false);
    else
        ui->Payables_ShipperWarehouse_upload->setEnabled(true);
    updateWindow();
}

void MainWindow::on_receipts_stateChanged(int arg1)
{
    if(arg1==0)
        ui->receipts_upload->setEnabled(false);
    else
        ui->receipts_upload->setEnabled(true);
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


void MainWindow::uncheckAll()
{
    //Mexico & US Files
    ui->mexP_Spreadsheets->setChecked(false);
    ui->mexP_Invoice->setChecked(false);
    ui->mexP_Phyto->setChecked(false);
    ui->mexP_ShipperConf->setChecked(false);
    ui->mexP_CarrierConf->setChecked(false);
    ui->mexP_Passing->setChecked(false);
    ui->mexP_SaleConf->setChecked(false);
    ui->mexP_SignedSale->setChecked(false);
    ui->mexP_Pedimento->setChecked(false);
    ui->mexP_ProduceInv->setChecked(false);
    ui->mexP_Payable_Shipper->setChecked(false);
    ui->mexP_Payables_Carriers->setChecked(false);

    //Overseas
    ui->ExpInvima->setChecked(false);
    ui->FacturaComercial->setChecked(false);
    ui->ListadeEmpaque->setChecked(false);
    ui->CertOrigin->setChecked(false);
    ui->CaftaNafta->setChecked(false);
    ui->FreightContract->setChecked(false);
    ui->Transloader->setChecked(false);
    ui->Harris->setChecked(false);
    ui->HarrisEmails->setChecked(false);
    ui->CustomerPO->setChecked(false);
    ui->OtherEmails->setChecked(false);
    ui->Payables_Transloader->setChecked(false);
    ui->payables_TruckFreight->setChecked(false);
    ui->Payables_Harris->setChecked(false);
    ui->Payables_ShipperWarehouse->setChecked(false);

}
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    //std::cout<<"Combo box:" +QString::number(index).toStdString()<<std::endl;
    //ui->mexP_Spreadsheets_upload->setChecked(true);
    switch(index) {
        case 0 : uncheckAll();
                    ui->mexP_Spreadsheets->setChecked(true);
                    ui->mexP_Invoice->setChecked(true);
                    ui->mexP_Phyto->setChecked(true);
                    ui->mexP_ShipperConf->setChecked(true);
                    ui->mexP_CarrierConf->setChecked(true);
                    ui->mexP_Passing->setChecked(true);
                    ui->mexP_SaleConf->setChecked(true);
                    ui->mexP_SignedSale->setChecked(true);
                    ui->mexP_Pedimento->setChecked(true);
                    ui->mexP_ProduceInv->setChecked(true);
                    ui->mexP_Payable_Shipper->setChecked(true);
                    ui->mexP_Payables_Carriers->setChecked(true);
                 break;
        case 1 : uncheckAll();
                    ui->mexP_Spreadsheets->setChecked(true);
                    ui->mexP_Invoice->setChecked(true);
                    ui->mexP_ShipperConf->setChecked(true);
                    ui->mexP_CarrierConf->setChecked(true);
                    ui->mexP_SaleConf->setChecked(true);
                    ui->mexP_SignedSale->setChecked(true);
                    ui->mexP_Payable_Shipper->setChecked(true);
                    ui->mexP_Payables_Carriers->setChecked(true);
                 break;
        case 2 : uncheckAll();
                    ui->mexP_Spreadsheets->setChecked(true);
                    ui->mexP_Invoice->setChecked(true);
                    ui->mexP_Phyto->setChecked(true);
                    ui->mexP_ShipperConf->setChecked(true);
                    ui->mexP_CarrierConf->setChecked(true);
                    ui->mexP_Passing->setChecked(true);
                    ui->mexP_SaleConf->setChecked(true);
                    ui->mexP_SignedSale->setChecked(true);
                    ui->mexP_Pedimento->setChecked(true);
                    ui->mexP_Payable_Shipper->setChecked(true);
                    ui->mexP_Payables_Carriers->setChecked(true);
                 break;
        case 3 : uncheckAll();
                    ui->mexP_Spreadsheets->setChecked(true);
                    ui->mexP_Invoice->setChecked(true);
                    ui->mexP_Phyto->setChecked(true);
                    ui->mexP_ShipperConf->setChecked(true);
                    ui->mexP_Passing->setChecked(true);
                    ui->ExpInvima->setChecked(true);
                    ui->FacturaComercial->setChecked(true);
                    ui->ListadeEmpaque->setChecked(true);
                    ui->CertOrigin->setChecked(true);
                    ui->CaftaNafta->setChecked(true);
                    ui->FreightContract->setChecked(true);
                    ui->Transloader->setChecked(true);
                    ui->Harris->setChecked(true);
                    ui->HarrisEmails->setChecked(true);
                    ui->CustomerPO->setChecked(true);
                    ui->OtherEmails->setChecked(true);
                    ui->Payables_Transloader->setChecked(true);
                    ui->payables_TruckFreight->setChecked(true);
                    ui->Payables_Harris->setChecked(true);
                    ui->Payables_ShipperWarehouse->setChecked(true);

                 break;
    }

}





