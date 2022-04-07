#include "weekclass.h"
#include <QAbstractItemModel>
#include <QMap>


WeekClass::WeekClass(const QString &getdate,const int &gettemp_max,const int &gettemp_min,
                    const int &gettemp_avg, const int &gettemp,const int &getprec_strength)
    : m_date(getdate),
          m_temp_max(gettemp_max),
          m_temp_min(gettemp_min),
          m_temp_avg(gettemp_avg),
          m_temp(gettemp),
          m_prec_strength(getprec_strength)
{
}

//WeekModel::WeekModel(QObject * parent) : QAbstractListModel(parent)
//{

//}

QString WeekClass::getdate() const{
    return m_date;
}
int WeekClass::gettemp_max() const{
    return m_temp_max;
}
int WeekClass::gettemp_min() const{
    return m_temp_min;
}
int WeekClass::gettemp_avg() const{
    return m_temp_avg;
}
int WeekClass::gettemp() const{
    return m_temp;
}
int WeekClass::getprec_strength() const{
    return m_prec_strength;
}

void WeekModel::addItem(const WeekClass & newItem){
    beginInsertRows(QModelIndex(), rowCount(),rowCount());
    m_items << newItem;
    endInsertRows();
}

int WeekModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant WeekModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || (index.row() >= m_items.count()))
        return QVariant();

    const WeekClass&itemToReturn = m_items[index.row()];
    if(role == Weekdata)
        return itemToReturn.getdate();
    else if (role == WeekTempMax) {
        return itemToReturn.gettemp_max();
    }
    else if (role == WeekTempMin) {
        return itemToReturn.gettemp_min();
    }
    else if (role == WeekTempAvg) {
        return itemToReturn.gettemp_avg();
    }
    else if (role == WeekTemp) {
        return itemToReturn.gettemp();
    }
    else if (role == WeekPrecStrength) {
        return itemToReturn.getprec_strength();
    }
    return QVariant();
}


QHash<int, QByteArray> WeekModel::roleWeek() const
{
    // метод используется в QML для сопоставления полей данных со строковыми названиями
     // TODO сопоставить полям данных строковые имена
    QHash<int, QByteArray> roles;

    roles[ Weekdata] = "date";
    roles[ WeekTempMax] = "temp_max";
    roles[ WeekTempMin] = "temp_min";// TODO
    roles[ WeekTempAvg] = "temp_avg";// TODO
    roles[ WeekTemp] = "temp";// TODO
    roles[ WeekPrecStrength] = "prec_strength";// TODO
    return roles;
}

QVariantMap WeekModel::get(int idx) const
{
    // не изменяется
   // метод используется ListView в QML для получения значений полей idx-го элемента модели
    QVariantMap map;
    foreach(int k, roleNames().keys())
    {
        map[roleNames().value(k)] = data(index(idx, 0), k);
    }
    return map;
}

void WeekModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, rowCount()-1);
    m_items.clear();
    endRemoveRows();
}






