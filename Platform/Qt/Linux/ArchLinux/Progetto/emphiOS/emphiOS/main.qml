import QtQuick 2.0
//import QtQuick 2.7
import Eos_Item_Cpp 1.0
//eos_Item_Cpp


EosItemCpp {
//Item {
    id: eos_item_root
    visible: true
    width: 640
    height: 480
    focus: true

    signal qmlSignal_Start(string msg)
    signal qmlSignal_Stop(string msg)


    Rectangle {
        id: button_start
        x: 0; y: 0
        width: 100; height: 100
        color: "green"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("QML - Stsrt Rectangle")
                eos_item_root.qmlSignal_Start("Start Process!!!!")
            }
        }
    }

    Rectangle {
        id: button_stop
        x: 110; y: 110
        width: 100; height: 100
        color: "red"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("QML - Stop Rectangle")
                eos_item_root.qmlSignal_Stop("Stop Process!!!")
            }
        }
    }

    Rectangle {
        x: 200; y: 300
        Text {
            objectName: "LcdRiga1"
            text: qsTr("Riga 1 - 01234567890")
            anchors.centerIn: parent
        }
    }

    Rectangle {
        x: 200; y: 320
        Text {
            objectName: "LcdRiga2"
            text: qsTr("Riga 2 - 01234567890")
            anchors.centerIn: parent
        }
    }

    Rectangle {
        x: 200; y: 340
        Text {
            x: 200; y: 340
            objectName: "LcdRiga3"
            text: qsTr("Riga 3 - 01234567890")
            anchors.centerIn: parent
        }
    }

    Rectangle {
        x: 200; y: 360
        Text {
            objectName: "LcdRiga4"
            text: qsTr("Riga 4 - 01234567890")
            anchors.centerIn: parent
        }
    }
}


