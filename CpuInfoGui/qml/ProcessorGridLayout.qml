import QtQuick 2.0
import QtQuick.Layouts 1.3


GridLayout {
    id: processorInfoGrid
    transformOrigin: Item.Center
    anchors.centerIn: parent
    columnSpacing: 5
    columns: 2
    rows: 7
    ProcessorInfoItem{
        itemText.text: "Processor Id"
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: processorPass.processorNo
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: "Manufacturer"
        itemText.color: "black"
        itemRect.color: "white"
    }
    ProcessorInfoItem{
        itemText.text: processorPass.vendorId
        itemText.color: "black"
        itemRect.color: "white"
    }
    ProcessorInfoItem{
        itemText.text: "Cache Size"
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: processorPass.cacheSize
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: "CPU Speed"
        itemText.color: "black"
        itemRect.color: "white"
    }
    ProcessorInfoItem{
        itemText.text: processorPass.cpuMhz
        itemText.color: "black"
        itemRect.color: "white"
    }

    ProcessorInfoItem{
        itemText.text: "No. of CPU Cores"
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: processorPass.cpuCores
        itemText.color: "white"
        itemRect.color: "grey"
    }

    ProcessorInfoItem{
        itemText.text: "FPU Supported"
        itemText.color: "black"
        itemRect.color: "white"
    }
    ProcessorInfoItem{
        itemText.text: processorPass.fpu
        itemText.color: "black"
        itemRect.color: "white"
    }

    ProcessorInfoItem{
        itemText.text: "CPU Speed in MIPS"
        itemText.color: "white"
        itemRect.color: "grey"
    }
    ProcessorInfoItem{
        itemText.text: processorPass.bogoMips
        itemText.color: "white"
        itemRect.color: "grey"
    }

}


