/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#include "src/viewmodel/Processoritemlistviewmodel.h"

#include "src/Cpuinfodataholder.h"
#include "Processoritemviewmodel.h"

ProcessorItemListViewModel::ProcessorItemListViewModel(const CpuInfoDataHolder *cpuInfoData, QObject *parent)
    : QObject(parent),
      _cpuInfoData(cpuInfoData),
      _readError(0)
{
    updateProcessorItems();

}

QList<QObject *> ProcessorItemListViewModel::processorItems() const
{
    return _processorItems;
}

int ProcessorItemListViewModel::noOfProcessors() const
{
    return _noOfProcessors;
}

int ProcessorItemListViewModel::readError() const
{
    return _readError;
}

void ProcessorItemListViewModel::updateProcessorItems()
{
    int i = 0;
    auto dataVector = _cpuInfoData->retreiveData();
    //Error handling if the file read was empty or wrong file is read or error reading the file or if the file does not exist
    if (!dataVector.empty())
    {
        for (auto processorInfo : dataVector)
        {
            auto newItem = new ProcessorItemViewModel(processorInfo, this);
            _processorItems << newItem;
            i++;
        }
    }
    else{
        _readError = 1;
    }
    _noOfProcessors = i;

    emit noOfProcessorsChanged();
    emit processorItemsChanged();
    emit readErrorChanged();

}

