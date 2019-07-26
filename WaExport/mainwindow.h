#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <shellapi.h>
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
#include "folderio.h"
#include <mytablemodel.h>
#include <helpcenter.h>
#include <archivecheck.h>
#include <settingd.h>
#include <aboutwindow.h>
#include <helpcenter.h>
#include <settingd.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QString getMainDirectory();
    ~MainWindow();

    void loadSettings();
protected:

    void dragEnterEvent(QDragEnterEvent *event);
      void dropEvent(QDropEvent *event);
protected slots:

private slots:
      void on_openFolder_clicked();
      void openDirectory(QString );
      void on_actionOpen_triggered();
      void on_mexP_Spreadsheets_upload_clicked();
      void on_saveButton_clicked();
      void on_POInput_returnPressed();
      void on_mexP_Invoice_upload_clicked();
      void on_mexP_Phyto_upload_clicked();
      void on_mexP_ShipperConf_upload_clicked();
      void on_mexP_CarrierConf_upload_clicked();
      void on_mexP_Passing_upload_clicked();
      void on_mexP_SaleConf_upload_clicked();
      void on_mexP_SignedSale_upload_clicked();
      void on_mexP_Pedimento_upload_clicked();
      void on_mexP_ProduceInv_upload_clicked();
      void on_mexP_Payable_Shipper_upload_clicked();
      void on_mexP_Payables_Carriers_upload_clicked();
      void on_mexP_Spreadsheets_stateChanged(int arg1);
      void on_mexP_Invoice_stateChanged(int arg1);
      void on_mexP_Phyto_stateChanged(int arg1);
      void on_mexP_ShipperConf_stateChanged(int arg1);
      void on_mexP_CarrierConf_stateChanged(int arg1);
      void on_mexP_Passing_stateChanged(int arg1);
      void on_mexP_SaleConf_stateChanged(int arg1);
      void on_mexP_SignedSale_stateChanged(int arg1);
      void on_mexP_Pedimento_stateChanged(int arg1);
      void on_mexP_ProduceInv_stateChanged(int arg1);
      void on_mexP_Payable_Shipper_stateChanged(int arg1);
      void on_mexP_Payables_Carriers_stateChanged(int arg1);
      void on_reloadButton_clicked();
      void on_POInput_editingFinished();
      void on_ExpInvima_stateChanged(int arg1);
      void on_FacturaComercial_stateChanged(int arg1);
      void on_ListadeEmpaque_stateChanged(int arg1);
      void on_CertOrigin_stateChanged(int arg1);
      void on_CaftaNafta_stateChanged(int arg1);
      void on_FreightContract_stateChanged(int arg1);
      void on_Transloader_stateChanged(int arg1);
      void on_Harris_stateChanged(int arg1);
      void on_HarrisEmails_stateChanged(int arg1);
      void on_CustomerPO_stateChanged(int arg1);
      void on_OtherEmails_stateChanged(int arg1);
      void on_Payables_Transloader_stateChanged(int arg1);
      void on_payables_TruckFreight_stateChanged(int arg1);
      void on_Payables_Harris_stateChanged(int arg1);
      void on_Payables_ShipperWarehouse_stateChanged(int arg1);
      void on_comboBox_currentIndexChanged(int index);
      void on_receipts_stateChanged(int arg1);
      void on_ExpInvima_Upload_clicked();
      void on_receipts_upload_clicked();
      void on_FacturaComercial_upload_clicked();
      void on_ListadeEmpaque_upload_clicked();
      void on_CertOrigin_upload_clicked();
      void on_CaftaNafta_upload_clicked();
      void on_FreightContract_upload_clicked();
      void on_Transloader_upload_clicked();
      void on_Harris_upload_clicked();
      void on_HarrisEmails_upload_clicked();
      void on_CustomerPO_upload_clicked();
      void on_OtherEmails_upload_clicked();
      void on_Payables_Transloader_upload_clicked();
      void on_payables_TruckFreight_upload_clicked();
      void on_Payables_Harris_upload_clicked();
      void on_Payables_ShipperWarehouse_upload_clicked();
      void on_archiveCheckButton_clicked();
      void on_tableView_doubleClicked(const QModelIndex &index);
      void on_archiveCheckButton_2_clicked();
      void on_actionAbout_triggered();
      void on_actionHelp_Center_triggered();
      // void on_actionSettings_triggered();
      void on_actionSettings_2_triggered();
      void on_otherFiles_upload_clicked();


      void on_RB_SalesOrder_clicked();

      void on_RB_Shipped_clicked();

      void on_RB_Border_clicked();

      void on_RB_Crossed_clicked();

      void on_RB_Delivered_clicked();

      void on_testSocketButton_clicked();


       void on_addCommentButton_clicked();


private:
    Ui::MainWindow *ui;
    HelpCenter *helpP;

    myTableModel *tableModel;
   // settingD *settingD;
   // ArchiveCheck *aCheck;
    //void openDirectory(QString );
    QString mainDirectory="NULL";
    QString userName="";
    QString PAT="";
    void openFolder(QString folderText,bool winEx);
    QString filesRequired [30]={NULL};
    void closeEvent(QCloseEvent *bar);


    void updateWindow();
    void uploadFile(std::string fileDialog1, std::string fileDialog2, QString destFileName);
    void uncheckAll();
    std::ostringstream getRequiredFiles();
    void updateWindowT(int num);
    void createShortcut(std::string fileDialog1, std::string fileDialog2, QString destFileName);
    void updateChecked();

    //bool readFile(const QString &fileName);
    QByteArray postRequest(QJsonObject postData, QString path);


    void gloCreatePO(QString po);
    void gloMoveCard();
    QJsonArray getRequest( QString path);
    void gloAddComment(QString cardId, QString comment);
    QString gloGetCardId(QString po);
};

#endif // MAINWINDOW_H





