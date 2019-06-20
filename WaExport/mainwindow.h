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

private:
    Ui::MainWindow *ui;
    //void openDirectory(QString );
    QString mainDirectory=nullptr;


};

#endif // MAINWINDOW_H
