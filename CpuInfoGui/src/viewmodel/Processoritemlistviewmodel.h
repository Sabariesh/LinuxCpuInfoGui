/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#ifndef PROCESSORITEMLISTVIEWMODEL_H
#define PROCESSORITEMLISTVIEWMODEL_H

#include <QObject>

#include "src/Cpuinfodataholder.h"

class ProcessorItemListViewModel : public QObject
{
    Q_OBJECT


public:
    Q_PROPERTY(QList<QObject*> processorItems READ processorItems NOTIFY processorItemsChanged)
    Q_PROPERTY(int noOfProcessors READ noOfProcessors NOTIFY noOfProcessorsChanged)

    ProcessorItemListViewModel(const CpuInfoDataHolder cpuInfoData, QObject *parent = nullptr);

    QList<QObject*> processorItems() const;
    int noOfProcessors() const;
signals:
    void processorItemsChanged();
    void noOfProcessorsChanged();

private slots:
    void updateProcessorItems();
private:
    QList<QObject*> _processorItems;
    CpuInfoDataHolder _cpuInfoData;
    int _noOfProcessors;
};

#endif // PROCESSORITEMLISTVIEWMODEL_H
