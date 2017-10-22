/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/
#include <QApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <fstream>

#include <Cpuinforeader.h>
#include <Cpuinfodataholder.h>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::ifstream readFile("/home/sabariesh/cpuinfo");
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


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

