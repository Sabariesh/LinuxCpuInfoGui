/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#include "src/viewmodel/Processoritemlistviewmodel.h"

#include "src/Cpuinfodataholder.h"
#include "Processoritemviewmodel.h"

ProcessorItemListViewModel::ProcessorItemListViewModel(const CpuInfoDataHolder cpuInfoData, QObject *parent)
    : QObject(parent),
      _cpuInfoData(cpuInfoData)
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

void ProcessorItemListViewModel::updateProcessorItems()
{
    int i = 0;
    for (auto processorInfo : _cpuInfoData.dataVector)
    {
        auto newItem = new ProcessorItemViewModel(processorInfo, this);
        _processorItems << newItem;

        i++;

    }

    _noOfProcessors = i;

    emit noOfProcessorsChanged();
    emit processorItemsChanged();

}

