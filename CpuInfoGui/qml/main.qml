//import QtQuick 2.3
//import QtQuick.Controls 1.2
//import QtQuick.Layouts 1.3

//ApplicationWindow {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")
//    property var vm: root

//    property int additionalFlags: 0
////    flags: Qt.FramelessWindowHint | Qt.Window | additionalFlags
//    menuBar: MenuBar {
//        Menu {
//            title: qsTr("File")
//            MenuItem {
//                text: qsTr("&Open")
//                onTriggered: console.log("Open action triggered");
//            }
//            MenuItem {
//                text: qsTr("Exit")
//                onTriggered: Qt.quit();
//            }
//        }
//    }


////    Label {
////        text: "#vm.noOfProcessors#"
////        anchors.verticalCenterOffset: -178
////        anchors.horizontalCenterOffset: -143
////        //        text: qsTr("Hello World")
////        anchors.centerIn: parent
////    }
////    Row {
////        anchors.fill: parent
////        Repeater {
////            model: vm.processorItems
////            Text {
////                readonly property var processor : modelData
////                text: modelData.vendorId
////                //            anchors.centerIn: parent
////            }

////        }

////    }

//    Column {
//        id: column
//        x: 101
//        y: 126
//        width: 439
//        height: 293
//    }
//}

import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    property int initialWidth: 600
    property int initialHeight: 800
    id: mainView
    width: initialWidth
    height: initialHeight
    visible: true
    title: qsTr("Linux CPU Info")
    color: "white"

    property  var vm: root

    Item {
        anchors.fill: parent
        Label {
//            y: 0
            anchors.right: parent.right
            anchors.left: parent.left
            Text {
                id: text
                text: qsTr("Cpu information for the system")
                verticalAlignment: Text.AlignVCenter
//                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                height: initialHeight/10
                font.pixelSize: 22
                font.italic: true
                color: "steelblue"
            }

            Text {
                id: text1
                text: qsTr("Total number of processors found:") + " " + vm.noOfProcessors
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                height: initialHeight/10 + 40
                font.pixelSize: 12
                font.italic: true
            }
        }

//        TabBar {
//            id: bar
//            width: parent.width
//            height: initialHeight/10 + 80
//            Repeater {
//                model: vm.processorItems
//                TabButton {
//                    readonly property var processor : modelData
//                    text: "Processor: " + processor.processorNo
//                    width: Math.max(100, bar.width / 5)
//                }
//            }
//        }
    }

//    Column {
//        id: column
//        x: 21
//        y: 109
//        width: 200
//        height: 491
//    }

//    Row {
//        id: row1
//        x: 273
//        y: 148
//        width: 200
//        height: 400
//    }

//    Row {
//        id: row2
//        x: 479
//        y: 148
//        width: 200
//        height: 400
//    }

}

