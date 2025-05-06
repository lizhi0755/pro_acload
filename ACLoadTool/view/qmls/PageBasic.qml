 
import QtQuick  
import QtQuick.Window  
import QtQuick.Layouts
import QtQuick.Controls 2

Rectangle {
    anchors.leftMargin: 0
    anchors.rightMargin: 0
    anchors.topMargin: 0
    anchors.bottomMargin: 0
    color: "transparent"

    RowLayout {
        anchors.fill: parent
        spacing: 10

        PageBasicVITable {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "red" //"transparent"
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "blue"
        }
    
    }

}
