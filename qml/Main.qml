import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: aplicationWindow

    width: 1280
    height: 720

    visible: true

    RowLayout {
        anchors.fill: parent
        anchors.margins: 50

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter
            spacing: 40
            orientation: ListView.Horizontal
            // clip: true
            interactive: false

            model: 15

            delegate: Rectangle {
                id: container
                width: 40
                height: listView.height

                color: "transparent"

                Column {
                    spacing:10

                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        rotation: 270
                        text: countRectangle.height
                    }

                    Rectangle {
                        id: countRectangle
                        width: 40
                        height: Math.floor(Math.random() * container.height)
                    }

                    anchors.bottom: parent.bottom
                }
            }
        }
    }
}
