import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property var vm: root
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Label {
//        text: qsTr("Hello World")
        text: vm.noOfProcessors
        anchors.centerIn: parent
    }
    Row {
        Repeater {
            model: vm.processorItems
            Text {
                readonly property var processor : modelData
                text: modelData.vendorId
    //            anchors.centerIn: parent
            }

            }

    }


}

