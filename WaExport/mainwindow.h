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

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

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

private:
    Ui::MainWindow *ui;
    //void openDirectory(QString );
    QString mainDirectory=nullptr;
    void openFolder();


    void updateWindow();
    void uploadFile(std::string fileDialog1, std::string fileDialog2, QString destFileName);
};

#endif // MAINWINDOW_H
