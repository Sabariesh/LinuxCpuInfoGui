import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Window {
    property int initialWidth: 600
    property int initialHeight: 500
    property var processorPass
    id: mainView
    width: initialWidth
    height: initialHeight
    visible: true
    title: qsTr("Linux CPU Info")
    color: "white"

    property  var vm: root

    Item {
        id: item1
        anchors.fill: parent
        Label {
            id: cpuLabel
            //            y: 0
            anchors.right: parent.right
            anchors.left: parent.left
            Text {
                id: text1
                text: qsTr("Cpu information for the system")
                verticalAlignment: Text.AlignVCenter
                //                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                height: initialHeight/20
                font.pixelSize: 22
                font.italic: true
                color: "steelblue"
            }

            Text {
                id: text2
                text: qsTr("Total number of processors found:") + " " + vm.noOfProcessors
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                height: initialHeight/20 + 40
                font.pixelSize: 12
                font.italic: true
            }
        }

        TabBar {
            id: processorTabBar
            y: text2.height+10
            width: mainView.width
            Repeater {
                id: buttonRepeater
                property int prevIndex : 0
                model: vm.processorItems
                TabButton {
                    id:processorTabButton
                    readonly property var processor : modelData
                    width: Math.max(100, processorTabBar.width / vm.noOfProcessors)
                    text: qsTr("Processor: ") + processor.processorNo
                    onCheckedChanged: {
                        mainView.processorPass = processor
                    }
                }
            }
        }
//        Rectangle{
//            id:messageRect
////            height: 20
//            anchors.top: processorTabBar.bottom
        Rectangle
        {
            id:spacingRect
            height: 20
            anchors.top: processorTabBar.bottom
        }

        Rectangle{
            id:infoRect
            height: 10
            anchors.top: spacingRect.bottom
            Text {
                id: infoText
//                anchors.top: spacingRect.bottom
//                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Information for the processor of model ") + processorPass.modelName
            }

        }


//        }
        ColumnLayout {
            id: processorColumn
//            anchors.top: infoText.bottom
            anchors.top: infoRect.bottom
            width: mainView.width
//            anchors.fill: parent

            GridLayout {
                id: processorInfoGrid
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
//                anchors.top: infoRect.bottom
                anchors.margins: 50
                anchors.fill: parent
                columnSpacing: 5
                columns: 2

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "grey"
                    border.color: "black"
                    Text {
                        text: "Processor Id";
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        color: "white"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "grey"
                    border.color: "black"
                    Text {

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: processorPass.processorNo
                        color: "white"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "white"
                    border.color: "black"
                    Text {
                        text: "Manufacturer";
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        color: "black"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "white"
                    border.color: "black"
                    Text {

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: processorPass.vendorId
                        color: "black"
                    }

                }
                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "grey"
                    border.color: "black"
                    Text {
                        text: "Cache Size";
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        color: "white"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "grey"
                    border.color: "black"
                    Text {

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: processorPass.cacheSize
                        color: "white"
                    }

                }
                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "white"
                    border.color: "black"
                    Text {
                        text: "CPU Speed";
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        color: "black"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "white"
                    border.color: "black"
                    Text {

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: processorPass.cpuMhz
                        color: "black"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "grey"
                    border.color: "black"
                    Text {
                        text: "No. of CPU Cores";
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        color: "white"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "grey"
                    border.color: "black"
                    Text {

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: processorPass.cpuCores
                        color: "white"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "white"
                    border.color: "black"
                    Text {
                        text: "FPU Enabled";
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        color: "black"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "white"
                    border.color: "black"
                    Text {

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: processorPass.fpu
                        color: "black"
                    }

                }



                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "grey"
                    border.color: "black"
                    Text {
                        text: "CPU Speed in MIPS";
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        color: "white"
                    }

                }

                Rectangle {
                    width: mainView.width/3
                    height: 30
                    color: "grey"
                    border.color: "black"
                    Text {

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: processorPass.bogoMips
                        color: "white"
                    }

                }

            }

        }

    }

}

