import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
//import QtQuick.Dialogs 1.2

Window {
    property int initialWidth: 600
    property int initialHeight: 450
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
            Text {
                id: text1
                text: qsTr("Cpu information for the system")
                verticalAlignment: Text.AlignVCenter                
                anchors.horizontalCenter: parent.horizontalCenter               
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
                anchors.top: text1.bottom
                font.pixelSize: 12
                font.italic: true
            }

        TabBar {
            id: processorTabBar            
            anchors.top: text2.bottom
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

        Rectangle
        {
            id:spacingRect
            height: 20
            anchors.top: processorTabBar.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

            Text {
                id: infoText
                text: qsTr("Information for the processor of model ") + processorPass.modelName
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.top: spacingRect.bottom
                anchors.horizontalCenter: parent.horizontalCenter
            }

        ColumnLayout {
            id: processorColumn
            anchors.top: infoText.bottom
            width: mainView.width
                ProcessorGridLayout {
                    id: processorGridView
                    anchors.horizontalCenter: parent.horizontalCenter

                }
           Rectangle
                {
                    id:spacingRect1
                    height: 10
                    anchors.top: processorGridView.bottom
                }

            Button{
                text: qsTr("Detailed Info")
                anchors.top: spacingRect1.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    var component = Qt.createComponent("InfoDialog.qml")
                    var window = component.createObject(mainView)
                    window.processorInfo = processorPass
                    window.show()
                }

            }

        }

    }

}

