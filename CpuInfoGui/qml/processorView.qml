import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Item {
    property var vm
    GridLayout {
        id: grid
        columns: 2

        Text { text: "Three"; font.bold: true; }
        Text { text: "words"; color: "red" }

    }

}
