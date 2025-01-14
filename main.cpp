/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QApplication>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QNetworkReply>
#include <httpcontrollerq.h>
#include <QLabel>
#include <QDialog>
#include <QHBoxLayout>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    HttpControllerQ pep;
    pep.restRequest();


    QDialog *dialog = new QDialog;
    dialog->setGeometry(dialog->x(), dialog->y(), 250, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    QHBoxLayout *layoutHedder = new QHBoxLayout;
    QHBoxLayout *CenterLayout = new QHBoxLayout;
    QVBoxLayout *layoutLeft = new QVBoxLayout;
    QVBoxLayout *layoutRight = new QVBoxLayout;
    QHBoxLayout *layoutBottem = new QHBoxLayout;

    mainLayout->addLayout(layoutHedder);
    layoutHedder->setAlignment(Qt::AlignTop);
    layoutHedder->setAlignment(Qt::AlignHCenter);

    mainLayout->addLayout(CenterLayout);
    CenterLayout->addLayout(layoutLeft);
    layoutLeft->setAlignment(Qt::AlignLeft);
    CenterLayout->addLayout(layoutRight);
    layoutRight->setAlignment(Qt::AlignRight);

    mainLayout->addLayout(layoutBottem);
    layoutBottem->setAlignment(Qt::AlignBottom);

    QLabel *label1 = new QLabel;
    label1->setText("<font color=red>Доброго времени суток! Погода по Москве </font>");
    label1->setAlignment(Qt::AlignHCenter);
//    label1->setAutoFillBackground(true);

//Левая

//    QPixmap *cartun = new QPixmap(":resourse/icons/WeatherIcon - 1-32.png");
//    QSize sizeCart(35,35);
//    QLabel *labelCart = new QLabel;
//    QString ChangeIcon = "";
//    if(pep.getData() == "ovc"){
//        cartun->load(":resourse/icons/WeatherIcon - 1-32.png");
//    }
//    else if (pep.getwind_dir() == "n") {
////        ChangeWinDir = "Северное.";
//    }
////    cartun->load("/icons/WeatherIcon - 1-32.png");
//    labelCart->setPixmap(cartun->scaled(sizeCart,Qt::KeepAspectRatio));
//    labelCart->setMargin(35);

    QLabel *labelTemp = new QLabel;
    QFont font = labelTemp->font();
    labelTemp->setText(QString::number(pep.gettemp())+"°С");
    font.setPointSize(35);
    labelTemp->setFont(font);
    labelTemp->setAlignment(Qt::AlignRight);
    labelTemp->setMargin(2);
//    label2->setMargin(10);
//правая
    QLabel *labelWind_speed = new QLabel;
    labelWind_speed->setText("<font color=green>Скорость ветра: </font>"+QString::number(pep.getwind_speed())+"м/с");
    labelWind_speed->setAlignment(Qt::AlignRight);
    labelWind_speed->setMargin(1);

    QLabel *labelWind_gust = new QLabel;
    labelWind_gust->setText("<font color=green>Скорость порывов: </font>"+QVariant(pep.getwind_gust()).toString()+"м/с");
    labelWind_gust->setAlignment(Qt::AlignRight);
    labelWind_gust->setMargin(1);

    QString ChangeWinDir = "";
    if(pep.getwind_dir() == "nw"){
        ChangeWinDir = "Северо-западное.";
    }
    else if (pep.getwind_dir() == "n") {
        ChangeWinDir = "Северное.";
    }
    else if (pep.getwind_dir() == "ne") {
        ChangeWinDir = "Северо-восточное.";
    }
    else if (pep.getwind_dir() == "e") {
        ChangeWinDir = "Восточное.";
    }
    else if (pep.getwind_dir() == "se") {
        ChangeWinDir = "Юго-восточное.";
    }
    else if (pep.getwind_dir() == "s") {
        ChangeWinDir = "Южное.";
    }
    else if (pep.getwind_dir() == "sw") {
        ChangeWinDir = "Юго-западное.";
    }
    else if (pep.getwind_dir() == "w") {
        ChangeWinDir = "Западное.";
    }
    else if (pep.getwind_dir() == "c") {
        ChangeWinDir = "Штиль.";
    }

    QLabel *labelWind_dir = new QLabel;
    labelWind_dir->setText("<font color=green>Направление: </font>"+ChangeWinDir);
    labelWind_dir->setAlignment(Qt::AlignRight);
    labelWind_dir->setMargin(1);

    QLabel *labelPressure_mm = new QLabel;
    labelPressure_mm->setText("<font color=green>Давление: </font>"+QString::number(pep.getpressure_mm())+"mm");
    labelPressure_mm->setAlignment(Qt::AlignRight);
    labelPressure_mm->setMargin(1);

    QLabel *labelFeelsLick = new QLabel;
    labelFeelsLick->setText("<font color=green>Ощущаеться: </font>"+QString::number(pep.getfeels_like())+"°С");
    labelFeelsLick->setAlignment(Qt::AlignRight);
    labelFeelsLick->setMargin(2);


    QString ChangePrec = "";
    if(pep.getprec_type() == 0){
        ChangePrec = "Без осадков.";
    }
    else if (pep.getprec_type() == 1) {
        ChangePrec = "Дождь.";
    }
    else if (pep.getprec_type() == 2) {
        ChangePrec = "Дождь со снегом.";
    }
    else if (pep.getprec_type() == 3) {
        ChangePrec = "Снег.";
    }
    else if (pep.getprec_type() == 4) {
        ChangePrec = "Град.";
    }

    QLabel *labelPrec_type = new QLabel;
//    labelPrec_type->setText("<font color=green>Тип осадков </font>"+QString::number(pep.getprec_type()));
    labelPrec_type->setText("<font color=green>Тип осадков: </font>"+ChangePrec);
    labelPrec_type->setAlignment(Qt::AlignRight);
    labelPrec_type->setMargin(2);

    QString Changecond = "";
    if(pep.getcondition() == "clear"){
        Changecond = "Ясно.";
    }
    else if (pep.getcondition() == "partly-cloudy") {
        Changecond = "Малооблачно.";
    }
    else if (pep.getcondition() == "cloudy") {
        Changecond = "Облачно с прояснениями.";
    }
    else if (pep.getcondition() == "overcast") {
        Changecond = "Пасмурно.";
    }
    else if (pep.getcondition() == "drizzle") {
        Changecond = "Морось.";
    }
    else if (pep.getcondition() == "light-rain") {
        Changecond = "Небольшой дождь.";
    }
    else if (pep.getcondition() == "rain") {
        Changecond = "Дождь.";
    }
    else if (pep.getcondition() == "moderate-rain") {
        Changecond = "Умеренно сильный дождь.";
    }
    else if (pep.getcondition() == "heavy-rain") {
        Changecond = "Сильный дождь.";
    }
    else if (pep.getcondition() == "continuous-heavy-rain") {
        Changecond = "Длительный сильный дождь.";
    }
    else if (pep.getcondition() == "showers") {
        Changecond = "Ливень.";
    }
    else if (pep.getcondition() == "wet-snow") {
        Changecond = "Дождь со снегом.";
    }
    else if (pep.getcondition() == "light-snow") {
        Changecond = "Небольшой снег.";
    }
    else if (pep.getcondition() == "snow") {
        Changecond = "Снег";
    }
    else if (pep.getcondition() == "snow-showers") {
        Changecond = "Снегопад.";
    }
    else if (pep.getcondition() == "hail") {
        Changecond = "Град.";
    }
    else if (pep.getcondition() == "thunderstorm") {
        Changecond = "Гроза.";
    }
    else if (pep.getcondition() == "thunderstorm-with-rain") {
        Changecond = "Дождь с грозой.";
    }
    else if (pep.getcondition() == "thunderstorm-with-hail") {
        Changecond = "Гроза с градом.";
    }

    QLabel *labelcondition = new QLabel;
    labelcondition->setText("<font color=green>Обозначение: </font>" + Changecond);
    labelcondition->setAlignment(Qt::AlignRight);
    labelcondition->setMargin(2);

    QLabel *label4 = new QLabel;
    label4->setText("Погода 1.0");
    label4->setAlignment(Qt::AlignHCenter);

    layoutHedder->addWidget(label1);
//    layoutLeft->addWidget(labelCart);
    layoutLeft->addWidget(labelTemp);
    layoutRight->addWidget(labelFeelsLick);
    layoutRight->addWidget(labelPrec_type);
    layoutRight->addWidget(labelcondition);
    layoutRight->addWidget(labelWind_speed);
    layoutRight->addWidget(labelWind_gust);
    layoutRight->addWidget(labelWind_dir);
    layoutRight->addWidget(labelPressure_mm);
    layoutBottem->addWidget(label4);

    dialog->setWindowTitle("Weather Widget");
    dialog->show();

    return app.exec();
}
