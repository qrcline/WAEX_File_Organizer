#ifndef GLOBOARD_H
#define GLOBOARD_H
#include "string"
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "filesystem"
#include "folderio.h"
#include <sstream>
#include <archivecheck.h>
#include <QSettings>
#include <QtCore>
#include <thread>
#include <QtGui>
#include <QInputDialog>
#include <QNetworkAccessManager>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QVariant>
#include <QtDebug>
#include <QSsl>


class gloBoard
{
public:
    gloBoard(QString pat,Ui::MainWindow* ui);
    QJsonArray getRequest(QString path);
    QByteArray postRequest(QJsonObject postData, QString path);
    QString GetCardPosition(QString po);



    void gloLoadComments(QString currentCarid);
    QString gloGetCardId(QString po);
    void gloAddComment(QString pO, QString comment,QString currentCardid);
    void gloCreatePO(QString po);
    void gloMoveCard(QString currentCardid);
public slots:

private:
    QString PAT;
    Ui::MainWindow* uiPointer;


};

#endif // GLOBOARD_H
