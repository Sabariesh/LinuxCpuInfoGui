#include "Cpuinforeader.h"
#include <sstream>
#include <string>
#include <iostream>

#include <boost/algorithm/string.hpp>

CpuInfoReader::CpuInfoReader()
{

}

std::istream & operator>>(std::istream &str, CpuInfoReader &dataReader)
{
    std::string currentLine;
    std::string key;
    std::string value;

    if (std::getline(str,currentLine))
    {
        std::stringstream currentLineStream(currentLine);
        if (std::getline(currentLineStream, key, ':') && std::getline(currentLineStream, value))
        {
            boost::trim_right(key);
            boost::trim_left(value);
            dataReader._mapVariable.insert( QString::fromStdString(key), QString::fromStdString(value));
        }
//        std::cout << key << value << "\n";

    }
    return str;

}

