#include "settingd.h"
#include "ui_settingd.h"
#include "QSettings.h"
#include "mainwindow.h"
#include <qdesktopservices.h>

settingD::settingD(QWidget *parent,Ui::MainWindow* uiMain) :
    QDialog(parent),
    ui(new Ui::settingD)
{
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    this->setWindowTitle("Settings");
    setup();
   mainUi=uiMain;
setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

settingD::~settingD()
{
    delete ui;
}

void settingD::on_settingsClose_clicked()
{
    //QString theme= ui->settingsColorScheme->currentText();


    QSettings setting("WAEX","Organizer");
    setting.beginGroup("Settings");
    //setting.setValue("theme",theme);
    if(ui->settingsToolTips->isChecked())
        setting.setValue("tTip","True");
    else
        setting.setValue("tTip","False");
    setting.setValue("User",ui->settingsUserName->text());
    setting.setValue("PAT",ui->settingsPAT->text());
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
    ui->settingsUserName->setText(setting.value("User","").toString());
     ui->settingsPAT->setText(setting.value("PAT","").toString());
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


void settingD::on_pushButton_clicked()
{
   // https://app.gitkraken.com/pats/new
  QDesktopServices::openUrl ( QUrl("https://app.gitkraken.com/pats/new"));
}
