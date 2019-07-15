#include "settingd.h"
#include "ui_settingd.h"
#include "QSettings.h"

settingD::settingD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingD)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings");
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
    setting.endGroup();



    close();
}
