import QtQuick 6.2
import QtQuick.Controls
import QtQuick.Layouts
import com.MediaViewer.viewFrame
import QtQuick.Dialogs


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
            text: "Show Image"
            color: "white"
            anchors.centerIn: parent
        }
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



    ColumnLayout{
        id: imageContainer
        width: 640
        height: 480

        anchors.top: bar.bottom
        anchors.horizontalCenterOffset: 0
        anchors.topMargin: 21
        anchors.horizontalCenter: parent.horizontalCenter

        Image {
            id: picture
            horizontalAlignment: Image.AlignHCenter
            source: "800px-OpenCV_Logo_with_text_svg_version.svg.png"
            scale: 0.495
            Layout.preferredWidth: imageContainer.width
            Layout.preferredHeight: imageContainer.height
            fillMode: Image.PreserveAspectFit
        }

        ViewWindow{
            id:selectImage
            Layout.preferredWidth: imageContainer.width
            Layout.preferredHeight: imageContainer.height
            visible: false
        }
    }

    RowLayout{
        anchors.top: imageContainer.bottom
        anchors.horizontalCenterOffset: 0
        anchors.topMargin: 11
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.6
        spacing: width*0.2

        Button{
            text: "Open Image"
            Layout.preferredWidth: parent.width*0.4
            onClicked: imageDialog.open()
        }
        Button{
            text: "Go Back"
            Layout.preferredWidth: parent.width*0.4
            onClicked: loader.pop()
        }

    }

    FileDialog{
        id: imageDialog
        title: "Choose Image"
        onAccepted: {

            console.log( imageDialog.selectedFile)
            selectImage.openImage(imageDialog.selectedFile);
            picture.visible = false;
            selectImage.visible = true;
        }

    }
}


