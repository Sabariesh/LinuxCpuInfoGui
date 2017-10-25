/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/
#include "Cpuinforeader.h"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

#include <boost/algorithm/string.hpp>

CpuInfoReader::CpuInfoReader()
    :  noOfProcessors(0)
{
}

CpuInfoDataHolder CpuInfoReader::readFile()
{
//    std::ifstream readFile(_fileName);
    std::ifstream readFile("/home/sabariesh-work/cpuinfo1");
    while(readFile >> *this)
    {
    }
    return this->dataHolder;

}

std::istream & operator>>(std::istream &str, CpuInfoReader &dataReader)
{
    std::string currentLine;
    std::string key;
    std::string value;

    if (std::getline(str,currentLine))
    {
        std::stringstream currentLineStream(currentLine);
        //The values stored in the file are divided by ":", so reading only the properties that have value and trimming empty properties
        if (std::getline(currentLineStream, key, ':') && std::getline(currentLineStream, value))
        {
            //Making sure the key and value does not have leading spaces on right and left
            boost::trim_right(key);
            boost::trim_left(value);
            if (key == "processor")
            {
                // Counting by number of processors in the CPU, usually the unique entry
                dataReader.noOfProcessors += 1;
                if (dataReader.noOfProcessors > 1)
                {
                    dataReader.dataHolder.storeData(dataReader.mapVariable);
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
            dataReader.dataHolder.storeData(dataReader.mapVariable);
        }


    }
    return str;

}


