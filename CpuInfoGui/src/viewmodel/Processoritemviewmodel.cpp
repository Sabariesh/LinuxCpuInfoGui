/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#include "Processoritemviewmodel.h"

ProcessorItemViewModel::ProcessorItemViewModel(QMap<QString, QString> dataMap, QObject *parent)
    : QObject(parent),
      _dataMap(dataMap)
{
    updateValues();
}

QString ProcessorItemViewModel::vendorId() const
{
    return _vendorId;
}

QString ProcessorItemViewModel::modelName() const
{
    return _modelName;
}

QString ProcessorItemViewModel::cpuMhz() const
{
    return _cpuMhz;
}

QString ProcessorItemViewModel::cacheSize() const
{
    return _cacheSize;
}

QString ProcessorItemViewModel::cpuCores() const
{
    return _cpuCores;
}

QString ProcessorItemViewModel::fpuFpu() const
{
    return _fpu;
}

QString ProcessorItemViewModel::bogoMips() const
{
    return _bogoMips;
}

QString ProcessorItemViewModel::processorNo() const
{
    return _processorNo;
}

//QVariantMap ProcessorItemViewModel::dataVariant() const
//{
//    return _dataVariant;
//}

void ProcessorItemViewModel::updateValues()
{

    //_dataVariant = _dataMap;

    _vendorId = _dataMap["vendor_id"];
    _modelName = _dataMap["model name"];
    _cpuMhz = _dataMap["cpu MHz"];
    _cacheSize = _dataMap["cache size"];
    _cpuCores = _dataMap["cpu cores"];
    _fpu = _dataMap["fpu"];
    _bogoMips = _dataMap["bogomips"];
    _processorNo = _dataMap["processor"];

    emit vendorIdChanged();
    emit modelNameChanged();
    emit cpuMhzChanged();
    emit cacheSizeChanged();
    emit cpuCoresChanged();
    emit fpuChanged();
    emit bogoMipsChanged();
    emit processorNoChanged();
//    emit dataVariantChanged();

}

