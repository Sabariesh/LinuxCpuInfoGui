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

class ProcessorItemViewModel : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString vendorId READ vendorId NOTIFY vendorIdChanged)
    Q_PROPERTY(QString modelName READ modelName NOTIFY modelNameChanged)
    Q_PROPERTY(QString cpuMhz READ cpuMhz NOTIFY cpuMhzChanged)
    Q_PROPERTY(QString cacheSize READ cacheSize NOTIFY cacheSizeChanged)
    Q_PROPERTY(QString cpuCores READ cpuCores NOTIFY cpuCoresChanged)
    Q_PROPERTY(QString fpu READ fpuFpu NOTIFY fpuChanged)
    Q_PROPERTY(QString bogoMips READ bogoMips NOTIFY bogoMipsChanged)
    Q_PROPERTY(QString processorNo READ processorNo NOTIFY processorNoChanged)
//    Q_PROPERTY(QVariantMap dataVariant READ dataVariant NOTIFY dataVariantChanged)

    ProcessorItemViewModel(QMap<QString, QString> dataMap, QObject *parent = nullptr);

    QString vendorId() const;

    QString modelName() const;

    QString cpuMhz() const;

    QString cacheSize() const;

    QString cpuCores() const;

    QString fpuFpu() const;

    QString bogoMips() const;

    QString processorNo() const;

//    QVariantMap dataVariant() const;

signals:

    void vendorIdChanged();

    void modelNameChanged();

    void cpuMhzChanged();

    void cacheSizeChanged();

    void cpuCoresChanged();

    void fpuChanged();

    void bogoMipsChanged();

    void processorNoChanged();

//    void dataVariantChanged();

private slots:
    void updateValues();

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
//    QVariantMap _dataVariant;
};

#endif // PROCESSORITEMVIEWMODEL_H
