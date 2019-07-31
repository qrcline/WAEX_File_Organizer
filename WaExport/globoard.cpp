#include "globoard.h"
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

gloBoard::gloBoard(QString pat,Ui::MainWindow* ui)
{
    PAT=pat;
    uiPointer=ui;
}

QJsonArray gloBoard::getRequest( QString path)
{
    QUrl url;
    url.setScheme("https");
    url.setHost("gloapi.gitkraken.com");
    url.setPath("/v1/glo/boards/5d360413538eed0011572e26"+path);


    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QString rawAuth= "Bearer "+PAT;
    req.setRawHeader("Authorization",rawAuth.toUtf8());  //Take out before git push
    req.setRawHeader("Accept","application/json");
    QNetworkAccessManager man;
    QNetworkReply *reply =man.get(req);

    while(!reply->isFinished())
    {
        qApp->processEvents();
    }

    //Converts the get response into a json array
    QString strReply = (QString)reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonArray json_array = jsonResponse.array();
    QByteArray responseByte=reply->readAll();
    qDebug()<<responseByte;
    return json_array;

}


QByteArray gloBoard::postRequest(QJsonObject postData, QString path)
{
    QUrl url;
    url.setScheme("https");
    url.setHost("gloapi.gitkraken.com");
    url.setPath("/v1/glo/boards/5d360413538eed0011572e26"+path);

    //Formats and sends the packet
    QJsonDocument doc(postData);

    //qDebug()<<doc.toJson();

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QString rawAuth= "Bearer "+PAT;
    req.setRawHeader("Authorization",rawAuth.toUtf8());  //Take out before git push
    req.setRawHeader("Accept","application/json");
    QNetworkAccessManager man;
    QNetworkReply *reply =man.post(req,doc.toJson());

    while(!reply->isFinished())
    {
        qApp->processEvents();
    }


    QByteArray responseByte=reply->readAll();
    qDebug()<<responseByte;
    return responseByte;
}

QString gloBoard::GetCardPosition(QString po)
{

    return nullptr;
}
//TODO:Make the Glo bords it's own class
//TODO:Make function to ge the comments for a card

void gloBoard::gloLoadComments(QString currentCarid)
{
    uiPointer->gloComments->clear();
    QString path= "/cards/"+currentCarid+"/comments";
    int index=0;
    foreach (const QJsonValue &value,  getRequest(path)) {
        QJsonObject json_obj = value.toObject();
        uiPointer->gloComments->addItem(json_obj["text"].toString());
    }
}


QString gloBoard::gloGetCardId(QString po)
{
    QString returnId="-1";
    QString columnId;
    foreach (const QJsonValue &value,  getRequest("/cards")) {
        QJsonObject json_obj = value.toObject();
        if((json_obj["name"].toString())==po)
        {
            returnId= json_obj["id"].toString();
            columnId=json_obj["column_id"].toString();
            break;
        }

    }
    if(columnId=="5d36041b538eed0011572e28")
    {
        //column="Sales Order";
        uiPointer->RB_SalesOrder->setChecked(true);
        uiPointer->order_progressBar->setValue(7);
    }

    else if(columnId=="5d36042213853d0011ab778f")
    {
        // column="Shipped";
        uiPointer->RB_Shipped->setChecked(true);
        uiPointer->order_progressBar->setValue(29);
    }
    else if(columnId=="5d3604684e1d32000f889e7a")
    {

        //column="Border";
        uiPointer->RB_Border->setChecked(true);
        uiPointer->order_progressBar->setValue(50);
    }
    else if(columnId=="5d360471538eed0011572e35")
    {

        //column="Crossed";
        uiPointer->RB_Crossed->setChecked(true);
        uiPointer->order_progressBar->setValue(75);
    }
    else if(columnId=="5d36047613853d0011ab7793")
    {
        //column="Delivered";
        uiPointer->RB_Delivered->setChecked(true);
        uiPointer->order_progressBar->setValue(100);
    }
    std::cout<<"The id for po: "+po.toStdString()+": "+returnId.toStdString();
    return returnId;
}

void gloBoard::gloAddComment(QString pO,QString comment,QString currentCardid)
{

    //QString cardId= gloGetCardId(ui->POInput->text());//Gets the cardId for the Po#
    QString path="/cards/"+currentCardid+"/comments";//Creates the post request url path
    QJsonObject send;
    send.insert("text",QJsonValue::fromVariant(comment));//Makes jsonobject with the message
    postRequest(send,path);//Call post request with the path and json object
}

void gloBoard::gloCreatePO(QString po)
{
    QString message= "{\"name\":\""+po+"\",\"position\":\"0\",\"column_id\":\"5d36042213853d0011ab778f\"}";
    QByteArray sendMessage=message.toUtf8();
    QJsonObject jObj;
    jObj.insert("name",QJsonValue::fromVariant(po));
    jObj.insert("column_id",QJsonValue::fromVariant("5d36041b538eed0011572e28"));

    postRequest(jObj,"/cards");

}

void gloBoard::gloMoveCard(QString currentCardid)
{
    QJsonObject jObj;
    //QString pO=ui->POInput->text();
    //QString cardId=gloGetCardId(pO);
    //jObj.insert("column_id",cardId);
    //Select the column_id
    QString column=uiPointer->buttonGroup_2->checkedButton()->text();
    //qDebug()<<column;
    if(column=="Sales Order")
        jObj.insert("column_id",QJsonValue::fromVariant("5d36041b538eed0011572e28"));//Sales Order
    else if(column=="Shipped")
        jObj.insert("column_id",QJsonValue::fromVariant("5d36042213853d0011ab778f"));//Shipped
    else if(column=="Border")
        jObj.insert("column_id",QJsonValue::fromVariant("5d3604684e1d32000f889e7a"));//Border
    else if(column=="Crossed")
        jObj.insert("column_id",QJsonValue::fromVariant("5d360471538eed0011572e35"));//Crossed
    else if(column=="Delivered")
        jObj.insert("column_id",QJsonValue::fromVariant("5d36047613853d0011ab7793"));//Delivered
    jObj.insert("position",QJsonValue::fromVariant(0));//Delivered
    //jObj.insert("column_id",QJsonValue::fromVariant("5d36041b538eed0011572e28"));
    postRequest(jObj,"/cards/"+currentCardid);
}
