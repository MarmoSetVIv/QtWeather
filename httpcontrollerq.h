#ifndef HTTPCONTROLLERQ_H
#define HTTPCONTROLLERQ_H

#include <QNetworkAccessManager>

class HttpControllerQ
{
public:
    HttpControllerQ();
    QNetworkAccessManager *nam;
    QString getcondition() const;
    QString getwind_dir() const;
    QString getdaytime() const;
    QString getcseason() const;
    QString getData() const;
    QVariant getwind_gust() const;
    int gettemp() const;
    int getfeels_like() const;
    int getwind_speed() const;
    int getprec_type() const;
    int getpressure_mm() const;

public slots:
    void restRequest();
    void PictureRequest();
private:
    int temp;
    int feels_like;
    QString condition;
    int wind_speed;
    QVariant wind_gust;
    QString wind_dir;
    QString daytime;
    QString season;
    QString cartun;
    QString DataCArt;
    int prec_type;
    int pressure_mm;
};

#endif // HTTPCONTROLLERQ_H
