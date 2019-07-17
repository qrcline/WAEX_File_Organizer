#include "settingd.h"
#include "ui_settingd.h"
#include "QSettings.h"
#include "mainwindow.h"

settingD::settingD(QWidget *parent,Ui::MainWindow* mainWindow) :
    QDialog(parent),
    ui(new Ui::settingD)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings");
    setup();
    uiPointer=parent;

}

settingD::~settingD()
{
    delete ui;
}

void settingD::on_settingsClose_clicked()
{
    QString theme= ui->settingsColorScheme->currentText();


    QSettings setting("WAEX","Organizer");
    setting.beginGroup("Settings");
    setting.setValue("theme",theme);
    if(ui->settingsToolTips->isChecked())
        setting.setValue("tTip","True");
    else
        setting.setValue("tTip","False");
    setting.endGroup();
    MainWindow mWindow;
    mWindow.loadSettings(); //TODO: Make it so that the settings can be refreshed for the mainwindow
    close();

}


void settingD::setup()
{
    QSettings setting("WAEX","Organizer");
    setting.beginGroup("Settings");
    QString tTip=setting.value("tTip","False").toString();
    if(tTip=="True")
        ui->settingsToolTips->setChecked(true);
    else
         ui->settingsToolTips->setChecked(false);
    setting.endGroup();
}

void settingD::closeEvent(QCloseEvent *bar)
{
//    QSettings setting("WAEX","Organizer");
//    setting.beginGroup("Settings");
//    setting.setValue("workDirec",mainDirectory);
//    setting.endGroup();
    QWidget::closeEvent(bar);
}

