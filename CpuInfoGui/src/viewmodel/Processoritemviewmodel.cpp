/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#include "Processoritemviewmodel.h"
#include "Processorpropviewmodel.h"
//#include <iostream>
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

QString ProcessorItemViewModel::fpu() const
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

QList<QObject *> ProcessorItemViewModel::propItems() const
{
    return _propItems;
}

QString ProcessorItemViewModel::getMapValue(QString key)
{
    if (_dataMap.count(key)){return _dataMap[key];}
    else {return QString("N/A");}


}

void ProcessorItemViewModel::updateValues()
{
    _vendorId = getMapValue("vendor_id");
    _modelName = getMapValue("model name");
    _cpuMhz = getMapValue("cpu MHz");
    _cacheSize = getMapValue("cache size");
    _cpuCores = getMapValue("cpu cores");
    _fpu = getMapValue("fpu");
    _bogoMips = getMapValue("bogomips");
    _processorNo = getMapValue("processor");

    QMap<QString, QString>::iterator it;

    for (it = _dataMap.begin(); it != _dataMap.end(); ++it) {

        auto newItem = new ProcessorPropViewModel(it.key(),it.value(), this);
        _propItems << newItem;
    }

    emit vendorIdChanged();
    emit modelNameChanged();
    emit cpuMhzChanged();
    emit cacheSizeChanged();
    emit cpuCoresChanged();
    emit fpuChanged();
    emit bogoMipsChanged();
    emit processorNoChanged();
    emit propItemsChanged();

}

