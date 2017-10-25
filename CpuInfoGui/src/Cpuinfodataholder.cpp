/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#include "Cpuinfodataholder.h"

CpuInfoDataHolder::CpuInfoDataHolder()
{

}

void CpuInfoDataHolder::storeData(QMap<QString, QString> tempData)
{
    _dataVector.push_back(tempData);
}

CpuInfoDataHolder::dataVectorMap CpuInfoDataHolder::retreiveData() const
{
    return _dataVector;

}

