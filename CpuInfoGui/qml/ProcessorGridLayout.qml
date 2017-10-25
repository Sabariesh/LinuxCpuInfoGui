/**************************************************************************
Creator: Sabariesh Ganesan
Email Id: sabari.eshwar@gmail.com
**************************************************************************/
import QtQuick 2.6
import QtQuick.Layouts 1.3


GridLayout {
    id: processorInfoGrid
    transformOrigin: Item.Center
    anchors.centerIn: parent
    columnSpacing: 5
    columns: 2
    rows: 7
    property string errorText: "N/A"
    ProcessorInfoItem{
        itemText.text: "Processor Id"
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: processorPass ? processorPass.processorNo : errorText
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: "Manufacturer"
        itemText.color: "black"
        itemRect.color: "white"
    }
    ProcessorInfoItem{
        itemText.text: processorPass ? processorPass.vendorId : errorText
        itemText.color: "black"
        itemRect.color: "white"
    }
    ProcessorInfoItem{
        itemText.text: "Cache Size"
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: processorPass ? processorPass.cacheSize : errorText
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: "CPU Speed in MHz"
        itemText.color: "black"
        itemRect.color: "white"
    }
    ProcessorInfoItem{
        itemText.text: processorPass ? processorPass.cpuMhz : errorText
        itemText.color: "black"
        itemRect.color: "white"
    }

    ProcessorInfoItem{
        itemText.text: "No. of CPU Cores"
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: processorPass ? processorPass.cpuCores : errorText
        itemText.color: "white"
        itemRect.color: "grey"
    }

    ProcessorInfoItem{
        itemText.text: "FPU Supported"
        itemText.color: "black"
        itemRect.color: "white"
    }
    ProcessorInfoItem{
        itemText.text: processorPass ? processorPass.fpu : errorText
        itemText.color: "black"
        itemRect.color: "white"
    }

    ProcessorInfoItem{
        itemText.text: "CPU Speed in MIPS"
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: processorPass ? processorPass.bogoMips : errorText
        itemText.color: "white"
        itemRect.color: "grey"
    }

}


