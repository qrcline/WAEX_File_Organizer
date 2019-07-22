#include "helpcenter.h"
#include "ui_helpcenter.h"

HelpCenter::HelpCenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelpCenter)
{
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
}

HelpCenter::~HelpCenter()
{
    delete ui;
}
