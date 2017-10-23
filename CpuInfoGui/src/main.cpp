/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtGui/QGuiApplication>
#include <QQmlContext>

#include <iostream>
#include <fstream>

#include "src/Cpuinforeader.h"
#include "src/Cpuinfodataholder.h"
#include "src/viewmodel/Processoritemlistviewmodel.h"



int main(int argc, char *argv[])
{
//    QApplication app(argc, argv);
    QGuiApplication app( argc, argv );
    std::ifstream readFile("/proc/cpuinfo");
//    std::ifstream readFile("/home/sabariesh/cpuinfo");
    CpuInfoReader dataReader;


    while(readFile >> dataReader)
    {

    }

    QMap<QString, QString>::iterator it;

    for (QMap<QString, QString> dataMap : dataReader.dataHolder.dataVector)
    {
        std::cout << 1 << "\n";
        for (it = dataMap.begin(); it != dataMap.end(); ++it) {

            std::cout << it.key().toStdString() << " : " << it.value().toStdString() << "\n";

        }

    }

    ProcessorItemListViewModel *_processorItemListViewModel = new ProcessorItemListViewModel(dataReader.dataHolder);



    // Expose the RandomTimer class
//    qmlRegisterType<RandomTimer>( "CustomComponents", 1, 0, "RandomTimer" );

//    QQuickView viewer;
//    viewer.setSource( QUrl( "qrc:/qml/main.qml" ) );
//    viewer.show();

    QQmlApplicationEngine engine;
//    _engine = std::make_unique<QQmlApplicationEngine>();
    engine.rootContext()->setContextProperty("root", _processorItemListViewModel);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

//    engine.setContextForObject();

    return app.exec();
}

