/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/
#include <QQmlApplicationEngine>
#include <QtGui/QGuiApplication>
#include <QQmlContext>

#include <memory>
#include <fstream>

#include "src/Cpuinforeader.h"
#include "src/viewmodel/Processoritemlistviewmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app( argc, argv );

    //Handling the data reading part, usually done in a different way,
    //since all the variables are known, doing it in simplest method
//    std::ifstream readFile("/proc/cpuinfo");
    std::ifstream readFile("/home/sabariesh-work/cpuinfo1");
    CpuInfoReader dataReader;
    while(readFile >> dataReader)
    {
    }

//    QMap<QString, QString>::iterator it;

//    for (QMap<QString, QString> dataMap : dataReader.dataHolder.dataVector)
//    {
//        std::cout << 1 << "\n";
//        for (it = dataMap.begin(); it != dataMap.end(); ++it) {

//            std::cout << it.key().toStdString() << " : " << it.value().toStdString() << "\n";

//        }

//    }

    // Instantiating the viewmodel for the qml
    ProcessorItemListViewModel *_processorItemListViewModel = new ProcessorItemListViewModel(& dataReader.dataHolder);

    auto _engine = std::unique_ptr<QQmlApplicationEngine>(new QQmlApplicationEngine());
    //Settings the context with the view model named as root
    _engine->rootContext()->setContextProperty("root", _processorItemListViewModel);
    //loading the main qml file, where the viewmodel is handled for display
    _engine->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

