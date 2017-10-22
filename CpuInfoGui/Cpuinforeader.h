#ifndef CPUINFOREADER_H
#define CPUINFOREADER_H

#include <QMap>
#include <QString>

class CpuInfoReader
{
public:
    CpuInfoReader();

    friend std::istream& operator>>(std::istream& str, CpuInfoReader& dataReader);


public:
    QMap<QString, QString> _mapVariable;
};

#endif // CPUINFOREADER_H
