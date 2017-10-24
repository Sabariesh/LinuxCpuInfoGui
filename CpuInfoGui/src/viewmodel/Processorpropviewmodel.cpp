#include "Processorpropviewmodel.h"

ProcessorPropViewModel::ProcessorPropViewModel(QString key, QString name, QObject *parent)
    : QObject(parent),
      _key(key),
      _value(name)
{
}

QString ProcessorPropViewModel::key() const
{
    return _key;
}

QString ProcessorPropViewModel::value() const
{
    return _value;
}
