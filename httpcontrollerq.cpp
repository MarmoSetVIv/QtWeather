#include "httpcontrollerq.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QEventLoop>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QDebug>
#include <iostream>
#include <QString>
#include <QByteArray>

HttpControllerQ::HttpControllerQ()
{
    nam = new QNetworkAccessManager(); // создаем менеджер
    //  connect(nam, &QNetworkAccessManager::finished, this, &HttpController::SlotFinished);


}

void HttpControllerQ::restRequest()
{

    int temp;
    int feels_like;
    QString condition;
    int wind_speed;
    QVariant wind_gust;
    QString wind_dir;
    QString daytime;
    QString season;
    int prec_type;
    int pressure_mm;

    QEventLoop loop;
    nam = new QNetworkAccessManager();
//    qDebug() << request1.url();

//    QNetworkReply *reply = nam->get(QNetworkRequest(QUrl("https://api.weather.yandex.ru/v2/informers?lat=55.75396&lon=37.620393")));
    QNetworkRequest request(QUrl("https://api.weather.yandex.ru/v2/forecast?lat=55.75396&lon=37.620393&extra=true"));
//    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    //    request.setRawHeader("Content-Type","");
    request.setRawHeader("X-Yandex-API-Key","40a29d7d-f83f-4cfd-ac3c-11811df18907");
//    qDebug() << "Наша nam" <<;
    QNetworkReply *reply = nam->get(request);
    QObject::connect(nam, // связываем loop  с нашим менеджером
                     SIGNAL(finished(QNetworkReply*)),
                     &loop,
                     SLOT(quit()));
    loop.exec();
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject root = document.object();
//        array = root.value("fact").toArray();
//        qDebug() << "Наша URL-ka" << root;
        QJsonValue itog = root.value("fact");
        QJsonObject pop = itog.toObject();
//        QJsonArray re = {"cloudness":1,"condition":"overcast","daytime":"d","feels_like":1,"humidity":39,"icon":"ovc",
//                         "is_thunder":false,"obs_time":1649152800,"polar":false,"prec_prob":0,"prec_strength":0,
//                         "prec_type":0,"pressure_mm":734,"pressure_pa":978,"season":"spring","soil_moisture":0.38,"soil_temp":0,
//                         "source":"station","temp":4,"uptime":1649153412,"uv_index":3,"wind_dir":"s","wind_gust":10.5,"wind_speed":1};
//        QByteArray  array1 =
//        QJsonArray array = itog.toArray();
//            qDebug() <<"Наш itog"<< itog;
//            qDebug() << "Наш поп" << pop;
//            qDebug() <<"Наш itog"<< array;
        for(int i = 0; i < pop.length(); i++){
             QJsonObject znach = pop;
     //       // Забираем значения свойств имени
              temp = znach.value("temp").toInt();
//              qDebug() <<"Температура" << temp;
              feels_like = znach.value("feels_like").toInt();
//              qDebug() <<"Ощущаеться как" << feels_like;
              condition = znach.value("condition").toString();
//              qDebug()  <<"Обозначение" << condition;
              wind_speed = znach.value("wind_speed").toInt();
//              qDebug() <<"Скорость ветра" << wind_speed;
              wind_gust = znach.value("wind_gust").toVariant();
//              qDebug() <<"Скорость порывов ветра" << wind_gust;
              wind_dir = znach.value("wind_dir").toString();
//              qDebug() <<"Направление ветра"<< wind_dir;
              daytime = znach.value("daytime").toString();
//              qDebug() <<"Направление ветра"<< daytime;
              season = znach.value("season").toString();
//              qDebug() <<"Светлое или темное время суток"<< season;
              prec_type = znach.value("prec_type").toInt();
//              qDebug() <<"Тип осадков."<< prec_type;
              pressure_mm = znach.value("pressure_mm").toInt();
//              qDebug() <<"Давление"<< pressure_mm;

        }

        qDebug() <<"Температура" << temp;
        qDebug() <<"Ощущаеться как" << feels_like;
        qDebug()  <<"Обозначение" << condition;
        qDebug() <<"Скорость ветра" << wind_speed;
        qDebug() <<"Скорость порывов ветра" << wind_gust;
        qDebug() <<"Направление ветра"<< wind_dir;
        qDebug() <<"Светлое или темное время суток"<< daytime;
        qDebug() <<"Время года в данном населенном пункте"<< season;
        qDebug() <<"Тип осадков."<< prec_type;
        qDebug() <<"Давление"<< pressure_mm;







}
