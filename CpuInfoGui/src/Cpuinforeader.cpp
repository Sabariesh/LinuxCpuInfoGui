/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/
#include "Cpuinforeader.h"
#include <sstream>
#include <string>
#include <iostream>

#include <boost/algorithm/string.hpp>

CpuInfoReader::CpuInfoReader()
    :  noOfProcessors(0)
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
            if (key == "processor")
            {
                dataReader.noOfProcessors += 1;
                if (dataReader.noOfProcessors > 1)
                {
                    dataReader.dataHolder.dataVector.push_back(dataReader.mapVariable);
                    dataReader.mapVariable.clear();
                }
            }
            dataReader.mapVariable.insert( QString::fromStdString(key), QString::fromStdString(value));
        }
    }
    else
    {
        if (dataReader.noOfProcessors != 0)
        {            
            dataReader.dataHolder.dataVector.push_back(dataReader.mapVariable);
        }


    }
    return str;

}

