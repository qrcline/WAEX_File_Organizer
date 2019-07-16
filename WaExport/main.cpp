#include "mainwindow.h"
#include "helpcenter.h"
#include <QApplication>
#include <qsettings.h>
#pragma once


void setStyleSheet(QApplication * a)
{
    //Retreve the theme
    QSettings setting("WAEX","Organizer");
    setting.beginGroup("Settings");
    QString theme=setting.value("theme","Light").toString();
    setting.endGroup();

    if(theme=="Dark")
    {
        std::cout<<"The theme is: "+theme.toStdString()<<std::endl;
//        a->setStyleSheet();
//         //a->setStyleSheet("QPushButton {color: rgb(255, 255, 255)}");
//         //a->setStyleSheet("QPushButton { border-color: rgb(49, 245, 255)}");
//        //a->setStyleSheet("QPushButton {border-radius: 5px }");
//        //a->setStyleSheet("QPushButton {background-color: rgb(51, 51, 51)}");

//        a->setStyleSheet("color: blue;"
//                                "background-color: yellow;"
//                                "selection-color: yellow;"
//                                "selection-background-color: blue;");

    }
    else
        a->setStyleSheet("");
}
int main(int argc, char *argv[])
{
    #pragma comment(lib, "shell32")
    QApplication a(argc, argv);
    setStyleSheet(&a);
    MainWindow w;
    w.show();





    return a.exec();
}
