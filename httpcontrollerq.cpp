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
#include <weekclass.h>
#include <QPixmap>

HttpControllerQ::HttpControllerQ()
{
    nam = new QNetworkAccessManager(); // создаем менеджер
    //  connect(nam, &QNetworkAccessManager::finished, this, &HttpController::SlotFinished);

}

int HttpControllerQ::gettemp() const{ // функция для получения id друга
    return temp;
}

int HttpControllerQ::getfeels_like() const{ // функция для получения id друга
    return feels_like;
}

int HttpControllerQ::getwind_speed() const{ // функция для получения id друга
    return wind_speed;
}

int HttpControllerQ::getprec_type() const{ // функция для получения id друга
    return prec_type;
}

int HttpControllerQ::getpressure_mm() const{ // функция для получения id друга
    return pressure_mm;
}

QString HttpControllerQ::getcondition() const{ // функция для получения имени друга
    return condition;
}

QString HttpControllerQ::getwind_dir() const{ // функция для получения фамилии друга
    return wind_dir;
}

QString HttpControllerQ::getdaytime() const{ // функция для получения фамилии друга
    return daytime;
}

QString HttpControllerQ::getcseason() const{ // функция для получения фамилии друга
    return season;
}

QVariant HttpControllerQ::getwind_gust() const{ // функция для получения id друга
    return wind_gust;
}

QString HttpControllerQ::getData() const{ // функция для получения фамилии друга
    return cartun;
}


//void HttpControllerQ::PictureRequest(QUrl url)
//{
////    QUrl url = "https://yastatic.net/weather/i/icons/funky/dark/"+cartun+".svg";
//    qDebug() <<"rjr" << url;
//    QEventLoop loop;
//    nam = new QNetworkAccessManager();
//    QNetworkRequest request(url);
//    QNetworkReply *reply = nam->get(request);
//    QObject::connect(nam, // связываем loop  с нашим менеджером
//                     SIGNAL(finished(QNetworkReply*)),
//                     &loop,
//                     SLOT(quit()));
//    loop.exec();
//    QPixmap pixmap;
//    pixmap.loadFromData(reply->readAll());
////    qDebug() <<"rjr" << cartun;
//     reply->deleteLater();

//}

void HttpControllerQ::restRequest()
{
    QEventLoop loop;
    nam = new QNetworkAccessManager();
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
        QJsonValue itogFact = root.value("fact");
        QJsonObject ParsFact = itogFact.toObject();
//        QJsonArray array = itog.toArray();
//           qDebug() <<"Наш itog"<< root;
//            qDebug() << "Наш поп" << pop;
//            qDebug() <<"Наш itog"<< array;
        for(int i = 0; i < ParsFact.length(); i++){
             QJsonObject znach = ParsFact;
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
              cartun = znach.value("icon").toString();
        }

//        QJsonValue itogForc = root.value("forecasts"); //  данный кусок надо доделать
//        QJsonObject ParsForecasts  = itogForc.toObject();
//        qDebug() <<"yfi ger" << ParsForecasts;
//        for(int i = 0; i < root.length(); i++){
//             QJsonObject znach = root;
//     //       // Забираем значения свойств имени

//             QString m_datex = znach.value("date").toString();
//             qDebug() <<"yfi ger" << m_datex;
//             int m_temp_max = znach.value("temp_max").toInt();
//             qDebug() <<"yfi ger" << m_temp_max;
//             int m_temp_min= znach.value("temp_min").toInt();
//             int m_temp_avg= znach.value("temp_avg").toInt();
//             int m_temp= znach.value("temp").toInt();
//             int m_prec_strength= znach.value("prec_strength").toInt();

////              qDebug() <<"Температура" << temp;
//             weekModel->addItem(WeekClass(m_datex,m_temp_max,m_temp_min,m_temp_avg,m_temp,m_prec_strength));
//             qDebug() <<"yfi ger" << weekModel->Weekdata;
//             qDebug() <<"yfi ger" << weekModel->WeekTempMax;
//             qDebug() <<"yfi ger" << weekModel->WeekTempMin;
//             qDebug() <<"yfi ger" << weekModel->WeekTempAvg;
//             qDebug() <<"yfi ger" << weekModel->WeekTemp;
//             qDebug() <<"yfi ger" << weekModel->WeekPrecStrength;

//        }

//        qDebug() <<"Температура" << week;

//        qDebug() <<"Ощущаеться как" << feels_like;
//        qDebug()  <<"Обозначение" << condition;
//        qDebug() <<"Скорость ветра" << wind_speed;
//        qDebug() <<"Скорость порывов ветра" << wind_gust;
//        qDebug() <<"Направление ветра"<< wind_dir;
//        qDebug() <<"Светлое или темное время суток"<< daytime;
//        qDebug() <<"Время года в данном населенном пункте"<< season;
//        qDebug() <<"Тип осадков."<< prec_type;
//        qDebug() <<"Давление"<< pressure_mm;
//        qDebug() << "картинка" << cartun;
        reply->deleteLater();
//        PictureRequest();







}
