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

    //Handling the data reading part, usually done in a different way(not in main loop),
    //doing it in simplest method(YAGNI)
    auto dataReader = std::unique_ptr<CpuInfoReader>(new CpuInfoReader());
    auto dataHolder = dataReader->readFile();

    // Instantiating the viewmodel for the qml
    ProcessorItemListViewModel *_processorItemListViewModel = new ProcessorItemListViewModel(& dataHolder);

    auto _engine = std::unique_ptr<QQmlApplicationEngine>(new QQmlApplicationEngine());
    //Settings the context with the view model named as root
    _engine->rootContext()->setContextProperty("root", _processorItemListViewModel);
    //loading the main qml file, where the viewmodel is handled for display
    _engine->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

