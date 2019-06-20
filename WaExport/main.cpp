#include "mainwindow.h"
#include <QApplication>
#pragma once
int main(int argc, char *argv[])
{
    #pragma comment(lib, "shell32")
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
