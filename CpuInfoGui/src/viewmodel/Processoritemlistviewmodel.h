/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#ifndef PROCESSORITEMLISTVIEWMODEL_H
#define PROCESSORITEMLISTVIEWMODEL_H

#include <QObject>

#include "src/Cpuinfodataholder.h"

//The root view model to collect all the data and pass it on to the qml

class ProcessorItemListViewModel : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QList<QObject*> processorItems READ processorItems NOTIFY processorItemsChanged)
    Q_PROPERTY(int noOfProcessors READ noOfProcessors NOTIFY noOfProcessorsChanged)
    Q_PROPERTY(int readError READ readError NOTIFY readErrorChanged)
    ProcessorItemListViewModel(const CpuInfoDataHolder *cpuInfoData, QObject *parent = nullptr);

    QList<QObject*> processorItems() const;
    int noOfProcessors() const;
    int readError() const;

signals:
    void processorItemsChanged();
    void noOfProcessorsChanged();

    void readErrorChanged();

private slots:
    void updateProcessorItems();
private:
    QList<QObject*> _processorItems;
    const CpuInfoDataHolder *_cpuInfoData;
    int _noOfProcessors;
    int _readError;
};

#endif // PROCESSORITEMLISTVIEWMODEL_H
