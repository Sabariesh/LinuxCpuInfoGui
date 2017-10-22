TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += src/main.cpp \
    src/Cpuinfodataholder.cpp \
    src/Cpuinforeader.cpp \
    src/viewmodel/Processoritemviewmodel.cpp \
    src/viewmodel/Processoritemlistviewmodel.cpp


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/Cpuinfodataholder.h \
    src/Cpuinforeader.h \
    src/viewmodel/Processoritemviewmodel.h \
    src/viewmodel/Processoritemlistviewmodel.h

