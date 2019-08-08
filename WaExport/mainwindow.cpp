#include "mainwindow.h"
#include "ui_mainwindow.h"

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
#include <archivecheck.h>
#include <QSettings>
#include <QtCore>
#include <thread>
#include <QtGui>
#include <QInputDialog>
#include <QNetworkAccessManager>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QVariant>
#include <QtDebug>
#include <QSsl>






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tableModel(new myTableModel(this))
{
    std::cout<<"In mainWindow construct"<<std::endl;
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    ui->tableView->setModel(tableModel);
    QPixmap waexPix(":/pictures/waExportHeaderLogo.png");
    ui->WAEX_logo->setPixmap(waexPix);
    ui->WAEX_logo_2->setPixmap(waexPix);
    // ui->progressBar_save_createFile->hide();
    //settingD= new class settingD(this,ui);
    ui->mexP_Invoice->acceptDrops();
    acceptDrops();

    ui->statusBar->hide();
    //THis is a test
    //ui->mexP_Spreadsheets->setChecked(false);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox->setCurrentIndex(1);
    ui->comboBox->setCurrentIndex(0);
    loadSettings();
    ui->notesDisplay->hide();
    ui->testSocketButton->hide();



    //updateWindow();
}


void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{

    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
    std::cout<<"This is a drag Event"<<std::endl;

}

void MainWindow::dropEvent(QDropEvent *event)
{
    std::cout<<"This is a drop event"<<std::endl;
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
        return;

    //if (readFile(fileName))
    std::cout<<fileName.toStdString()<<std::endl;
    QStringList choices = {"CaftaNafta","CarrierConf","CertOrigin","CustomerPO","ExpInvima","FacturaComercial","FreightContract","HarEmails","Harris","Invoice","ListaEmpaque","OtherEmails","Passing","PayablesCarrier","PayablesHarris","PayablesShipper","PayablesSW","PayablesTransloader","PayablesTruckFreight","Pedimento","Phyto","ProduceInv","Receipt","SaleConf","ShipperConf","SignedSaleConf","Spreadsheets","Transloader"};
    QString selection=QInputDialog::getItem(nullptr,"Upload","What file is this?",choices);

    //Checks if the file exists already in the directory
    FolderIO fIo;
    std::vector<std::string> filesVec=fIo.list_files_vector(mainDirectory+"/"+ui->POInput->text()); //Gets list of files in a directory
    int num=0;
    num=fIo.doesFileExist(selection,filesVec);

    //copy(from,to,dest name)
    fIo.copyFile(fileName,mainDirectory+"/"+ui->POInput->text(),selection+"_"+QString::number((num+1)));

}




void MainWindow::loadSettings()
{
    //Grab the settings
    QSettings setting("WAEX","Organizer");
    setting.beginGroup("Settings");
    mainDirectory=setting.value("workDirec","NULL").toString();
    userName=setting.value("User","").toString();
    PAT=setting.value("PAT","").toString();
    QString tTip=setting.value("tTip","False").toString();
    setting.endGroup();
    //Set working directory labels
    ui->workingDirectory->setText(mainDirectory);
    ui->workingDirectory_CreateFile->setText(mainDirectory);

    std::cout<<"The tTip value is: "<<tTip.toStdString()<<std::endl;
    if(tTip=="True")
    {

        ui->POInput->setToolTip("Input PO to lookup or create.");
        ui->comboBox->setToolTip("Select template for req files.");
        ui->workingDirectory->setToolTip("The directory were files are saved.");
        ui->openFolder->setToolTip("Opens the PO# folder in File Explorer");
        ui->saveButton->setToolTip("Click save to create the index file and save notes. ");
        ui->archiveCheckButton->setToolTip("Initiates Archive Check.");
        ui->archiveErrorList->setToolTip("Files that were unable to be checked.\n This is usually due to a missing index file.\n Open the PO in Create File and hit Save\n to generate the index file. ");

    }
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
    QElapsedTimer timer;
    timer.start();

    FolderIO fIo;
    if(mainDirectory=="NULL"||!fIo.checkForDirect(mainDirectory,ui->POInput->text()))
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
    ui->notesDisplay->setText( fIo.getNotes(mainDirectory+"/"+ui->POInput->text()+"/waex.index"));
    gloGetCardId(ui->POInput->text());
    gloLoadComments();//loads the globoard comments
    gloLoadLabels();

    std::cout<<"Time to complete window update: "+std::to_string(timer.elapsed())<<std::endl;


}

void MainWindow::updateChecked()
{
    uncheckAll();
    FolderIO fIo;
    bool errorCheck=false;
    std::vector<std::string> reqFiles=fIo.get_reqFiles(mainDirectory+"/"+ui->POInput->text(), errorCheck);

    if (binary_search(reqFiles.begin(), reqFiles.end(), "Spreadsheets"))
        ui->mexP_Spreadsheets->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "Invoice"))
        ui->mexP_Invoice->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "Phyto"))
        ui->mexP_Phyto->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "ShipperConf"))
        ui->mexP_ShipperConf->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "CarrierConf"))
        ui->mexP_CarrierConf->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "Passing"))
        ui->mexP_Passing->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "SaleConf"))
        ui->mexP_SaleConf->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "SignedSaleConf"))
        ui->mexP_SignedSale->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "Pedimento"))
        ui->mexP_Pedimento->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "ProduceInv"))
        ui->mexP_ProduceInv->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "PayablesShipper"))
        ui->mexP_Payable_Shipper->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "PayablesCarrier"))
        ui->mexP_Payables_Carriers->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "Receipts"))
        ui->receipts->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "ExpInvima"))
        ui->ExpInvima->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "FacturaComercial"))
        ui->FacturaComercial->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "ListaEmpaque"))
        ui->ListadeEmpaque->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "CertOrigin"))
        ui->CertOrigin->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "CaftaNafta"))
        ui->CaftaNafta->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "FreightContract"))
        ui->FreightContract->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "Transloader"))
        ui->Transloader->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "Harris"))
        ui->Harris->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "HarEmails"))
        ui->HarrisEmails->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "CustomerPO"))
        ui->CustomerPO->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "OtherEmails"))
        ui->OtherEmails->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "PayablesTransloader"))
        ui->Payables_Transloader->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "PayablesTruckFreight"))
        ui->payables_TruckFreight->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "PayablesHarris"))
        ui->Payables_ShipperWarehouse->setChecked(true);
    if (binary_search(reqFiles.begin(), reqFiles.end(), "PayablesSW"))
        ui->Payables_ShipperWarehouse->setChecked(true);
    ui->comboBox->setEnabled(false);
}


//This funtion opens a directory in windows File Explorer
void    MainWindow::openDirectory(QString input)
{
    long result = (long)ShellExecute(0, 0, reinterpret_cast<const WCHAR*>(input.utf16()), 0, 0, SW_NORMAL);

}

void MainWindow::openFolder(QString folderText,bool winEx)
{
    //if winEx true open the folder in windows explorer
    //Else dont open in explorer and just load the file
    FolderIO fIo;

    if(mainDirectory=="NULL") //If the maindirectory isn't selected ask user to select it
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Error", "Main directory not selected, select now?", QMessageBox::Yes|QMessageBox::No).exec())
        {
            mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
        }
        //return;
    }
    else if (!fIo.checkForDirect(mainDirectory,folderText)) //If the main directory is selected check the PO# that is input
    {
        std::cout<<"This directory doe not exist"<<std::endl;
        if(folderText=="")
        {
            QMessageBox(QMessageBox::Information, "Error", "Please input a valid PO#.").exec();
        }
        else
        {
            if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "ERROR", "This file doesn't exist, create it now?", QMessageBox::Yes|QMessageBox::No).exec())
            {
                std::cout<<"Yes was selected"<<std::endl;
                ui->comboBox->setEnabled(true);
                //std::cout<<"Directory to be created: "<<mainDirectory.toStdString()+"/"+folderText.toStdString()<<std::endl;
                fIo.createDirectory(mainDirectory+"/"+folderText);
                ui->comboBox->setCurrentIndex(0);
                ui->comboBox->setCurrentIndex(1);
                ui->comboBox->setCurrentIndex(0);
                gloCreatePO(folderText);
                currentCardid=gloGetCardId(ui->POInput->text());

            }
        }
    }

    //Opens the designated file
    else
    {
        if(winEx)
            openDirectory(mainDirectory+"/"+folderText);
        //Grabbing the template from the file
        QString tempTemplate=fIo.getTemplate(mainDirectory+"/"+folderText+"/waex.index");

        std::cout<<"Update window, fetch template:"+tempTemplate.toStdString()<<std::endl;
        if(tempTemplate=="Mex Produce")
            ui->comboBox->setCurrentIndex(0);
        else if(tempTemplate=="Domestic")
            ui->comboBox->setCurrentIndex(1);
        else if(tempTemplate=="Mex Direct")
            ui->comboBox->setCurrentIndex(2);
        else if(tempTemplate=="Overseas")
            ui->comboBox->setCurrentIndex(3);
        updateChecked();
        currentCardid=gloGetCardId(ui->POInput->text());
        gloLoadLabels();
    }
    ui->PoLabel->setText(folderText);
    ui->gloFrame->setEnabled(true);



    updateWindow();
}

void MainWindow::closeEvent(QCloseEvent *bar)
{
    //Saves the working directory to settings
    QSettings setting("WAEX","Organizer");
    setting.beginGroup("Settings");
    setting.setValue("workDirec",mainDirectory);
    setting.endGroup();
    QWidget::closeEvent(bar);
}



//open folder of the specified PO# or creates it if it does not exist
void MainWindow::on_openFolder_clicked()
{
    openFolder(ui->POInput->text(),true);
    //updateWindow();
}


void MainWindow::on_actionOpen_triggered()
{
    mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Working Directory"), QDir::currentPath());
    std::cout<<mainDirectory.toStdString()<<std::endl;
    if(mainDirectory!=nullptr)
        ui->notesArea->setEnabled(true);
    ui->workingDirectory->setText(mainDirectory);
    ui->workingDirectory_CreateFile->setText(mainDirectory);
}

std::ostringstream MainWindow::getRequiredFiles()
{
    std::ostringstream fileStream;
    ui->comboBox->currentIndex();
    std::cout<<"Get required files, current indedx: "+ui->comboBox->currentText().toStdString()<<std::endl;
    fileStream<<"Template:"+ui->comboBox->currentText().toStdString()+"/TEND"<<std::endl;
    fileStream<<"/REQSTART/"<<std::endl;

    if(ui->CaftaNafta->isChecked())
        fileStream<<"CaftaNafta"<<std::endl;
    if(ui->mexP_CarrierConf->isChecked())
        fileStream<<"CarrierConf"<<std::endl;
    if(ui->CertOrigin->isChecked())
        fileStream<<"CertOrigin"<<std::endl;
    if(ui->CustomerPO->isChecked())
        fileStream<<"CustomerPO"<<std::endl;
    if(ui->ExpInvima->isChecked())
        fileStream<<"ExpInvima"<<std::endl;
    if(ui->FacturaComercial->isChecked())
        fileStream<<"FacturaComercial"<<std::endl;
    if(ui->FreightContract->isChecked())
        fileStream<<"FreightContract"<<std::endl;
    if(ui->HarrisEmails->isChecked())
        fileStream<<"HarEmails"<<std::endl;
    if(ui->Harris->isChecked())
        fileStream<<"Harris"<<std::endl;
    if(ui->mexP_Invoice->isChecked())
        fileStream<<"Invoice"<<std::endl;
    if(ui->ListadeEmpaque->isChecked())
        fileStream<<"ListaEmpaque"<<std::endl;
    if(ui->OtherEmails->isChecked())
        fileStream<<"OtherEmails"<<std::endl;
    if(ui->mexP_Passing->isChecked())
        fileStream<<"Passing"<<std::endl;
    if(ui->mexP_Payables_Carriers->isChecked())
        fileStream<<"PayablesCarrier"<<std::endl;
    if(ui->Payables_Harris->isChecked())
        fileStream<<"PayablesHarris"<<std::endl;
    if(ui->mexP_Payable_Shipper->isChecked())
        fileStream<<"PayablesShipper"<<std::endl;
    if(ui->Payables_ShipperWarehouse->isChecked())
        fileStream<<"PayablesSW"<<std::endl;
    if(ui->Payables_Transloader->isChecked())
        fileStream<<"PayablesTransloader"<<std::endl;
    if(ui->payables_TruckFreight->isChecked())
        fileStream<<"PayablesTruckFreight"<<std::endl;
    if(ui->mexP_Pedimento->isChecked())
        fileStream<<"Pedimento"<<std::endl;
    if(ui->mexP_Phyto->isChecked())
        fileStream<<"Phyto"<<std::endl;
    if(ui->mexP_ProduceInv->isChecked())
        fileStream<<"ProduceInv"<<std::endl;
    if(ui->receipts->isChecked())
        fileStream<<"Receipt"<<std::endl;
    if(ui->mexP_SaleConf->isChecked())
        fileStream<<"SaleConf"<<std::endl;
    if(ui->mexP_ShipperConf->isChecked())
        fileStream<<"ShipperConf"<<std::endl;
    if(ui->mexP_SignedSale->isChecked())
        fileStream<<"SignedSaleConf"<<std::endl;
    if(ui->mexP_Spreadsheets->isChecked())
        fileStream<<"Spreadsheets"<<std::endl;
    if(ui->Transloader->isChecked())
        fileStream<<"Transloader"<<std::endl;
    fileStream<<"/REQEND/"<<std::endl;


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
        if(!(fIo.createIndexFile((mainDirectory+"/"+ui->POInput->text()),ui->POInput->text(),"Quinton Cline Test",ui->notesDisplay->toPlainText(),getRequiredFiles())))
        {
            std::cout<<"Index file creation failed"<<std::endl;
        }
        updateWindow();
        return;
    }
    else if (mainDirectory=="NULL")
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
    openFolder(ui->POInput->text(),false);
    //updateWindow();
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
    //updateWindow();
}

void MainWindow:: createShortcut(std::string fileDialog1,std::string fileDialog2,QString destFileName )
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
    //fIo.copyFile(filePath,mainDirectory+"/"+ui->POInput->text(),destFileName+"_"+QString::number((num+1)));
    fIo.createLink(filePath,mainDirectory+"/"+ui->POInput->text()+"/"+destFileName);
    updateWindow();
}



void MainWindow::on_mexP_Spreadsheets_upload_clicked()
{
    //uploadFile("Open Spreadsheets","Excel Spreadsheet (*.xlsx)","Spreadsheets");
    createShortcut("Open Spreadsheets","Excel Spreadsheet (*.xlsx)","Spreadsheets");
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
void MainWindow::on_otherFiles_upload_clicked()
{
    //uploadFile("Open Other Files","Other Files","Other Files");



    //Get the excell file location
    //std::string fileD2=fileDialog2+";; All Files(*)";
    QString filePath= QFileDialog::getOpenFileName(this,tr("Open File"), "",tr("All Files(*)"));

    std::cout<<filePath.toStdString()<<std::endl;
    QString fileName=filePath.right(filePath.length()-filePath.lastIndexOf("/")-1);
    std::cout<<fileName.toStdString()<<std::endl;
    QFile::copy(filePath, mainDirectory+"/"+ui->POInput->text()+"/"+fileName);//This copies the file with the new destination name
    updateWindow();

    //TODO: Make the other files upload work
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
    //updateWindow();
}

void MainWindow::on_mexP_Invoice_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Invoice_upload->setEnabled(false);
    else
        ui->mexP_Invoice_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_mexP_Phyto_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Phyto_upload->setEnabled(false);
    else
        ui->mexP_Phyto_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_mexP_ShipperConf_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_ShipperConf_upload->setEnabled(false);
    else
        ui->mexP_ShipperConf_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_mexP_CarrierConf_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_CarrierConf_upload->setEnabled(false);
    else
        ui->mexP_CarrierConf_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_mexP_Passing_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Passing_upload->setEnabled(false);
    else
        ui->mexP_Passing_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_mexP_SaleConf_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_SaleConf_upload->setEnabled(false);
    else
        ui->mexP_SaleConf_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_mexP_SignedSale_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_SignedSale_upload->setEnabled(false);
    else
        ui->mexP_SignedSale_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_mexP_Pedimento_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Pedimento_upload->setEnabled(false);
    else
        ui->mexP_Pedimento_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_mexP_ProduceInv_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_ProduceInv_upload->setEnabled(false);
    else
        ui->mexP_ProduceInv_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_mexP_Payable_Shipper_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Payable_Shipper_upload->setEnabled(false);
    else
        ui->mexP_Payable_Shipper_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_mexP_Payables_Carriers_stateChanged(int arg1)
{
    if(arg1==0)
        ui->mexP_Payables_Carriers_upload->setEnabled(false);
    else
        ui->mexP_Payables_Carriers_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_ExpInvima_stateChanged(int arg1)
{
    if(arg1==0)
        ui->ExpInvima_Upload->setEnabled(false);
    else
        ui->ExpInvima_Upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_FacturaComercial_stateChanged(int arg1)
{
    if(arg1==0)
        ui->FacturaComercial_upload->setEnabled(false);
    else
        ui->FacturaComercial_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_ListadeEmpaque_stateChanged(int arg1)
{
    if(arg1==0)
        ui->ListadeEmpaque_upload->setEnabled(false);
    else
        ui->ListadeEmpaque_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_CertOrigin_stateChanged(int arg1)
{
    if(arg1==0)
        ui->CertOrigin_upload->setEnabled(false);
    else
        ui->CertOrigin_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_CaftaNafta_stateChanged(int arg1)
{
    if(arg1==0)
        ui->CaftaNafta_upload->setEnabled(false);
    else
        ui->CaftaNafta_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_FreightContract_stateChanged(int arg1)
{
    if(arg1==0)
        ui->FreightContract_upload->setEnabled(false);
    else
        ui->FreightContract_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_Transloader_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Transloader_upload->setEnabled(false);
    else
        ui->Transloader_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_Harris_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Harris_upload->setEnabled(false);
    else
        ui->Harris_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_HarrisEmails_stateChanged(int arg1)
{
    if(arg1==0)
        ui->HarrisEmails_upload->setEnabled(false);
    else
        ui->HarrisEmails_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_CustomerPO_stateChanged(int arg1)
{
    if(arg1==0)
        ui->CustomerPO_upload->setEnabled(false);
    else
        ui->CustomerPO_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_OtherEmails_stateChanged(int arg1)
{
    if(arg1==0)
        ui->OtherEmails_upload->setEnabled(false);
    else
        ui->OtherEmails_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_Payables_Transloader_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Payables_Transloader_upload->setEnabled(false);
    else
        ui->Payables_Transloader_upload->setEnabled(true);
    //updateWindow();
}

void MainWindow::on_payables_TruckFreight_stateChanged(int arg1)
{
    if(arg1==0)
        ui->payables_TruckFreight_upload->setEnabled(false);
    else
        ui->payables_TruckFreight_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_Payables_Harris_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Payables_Harris_upload->setEnabled(false);
    else
        ui->Payables_Harris_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_Payables_ShipperWarehouse_stateChanged(int arg1)
{
    if(arg1==0)
        ui->Payables_ShipperWarehouse_upload->setEnabled(false);
    else
        ui->Payables_ShipperWarehouse_upload->setEnabled(true);
    // updateWindow();
}

void MainWindow::on_receipts_stateChanged(int arg1)
{
    if(arg1==0)
        ui->receipts_upload->setEnabled(false);
    else
        ui->receipts_upload->setEnabled(true);
    // updateWindow();
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
    //ui->receipts->setChecked(false);

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

void MainWindow::on_archiveCheckButton_clicked()
{
    ArchiveCheck *aCheck  =new ArchiveCheck(mainDirectory,ui,tableModel);
    if(mainDirectory=="NULL") //If the maindirectory isn't selected ask user to select it
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Error", "Main directory not selected, select now?", QMessageBox::Yes|QMessageBox::No).exec())
        {
            mainDirectory = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
        }

    }
    //runs the archive check
    std::cout<<"Archive check started"<<std::endl;


    int totalErrors=0;
    int filesAffected=0;
    QString response=aCheck->checkForArchive(totalErrors,filesAffected);

    if(response=="ERROR/1")
    {
        std::cout<<response.toStdString()<<std::endl;
    }
    std::cout<<response.toStdString()<<std::endl;
    ui->ACheck_TotalErrors->setNum(totalErrors);
    ui->ACheck_FilesAffected->setNum(filesAffected);

    ui->archiveCheckButton_2->setEnabled(true);

    std::cout<<"Archive check finished"<<std::endl;
}

void MainWindow::updateWindowT(int num)
{
    //std::thread t1(updateWindow);

    //t1.join();
    //updateWindow();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{

    ui->POInput->setText(tableModel->getPo(index.row()));
    ui->tabWidget->setCurrentIndex(0);
    openFolder(tableModel->getPo(index.row()),false);
    //updateWindow();
    //std::thread t1(MainWindow::updateWindow);
    //t1.join();
    std::cout<<QString::number(index.row()).toStdString()+"--"+tableModel->getPo(index.row()).toStdString()<<std::endl;
}




void MainWindow::on_archiveCheckButton_2_clicked()
{
    //Opens the errors.csv for the user to view
    std::string openFile=mainDirectory.toStdString()+"/errors.csv";
    openFile="\""+openFile+"\"";
    system(openFile.c_str());
    //system("exit");
}

void MainWindow::on_actionAbout_triggered()
{
    AboutWindow aboutWindow;
    aboutWindow.setModal(true);
    // aboutWindow.setWindowFlag(aboutWindow.windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ///setWindowFlag(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    aboutWindow.exec();
}

void MainWindow::on_actionHelp_Center_triggered()
{
    helpP = new HelpCenter();
    helpP->show();

}

void MainWindow::on_actionSettings_2_triggered()
{
    settingD setD(this,ui);
    setD.setModal(true);
    setD.exec();
}

void MainWindow::on_actionDelete_Current_PO_triggered()
{
    QString message="You are going to delete PO#: "+ui->POInput->text()+"\nThis is not reversable and will delete any Glo Board card, continue?";
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Delete File", message, QMessageBox::Yes|QMessageBox::No).exec())
    {
        if(ui->POInput->text().length()>0)
        {
            //Delete file
            std::cout<<"Yes was selected"<<std::endl;
            QDir dir(mainDirectory+"/"+ui->POInput->text());

            if(dir.removeRecursively())
            {

                //Delete Glo Boards Card
                QString path="/cards/"+currentCardid;
                QUrl url;
                url.setScheme("https");
                url.setHost("gloapi.gitkraken.com");
                url.setPath("/v1/glo/boards/5d360413538eed0011572e26"+path);


                QNetworkRequest req(url);

                req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
                QString rawAuth= "Bearer "+PAT;
                req.setRawHeader("Authorization",rawAuth.toUtf8());  //Take out before git push
                req.setRawHeader("Accept","application/json");
                QNetworkAccessManager man;
                QNetworkReply *reply =man.deleteResource(req);

                while(!reply->isFinished())
                {
                    qApp->processEvents();
                }


                QByteArray responseByte=reply->readAll();
                //qDebug()<<responseByte;
                ui->POInput->clear();
                ui->notesArea->clear();
                ui->notesDisplay->clear();
                ui->order_progressBar->setValue(0);
                updateWindow();
            }
        }
        else
        {
            QMessageBox(QMessageBox::Information, "Error", "Please input a valid PO#.").exec();
        }


    }

}


void MainWindow::on_RB_SalesOrder_clicked()
{
    ui->order_progressBar->setValue(7);
    gloMoveCard();
}

void MainWindow::on_RB_Shipped_clicked()
{
    ui->order_progressBar->setValue(29);
    gloMoveCard();
}

void MainWindow::on_RB_Border_clicked()
{
    ui->order_progressBar->setValue(50);
    gloMoveCard();
}

void MainWindow::on_RB_Crossed_clicked()
{
    ui->order_progressBar->setValue(75);
    gloMoveCard();
}

void MainWindow::on_RB_Delivered_clicked()
{
    ui->order_progressBar->setValue(100);
    gloMoveCard();
}

void MainWindow::on_testSocketButton_clicked()
{
    QByteArray message= "{\"name\":\"test2021\",\"position\":\"15\",\"column_id\":\"5d36042213853d0011ab778f\"}";
    // QString cardId= gloGetCardId(ui->POInput->text());
    gloAddComment(ui->POInput->text(),"Hi my name is Quinton");
    //qDebug()<<cardId;

    //postRequest(message);
}

void MainWindow::gloCreatePO(QString po)
{
    QString message= "{\"name\":\""+po+"\",\"position\":\"0\",\"column_id\":\"5d36042213853d0011ab778f\"}";
    QByteArray sendMessage=message.toUtf8();
    QJsonObject jObj;
    jObj.insert("name",QJsonValue::fromVariant(po));
    jObj.insert("column_id",QJsonValue::fromVariant("5d36041b538eed0011572e28"));

    postRequest(jObj,"/cards");

}
void MainWindow::gloMoveCard()
{
    QJsonObject jObj;
    //QString pO=ui->POInput->text();
    //QString cardId=gloGetCardId(pO);
    //jObj.insert("column_id",cardId);
    //Select the column_id
    QString column=ui->buttonGroup_2->checkedButton()->text();
    //qDebug()<<column;
    if(column=="Sales Order")
        jObj.insert("column_id",QJsonValue::fromVariant("5d36041b538eed0011572e28"));//Sales Order
    else if(column=="Shipped")
        jObj.insert("column_id",QJsonValue::fromVariant("5d36042213853d0011ab778f"));//Shipped
    else if(column=="Border")
        jObj.insert("column_id",QJsonValue::fromVariant("5d3604684e1d32000f889e7a"));//Border
    else if(column=="Crossed")
        jObj.insert("column_id",QJsonValue::fromVariant("5d360471538eed0011572e35"));//Crossed
    else if(column=="Delivered")
        jObj.insert("column_id",QJsonValue::fromVariant("5d36047613853d0011ab7793"));//Delivered
    jObj.insert("position",QJsonValue::fromVariant(0));//Delivered
    //jObj.insert("column_id",QJsonValue::fromVariant("5d36041b538eed0011572e28"));
    postRequest(jObj,"/cards/"+currentCardid);
}

void MainWindow::gloAddComment(QString pO,QString comment)
{

    //QString cardId= gloGetCardId(ui->POInput->text());//Gets the cardId for the Po#
    QString path="/cards/"+currentCardid+"/comments";//Creates the post request url path
    QJsonObject send;
    send.insert("text",QJsonValue::fromVariant(comment));//Makes jsonobject with the message
    postRequest(send,path);//Call post request with the path and json object
}

QString MainWindow::gloGetCardId(QString po)
{
    QString returnId="-1";
    QString columnId;
    QJsonDocument temp;
    foreach (const QJsonValue &value,  getRequest("/cards",temp)) {
        QJsonObject json_obj = value.toObject();
        if((json_obj["name"].toString())==po)
        {
            returnId= json_obj["id"].toString();
            columnId=json_obj["column_id"].toString();
            break;
        }

    }
    if(columnId=="5d36041b538eed0011572e28")
    {
        //column="Sales Order";
        ui->RB_SalesOrder->setChecked(true);
        ui->order_progressBar->setValue(7);
    }

    else if(columnId=="5d36042213853d0011ab778f")
    {
        // column="Shipped";
        ui->RB_Shipped->setChecked(true);
        ui->order_progressBar->setValue(29);
    }
    else if(columnId=="5d3604684e1d32000f889e7a")
    {

        //column="Border";
        ui->RB_Border->setChecked(true);
        ui->order_progressBar->setValue(50);
    }
    else if(columnId=="5d360471538eed0011572e35")
    {

        //column="Crossed";
        ui->RB_Crossed->setChecked(true);
        ui->order_progressBar->setValue(75);
    }
    else if(columnId=="5d36047613853d0011ab7793")
    {
        //column="Delivered";
        ui->RB_Delivered->setChecked(true);
        ui->order_progressBar->setValue(100);
    }
    std::cout<<"The id for po: "+po.toStdString()+": "+returnId.toStdString();
    return returnId;
}

QString MainWindow::gloGetCardPosition(QString po)
{

    return nullptr;
}
//TODO:Make the Glo bords it's own class
//TODO:Make function to ge the comments for a card

void MainWindow::gloLoadComments()
{
    ui->gloComments->clear();
    QString path= "/cards/"+currentCardid+"/comments";
    int index=0;
    QJsonDocument temp;
    foreach (const QJsonValue &value,  getRequest(path,temp)) {
        QJsonObject json_obj = value.toObject();
        ui->gloComments->addItem(json_obj["text"].toString());
    }
}

void MainWindow::gloLoadLabels()
{

    QJsonDocument responseDoc;
    QJsonArray response=getRequest(("/cards/"+currentCardid+"?fields=labels"),responseDoc);
    QJsonObject tempObject= responseDoc.object();
    updateBlock=false;//block updates
    ui->gloLabelsClaimCust->setChecked(false);
    ui->gloLabelsClaimTaged->setChecked(false);
    ui->gloLabelsClaimClosed->setChecked(false);
    foreach (const QJsonValue &value,  (tempObject["labels"].toArray())) {
        QJsonObject json_obj = value.toObject();
        QString name=json_obj["name"].toString();
        if(name=="Claim-Customer")
        {
            labels.customer=true;
            ui->gloLabelsClaimCust->setChecked(true);
        }

        else if(name=="Claim-Taged")
        {
            labels.taged=true;
            ui->gloLabelsClaimTaged->setChecked(true);
        }

        else if(name=="Claim-Closed")
        {
            labels.closed=true;
            ui->gloLabelsClaimClosed->setChecked(true);
        }


        //ui->gloComments->addItem(json_obj["text"].toString());
    }
    updateBlock=true;
}

QByteArray MainWindow::postRequest(QJsonObject postData, QString path)
{
    QUrl url;
    url.setScheme("https");
    url.setHost("gloapi.gitkraken.com");
    url.setPath("/v1/glo/boards/5d360413538eed0011572e26"+path);

    //Formats and sends the packet
    QJsonDocument doc(postData);

    //qDebug()<<doc.toJson();

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QString rawAuth= "Bearer "+PAT;
    req.setRawHeader("Authorization",rawAuth.toUtf8());  //Take out before git push
    req.setRawHeader("Accept","application/json");
    QNetworkAccessManager man;
    QNetworkReply *reply =man.post(req,doc.toJson());

    while(!reply->isFinished())
    {
        qApp->processEvents();
    }


    QByteArray responseByte=reply->readAll();
    //qDebug()<<responseByte;
    return responseByte;
}


QJsonArray MainWindow::getRequest( QString path,QJsonDocument& docResponse)
{
    QUrl url;
    url.setScheme("https");
    url.setHost("gloapi.gitkraken.com");
    url.setPath("/v1/glo/boards/5d360413538eed0011572e26"+path);


    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QString rawAuth= "Bearer "+PAT;
    req.setRawHeader("Authorization",rawAuth.toUtf8());
    req.setRawHeader("Accept","application/json");
    QNetworkAccessManager man;
    QNetworkReply *reply =man.get(req);

    while(!reply->isFinished())
    {
        qApp->processEvents();
    }

    //Converts the get response into a json array
    QString strReply = (QString)reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    docResponse=jsonResponse;
    QJsonArray json_array = jsonResponse.array();
    QByteArray responseByte=reply->readAll();
    //qDebug()<<"The get data is: "+responseByte;
    return json_array;


}
void MainWindow::on_addCommentButton_clicked()
{
    QString tempNote=ui->notesDisplay->toPlainText();
    if(ui->notesArea->toPlainText().length()>0)
    {
        ui->notesDisplay->setText(tempNote+"\n"+userName+": "+ui->notesArea->toPlainText());
        gloAddComment(ui->POInput->text(),ui->notesArea->toPlainText());
        ui->notesArea->clear();
    }
    updateWindow();


}

void MainWindow::gloPushLabels()
{
    if(updateBlock)
    {
        QJsonObject jObj;
        QJsonArray label;
        QJsonObject temp;
        if(labels.customer)
        {
            temp.insert("id",QJsonValue::fromVariant("5d37256d13853d0011ab9008"));//Customer
            label.append(temp);
        }
        if(labels.taged)
        {
            temp.insert("id",QJsonValue::fromVariant("5d3b821e5afb5f000f3fd36f"));//Tagged
            label.append(temp);
        }
        if(labels.closed)
        {
            temp.insert("id",QJsonValue::fromVariant("5d372579538eed0011574725"));//closed
            label.append(temp);
        }

        jObj.insert("labels",label);
        QString path="/cards/"+currentCardid;
        postRequest(jObj,path);
    }
}
void MainWindow::on_gloLabelsClaimCust_stateChanged(int arg1)
{
    if(arg1==2)
        labels.customer=true;
    else
        labels.customer=false;
    gloPushLabels();
}

void MainWindow::on_gloLabelsClaimTaged_stateChanged(int arg1)
{
    if(arg1==2)
        labels.taged=true;
    else
        labels.taged=false;
    gloPushLabels();
}

void MainWindow::on_gloLabelsClaimClosed_stateChanged(int arg1)
{
    if(arg1==2)
        labels.closed=true;
    else
        labels.closed=false;
    gloPushLabels();
}


void MainWindow::on_POInput_textChanged(const QString &arg1)
{
    ui->gloFrame->setEnabled(false) ;
}

void MainWindow::on_archiveErrorList_itemDoubleClicked(QListWidgetItem *item)
{
    QString text=item->text();
    QString poNum=text.right(text.length()-mainDirectory.length()-1);
    std::cout<<poNum.toStdString()<<std::endl;
    ui->POInput->setText(poNum);
    ui->tabWidget->setCurrentIndex(0);
    openFolder(poNum,false);
}
void MainWindow::on_pushButton_clicked()
{
     QDesktopServices::openUrl ( QUrl("https://app.gitkraken.com/glo/board/XTYEE1OO7QARVy4m"));
}
