import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import wc

ApplicationWindow {
    id: aplicationWindow

    property QtObject wordChartModel: WordChartModel {}

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

            FileDialog {
                id: fileDialog
                nameFilters: [ "*.txt" ]

                onAccepted: {
                    wordChartModel.filePathUpdated(fileDialog.currentFile.toString().replace("file://", ""))
                }
            }

            Button {
                width: 100
                height: 40
                text: qsTr("Open")

                onPressed: fileDialog.open()
            }

            Button {
                width: 100
                height: 40
                text: qsTr("Start")

                onPressed: wordChartModel.startProcessing()
            }

            Button {
                width: 100
                height: 40
                text: qsTr("Pause")

                onPressed: fileProcessor.pauseProcessing()
            }

            Button {
                width: 100
                height: 40
                text: qsTr("Stop")

                onPressed: fileProcessor.stopProcessing()
            }
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 50

            ListView {
                id: listView

                property real delegateWidth: listView.width / 44
                property real scaleFactor: model.maxWordCount === 0 ? 1 : (listView.height - 50) / model.maxWordCount

                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter
                spacing: delegateWidth
                orientation: ListView.Horizontal
                interactive: false

                model: wordChartModel

                delegate: Rectangle {
                    id: container
                    width: listView.delegateWidth * 2
                    height: listView.height

                    color: "transparent"

                    Column {
                        spacing: 10

                        Label {
                            id: wordsCount
                            anchors.horizontalCenter: parent.horizontalCenter
                            rotation: 270
                            text: count
                        }

                        Rectangle {
                            id: countRectangle
                            width: container.width
                            height: count * listView.scaleFactor

                            Label {
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.verticalCenter: parent.verticalCenter
                                rotation: 270
                                text: word
                                color: "#000000"
                            }
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
