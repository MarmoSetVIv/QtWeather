#ifndef HTTPCONTROLLERQ_H
#define HTTPCONTROLLERQ_H

#include <QNetworkAccessManager>

class HttpControllerQ
{
public:
    HttpControllerQ();
    QNetworkAccessManager *nam;
public slots:
    void restRequest();
};

#endif // HTTPCONTROLLERQ_H
