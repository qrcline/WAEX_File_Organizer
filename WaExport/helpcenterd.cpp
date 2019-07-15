#include "helpcenterd.h"
#include "ui_helpcenterd.h"

helpCenterD::helpCenterD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::helpCenterD)
{
    ui->setupUi(this);
}

helpCenterD::~helpCenterD()
{
    delete ui;
}
