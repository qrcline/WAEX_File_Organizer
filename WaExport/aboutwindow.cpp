#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    QPixmap waexPix(":/pictures/smalleWAEXLOGO.png");
    QPixmap img2=waexPix.scaled(160,190,Qt::KeepAspectRatio);
    ui->aboutLogo->setPixmap(img2);
   this->setWindowTitle("About");
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_pushButton_clicked()
{
    close();
}
