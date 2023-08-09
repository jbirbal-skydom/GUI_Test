import QtQuick 6.2
import QtQuick.Controls
import QtQuick.Layouts

Page {
    anchors.fill: parent

    Rectangle {
        id: bar
        x: 0
        y: 20
        width: parent.width
        height: parent.height * 0.1
        color: "orange"

        Label {
            text: "Welome to the QT OpenCV app"
            color: "white"
            anchors.centerIn: parent
        }
    }



    Button{
        text: "Show Image"
        anchors.top: bar.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: loader.push("showImage.qml")
    }



    ToolBar {
        id: toolBar
        x: 0
        y: 0
        width: 640
        height: 21
    }

    ToolSeparator {
        id: toolSeparator
        x: 80
        y: 0
        width: 25
        height: 21
    }

    ToolButton {
        id: toolButton
        x: 6
        y: 3
        width: 83
        height: 15
        text: qsTr("File")
    }
}
