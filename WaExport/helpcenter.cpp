#include "helpcenter.h"
#include "ui_helpcenter.h"

HelpCenter::HelpCenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelpCenter)
{
    ui->setupUi(this);
}

HelpCenter::~HelpCenter()
{
    delete ui;
}
