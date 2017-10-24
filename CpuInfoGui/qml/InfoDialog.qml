import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: infoDialog
//    visible: true
    title: qsTr("Linux CPU Info")
    color: "white"
    property var processorInfo
//    property var vm: root.mainWindow
    Item {
        id: item1
        anchors.fill: parent
        Text {
            id: nameText
            text: processorInfo ? processorInfo.fpu: qsTr("N/A")
        }

    }

}
