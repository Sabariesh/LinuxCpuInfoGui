/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/
#ifndef CPUINFOREADER_H
#define CPUINFOREADER_H

#include <QMap>
#include <QString>

#include <src/Cpuinfodataholder.h>

class CpuInfoReader
{
public:
    CpuInfoReader();

    friend std::istream& operator>>(std::istream& str, CpuInfoReader& dataReader);


public:
    QMap<QString, QString> _mapVariable;
    int noOfProcessors;
    CpuInfoDataHolder dataHolder;
};

#endif // CPUINFOREADER_H
