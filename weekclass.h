#ifndef WEEKCLASS_H
#define WEEKCLASS_H
#include <QObject>
#include <QAbstractItemModel>
#include<QAbstractListModel>
#include <QList>
#include <QModelIndex>
#include <QVariant>
#include <QUrl>
#include <QVariant>


class WeekClass
{
public:
    WeekClass(const QString &pdate,
              const int &ptemp_max,
              const int &ptemp_min,
              const int &ptemp_avg,
              const int &ptemp,
              const int &Pprec_strength);

    QString getdate() const;
    int gettemp_max() const;
    int gettemp_min() const;
    int gettemp_avg() const;
    int gettemp() const;
    int getprec_strength() const;
private:
    QString m_date;
    int m_temp_max;
    int m_temp_min;
    int m_temp_avg;
    int m_temp;
    int m_prec_strength;
};

class WeekModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum enmWeekCount{
      Weekdata = Qt::UserRole+1,
        WeekTempMax,
        WeekTempMin,
        WeekTempAvg,
        WeekTemp,
        WeekPrecStrength
    };

    WeekModel(QObject *parent = nullptr);
    void addItem(const WeekClass & newItem);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QVariantMap get(int idx) const;
    void clear();
protected:
   QHash<int, QByteArray> roleWeek() const;

private:

  QList<WeekClass> m_items;

};

#endif // WEEKCLASS_H
