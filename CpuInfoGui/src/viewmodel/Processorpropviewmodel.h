#ifndef PROCESSORPROPVIEWMODEL_H
#define PROCESSORPROPVIEWMODEL_H

#include <QObject>
#include <QString>

class ProcessorPropViewModel : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QString key READ key NOTIFY keyChanged)
    Q_PROPERTY(QString value READ value NOTIFY valueChanged)
    ProcessorPropViewModel(QString key, QString name, QObject *parent = nullptr);
    QString key() const;
    QString value() const;

signals:
    void keyChanged(QString key);
    void valueChanged(QString value);

private:
    QString _key;
    QString _value;
};

#endif // PROCESSORPROPVIEWMODEL_H
