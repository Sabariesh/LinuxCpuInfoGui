import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Rectangle {
    id:itemRect
    property alias itemRect: itemRect
    property alias itemText: itemText
    width: mainView.width/3
    height: 30
    border.color: "black"
    Text {
        id:itemText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

}
