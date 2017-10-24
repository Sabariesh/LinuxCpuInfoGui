import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: infoDialog
    title: qsTr("Processor Detailed Info")
    color: "white"
    property int initialWidth: 600
    property int initialHeight: 450
    width: initialWidth
    height: initialHeight
    property var processorInfo
    ListModel {
        id: errorModel
        ListElement {
            key: qsTr("N/A")
            value: qsTr("N/A")
        }
    }
    TableView {
        width: initialWidth
        height: initialHeight
        TableViewColumn {
                role: "key"
                title: qsTr("Properties")
                width: initialWidth/2
            }
            TableViewColumn {
                role: "value"
                title: qsTr("Value")
                width: initialWidth/2
            }
            model: processorInfo ? processorInfo.propItems : errorModel
        }
}
