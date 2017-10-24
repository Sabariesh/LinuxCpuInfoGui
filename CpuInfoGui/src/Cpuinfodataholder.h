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

public:
    std::vector < QMap<QString, QString> > dataVector;
};

#endif // CPUINFODATAHOLDER_H
