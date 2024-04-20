import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import wc

ApplicationWindow {
    id: aplicationWindow

    width: 1280
    height: 720
    minimumWidth: 800
    minimumHeight: 400

    visible: true

    RowLayout {
        anchors.fill: parent
        anchors.margins: 50
        spacing: 50

        Column {
            spacing: 10

            Button {
                width: 100
                height: 40
                text: qsTr("Open")
            }

            Button {
                width: 100
                height: 40
                text: qsTr("Start")
            }

            Button {
                width: 100
                height: 40
                text: qsTr("Pause")
            }

            Button {
                width: 100
                height: 40
                text: qsTr("Stop")
            }
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 50

            ListView {
                id: listView

                property real delegateWidth: listView.width / 44

                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter
                spacing: delegateWidth
                orientation: ListView.Horizontal
                interactive: false

                model: WordChartModel {}

                delegate: Rectangle {
                    id: container
                    width: listView.delegateWidth * 2
                    height: listView.height

                    color: "transparent"

                    Column {
                        spacing:10

                        Label {
                            anchors.horizontalCenter: parent.horizontalCenter
                            rotation: 270
                            text: count
                        }

                        Rectangle {
                            id: countRectangle
                            width: container.width
                            height: Math.floor(Math.random() * container.height)
                        }

                        anchors.bottom: parent.bottom
                    }
                }
            }

            ProgressBar {
                Layout.fillWidth: true
            }
        }
    }
}
