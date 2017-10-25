/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/
#ifndef CPUINFOREADER_H
#define CPUINFOREADER_H

#include <QMap>
#include <QString>

#include <src/Cpuinfodataholder.h>
//Class to read the file into the data holder data structure
class CpuInfoReader      
{
public:
    CpuInfoReader();
    //Reads the file and returns the data holder stored
    CpuInfoDataHolder readFile();
    friend std::istream& operator>>(std::istream& str, CpuInfoReader& dataReader);
public:
    QMap<QString, QString> mapVariable;
    int noOfProcessors;    
    CpuInfoDataHolder dataHolder;
private:
    std::string _fileName = "/proc/cpuinfo";
};

#endif // CPUINFOREADER_H
