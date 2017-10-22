#include <QApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <fstream>

#include <Cpuinforeader.h>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::ifstream readFile("/proc/cpuinfo");
    CpuInfoReader dataReader;

    while(readFile >> dataReader)
    {

    }

    QMap<QString, QString>::iterator it;

    for (it = dataReader._mapVariable.begin(); it != dataReader._mapVariable.end(); ++it) {

        std::cout << it.key().toStdString() << " : " << it.value().toStdString() << "\n";

    }

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

