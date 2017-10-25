/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#ifndef CPUINFODATAHOLDER_H
#define CPUINFODATAHOLDER_H

#include <vector>
#include <QMap>
#include <QString>

class CpuInfoDataHolder
{
public:
    CpuInfoDataHolder();
    typedef std::vector < QMap<QString, QString> > dataVectorMap;
    void storeData(QMap<QString, QString>);
    dataVectorMap retreiveData() const;

private:
    dataVectorMap _dataVector;
};

#endif // CPUINFODATAHOLDER_H
