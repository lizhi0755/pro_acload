import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt.labs.qmlmodels 1.0
//import ACLoadTool

Rectangle {
    color: "transparent"

    ListModel {
        id: dataModel
        ListElement { phase: "Ua"; range: "220 V";  angle: "0°";    frequency: "50 Hz" }
        ListElement { phase: "Ub"; range: "220 V";  angle: "120°";  frequency: "50 Hz" }
        ListElement { phase: "Uc"; range: "220 V";  angle: "240°";  frequency: "50 Hz" }
        ListElement { phase: "Ia"; range: "5 A";    angle: "30°";   frequency: "50 Hz" }
        ListElement { phase: "Ib"; range: "5 A";    angle: "150°";  frequency: "50 Hz" }
        ListElement { phase: "Ic"; range: "5 A";    angle: "270°";  frequency: "50 Hz" }
    }

    HorizontalHeaderView {
        id: header
        syncView: tableView
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 30
        delegate: Rectangle {
            color: "#f0f0f0"
            border.width: 10
            Text {
                text: ["  ", "幅值", "相位", "频率"][section]
                anchors.centerIn: parent
            }
        }
    }
    TableView {
        id: tableView
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        columnSpacing: 1
        rowSpacing: 1
        clip: true
        model: dataModel

        // 列宽分配（修复动态计算逻辑）
        columnWidthProvider: (column) => tableView.width / 4

        // 单元格代理（添加显式宽度约束）
        delegate: Rectangle {
            implicitWidth: tableView.columnWidthProvider(column)
            implicitHeight: 30
            border.width: 1
            color: "white"

            Text {
                text: {
                    // 更健壮的取值方式
                    const roles = ["phase", "range", "angle", "frequency"]
                    return model[roles[column]] || ""
                }
                anchors.centerIn: parent
            }
        }
    }


}


/*
    TableModel {
        TableModelColumn { display: "name" }
        TableModelColumn { display: "range" }
        TableModelColumn { display: "angle" }
        TableModelColumn { display: "frequency" }
        rows: [
            {
                "name": "cat",
                "color": "black"
            },
            {
                "name": "dog",
                "color": "brown"
            },
            {
                "name": "bird",
                "color": "white"
    }

ListModel {
        id: dataModel
        ListElement { phase: "Ua"; range: "220 V";  angle: "0°";    frequency: "50 Hz" }
        ListElement { phase: "Ub"; range: "220 V";  angle: "120°";  frequency: "50 Hz" }
        ListElement { phase: "Uc"; range: "220 V";  angle: "240°";  frequency: "50 Hz" }
        ListElement { phase: "Ia"; range: "5 A";    angle: "30°";   frequency: "50 Hz" }
        ListElement { phase: "Ib"; range: "5 A";    angle: "150°";  frequency: "50 Hz" }
        ListElement { phase: "Ic"; range: "5 A";    angle: "270°";  frequency: "50 Hz" }
    }

    TableView {
        id: tableView
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        clip: true
        model: dataModel

        // 列定义
        columns: [
            TableViewColumn {
                title: "Phase"
                role: "phase"
                width: tableView.width / 4
            },

            TableViewColumn {
                title: "幅值"
                role: "range"
                width: tableView.width / 4
            },
            TableViewColumn {
                title: "相位"
                role: "angle"
                width: tableView.width / 4
            },
            TableViewColumn {
                title: "频率"
                role: "frequency"
                width: tableView.width / 4
            }
        ]
    }
        // 表头样式
        headerDelegate: Rectangle {
            height: 40
            color: "lightgray"
            border.color: "gray"

            Text {
                text: styleData.value
                anchors.centerIn: parent
                font.bold: true
                color: "black"
            }
        }

        // 行样式（斑马纹）
        rowDelegate: Rectangle {
            height: 35
            color: {
                if (styleData.selected) return "#d3e5ff";
                return styleData.alternate ? "#f5f5f5" : "white"
            }
            border.color: "#e0e0e0"
        }

        // 单元格样式
        itemDelegate: Rectangle {
            color: "transparent"

            Text {
                text: styleData.value
                anchors.centerIn: parent
                color: "black"
            }
        } */
