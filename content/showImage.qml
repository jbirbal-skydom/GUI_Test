import QtQuick 6.2
import QtQuick.Controls
import QtQuick.Layouts
import com.MediaViewer.viewFrame
import QtQuick.Dialogs

Page {
    anchors.fill: parent

    Rectangle {
        id: bar

        color: "orange"
        height: parent.height * 0.1
        width: parent.width
        x: 0
        y: 20

        Label {
            anchors.centerIn: parent
            color: "white"
            text: "Show Image"
        }
    }
    ToolBar {
        id: toolBar

        height: 21
        width: 640
        x: 0
        y: 0
    }
    ToolSeparator {
        id: toolSeparator

        height: 21
        width: 25
        x: 80
        y: 0
    }
    ToolButton {
        id: toolButton

        height: 15
        text: qsTr("File")
        width: 83
        x: 6
        y: 3
    }
    ColumnLayout {
        id: imageContainer
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        anchors.top: bar.bottom
        anchors.topMargin: 21
        height: parent.height * 0.5
        width: parent.width * 0.5

        Image {
            id: picture

            Layout.preferredHeight: imageContainer.height
            Layout.preferredWidth: imageContainer.width
            fillMode: Image.PreserveAspectFit
            horizontalAlignment: Image.AlignHCenter
            scale: 0.495
            source: "800px-OpenCV_Logo_with_text_svg_version.svg.png"
        }
        ViewWindow {
            id: selectImage

            Layout.preferredHeight: imageContainer.height
            Layout.preferredWidth: imageContainer.width
            visible: false
        }
    }
    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        anchors.top: imageContainer.bottom
        anchors.topMargin: 11
        width: parent.width * 0.6

        Button {
            text: "Open Image"
            onClicked: imageDialog.open()
        }

        Button {
            text: "Smoothing"
            onClicked: {
                if(!selectImage.smoothImage()){
                    errorAlert.open()
                }
            }
        }

        Button {
            text: "Go Back"
            onClicked: loader.pop()
        }
    }
    FileDialog {
        id: imageDialog

        title: "Choose Image"

        onAccepted: {
            //console.log(imageDialog.selectedFile)
            selectImage.openImage(imageDialog.selectedFile);
            picture.visible = false;
            selectImage.visible = true;
        }
    }

    Dialog
    {
        id: errorAlert
        title: "error"
        Text{
            text: "Plese open an image"
        }

        standardButtons: Dialog.Ok





    }

}

