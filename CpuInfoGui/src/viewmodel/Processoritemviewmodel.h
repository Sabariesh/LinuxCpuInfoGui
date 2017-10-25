/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/

#ifndef PROCESSORITEMVIEWMODEL_H
#define PROCESSORITEMVIEWMODEL_H

#include <QObject>
#include <QPointer>

#include <QMap>
#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>


// Properties to be displayed in QML are seperated here for basic and detailed view. The values for the basic values are provided directly and the values for the detailed
// view are provided as list model
//Reason for treating in different way is to build a tool that is agnostic  to the CPU Architecture, CPU type and the various properties stored by different flavors of linux
// It is assumed the basic view properties are common in most of the CPU Architecture, CPU type and Linux system. And the advanced view just passes the complete file
// as List and allow the QML to handle the display of values (without knowing key and value).

class ProcessorItemViewModel : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString vendorId READ vendorId NOTIFY vendorIdChanged)
    Q_PROPERTY(QString modelName READ modelName NOTIFY modelNameChanged)
    Q_PROPERTY(QString cpuMhz READ cpuMhz NOTIFY cpuMhzChanged)
    Q_PROPERTY(QString cacheSize READ cacheSize NOTIFY cacheSizeChanged)
    Q_PROPERTY(QString cpuCores READ cpuCores NOTIFY cpuCoresChanged)
    Q_PROPERTY(QString fpu READ fpu NOTIFY fpuChanged)
    Q_PROPERTY(QString bogoMips READ bogoMips NOTIFY bogoMipsChanged)
    Q_PROPERTY(QString processorNo READ processorNo NOTIFY processorNoChanged)
    Q_PROPERTY(QList<QObject*> propItems READ propItems NOTIFY propItemsChanged)

    ProcessorItemViewModel(QMap<QString, QString> dataMap, QObject *parent = nullptr);

    QString vendorId() const;
    QString modelName() const;
    QString cpuMhz() const;
    QString cacheSize() const;
    QString cpuCores() const;
    QString fpu() const;
    QString bogoMips() const;
    QString processorNo() const;
    QList<QObject*> propItems() const;

signals:
    void vendorIdChanged();
    void modelNameChanged();
    void cpuMhzChanged();
    void cacheSizeChanged();
    void cpuCoresChanged();
    void fpuChanged();
    void bogoMipsChanged();
    void processorNoChanged();
    void propItemsChanged();

private slots:
    void updateValues();
    QString getMapValue(QString);

private:
    QMap<QString, QString> _dataMap;
    QString _vendorId;
    QString _modelName;
    QString _cpuMhz;
    QString _cacheSize;
    QString _cpuCores;
    QString _fpu;
    QString _bogoMips;
    QString _processorNo;   
    QList<QObject*> _propItems;
};

#endif // PROCESSORITEMVIEWMODEL_H
