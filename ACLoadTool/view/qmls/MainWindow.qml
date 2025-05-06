 
import QtQuick  
import QtQuick.Window  
import QtQuick.Controls 2
import ACLoadTool

Window {
    id: window
    width: realWidth
    height: realHeight
    visible: true
    title:  (viewAppCfgs !== null) ? viewAppCfgs.getAppTitle() : qsTr("")
     
    property int realWidth: 1024
    property int realHeight: 800
     
    property var tabPageTexts: ["基本测量值", "最大、最小值", "设备配置信息"]

    Component.onCompleted:  { 
        //console.log("MianWindow Component.onCompleted ");
    }
    Component.onDestruction: {
        console.log("MianWindow onDestruction");
    }
    onActiveChanged: {
        //windowTitle.update();
        //windowBorder.update();
    }

    // head
    Rectangle {
        id: rectHead
        height: 1 //realHeight * 0.18
        width: parent.width
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: 1
        anchors.rightMargin: 1
        color: "transparent"
    }

    Rectangle {
        id: rectFoot
        height: realHeight * 0.1
        width: parent.width
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: 1
        anchors.rightMargin: 1
        anchors.bottomMargin: 1
        color: "transparent"
    }
    
    Rectangle {
        id: rectCenter
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: rectHead.bottom
        anchors.bottom: rectFoot.top
        anchors.leftMargin: 1
        anchors.rightMargin: 1
        color: "transparent"
        
        Rectangle {
            id: rectCenterBk
            anchors.fill: parent
            color: "transparent"
        } 
        
        TabBar {
            id: tabBarPages
            height: 48
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 0//20
            anchors.leftMargin: 0//20
            anchors.topMargin: 40
            anchors.bottomMargin: 0
            spacing: 0
            padding: 0 
            background: Rectangle {
                color: "transparent"
            }
            currentIndex: swipeViewPages.currentIndex
            Repeater {
                id: repeaterTabButton
                model:tabPageTexts.length
                TabButton {
                    text: tabPageTexts[index]
                    visible: true
                    spacing: 0
                    padding: 0
                    width: (rectCenter.width - 1) / tabPageTexts.length
                    height: parent.height
                }
            }
        }
        SwipeView {
            id: swipeViewPages
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: tabBarPages.bottom
            anchors.bottom: parent.bottom
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            currentIndex: tabBarPages.currentIndex 
            onCurrentIndexChanged: {
                tabBarPages.currentIndex = swipeViewPages.currentIndex;
            }
            
            PageBasic {
                id: pageBasic
                Text {
                    text: "This is Page 1"
                    anchors.centerIn: parent
                }
            }
            Page {
                id: pageMaxmin
                background: Rectangle {
                    color: "transparent"
                }  
                Text {
                    text: "This is Page 2"
                    anchors.centerIn: parent 
                }
            }
            Page {
                id: pageMachine
                background: Rectangle {
                    color: "transparent"
                }  
                Text {
                    text: "This is Page 3"
                    anchors.centerIn: parent 
                }
            } 

        }
    }  
      

}
