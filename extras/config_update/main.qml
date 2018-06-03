import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Configuration")



    Flow {
        id: flow1
        x: 23
        y: 40
        width: 420
        height: 400
    }

    Column {
        id: column
        x: 467
        y: 40
        width: 162
        height: 400
    }

    Slider {
        id: slider1
        x: 28
        y: 67
        width: 285
        height: 27
        stepSize: 0.1
        to: 100
        from: 0
        value: 0
        objectName: "Slider1"
        signal slider1Signal(double val)
        onMoved:{
            slider1.slider1Signal(slider1.value);
        }
    }

    TextInput {
        id: textInput1
        x: 325
        y: 71
        width: 104
        height: 20
        text: qsTr("Text Input")
        font.letterSpacing: -4
        echoMode: TextInput.NoEcho
        topPadding: 0
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
        objectName: "Text1"
        signal text1Changed(string msg)
        onAccepted: {
            textInput1.focus = false;
            Qt.inputMethod.hide();
            textInput1.text1Changed(textInput1.text);
        }
    }

    Button {
        id: button1
        x: 503
        y: 61
        text: qsTr("Update")
        objectName: "Button1"
        signal button1Callback(string msg)
        onClicked: {
            button1.focus = false;
            button1.button1Callback("clicked");
        }
    }

    Slider {
        id: slider2
        x: 28
        y: 145
        width: 285
        height: 27
        stepSize: 0.1
        to: 100
        value: 0
        objectName: "Slider2"
        signal slider2Signal(double val)
        onMoved:{
            slider2.slider2Signal(slider2.value);
        }
    }

    TextInput {
        id: textInput2
        x: 325
        y: 149
        width: 104
        height: 20
        text: qsTr("Text Input")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        echoMode: TextInput.NoEcho
        topPadding: 0
        font.letterSpacing: -4
        font.pixelSize: 12
        objectName: "Text2"
        signal text2Changed(string msg)
        onAccepted: {
            textInput2.focus = false;
            Qt.inputMethod.hide();
            textInput2.text2Changed(textInput2.text);
        }
    }

    Slider {
        id: slider3
        x: 28
        y: 226
        width: 285
        height: 27
        stepSize: 0.1
        to: 100
        value: 0
        objectName: "Slider3"
        signal slider3Signal(double val)
        onMoved:{
            slider3.slider3Signal(slider3.value);
        }
    }

    TextInput {
        id: textInput3
        x: 325
        y: 230
        width: 104
        height: 20
        text: qsTr("Text Input")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        echoMode: TextInput.NoEcho
        font.letterSpacing: -4
        topPadding: 0
        font.pixelSize: 12
        objectName: "Text3"
        signal text3Changed(string msg)
        onAccepted: {
            textInput3.focus = false;
            Qt.inputMethod.hide();
            textInput3.text3Changed(textInput3.text);
        }
    }

    Slider {
        id: slider4
        x: 28
        y: 327
        width: 285
        height: 27
        stepSize: 0.1
        to: 100
        value: 0
        objectName: "Slider4"
        signal slider4Signal(double val)
        onMoved:{
            slider4.slider4Signal(slider4.value);
        }
    }

    TextInput {
        id: textInput4
        x: 325
        y: 331
        width: 104
        height: 20
        text: qsTr("Text Input")
        font.family: "Arial"
        horizontalAlignment: Text.AlignHCenter
        echoMode: TextInput.NoEcho
        topPadding: 0
        font.letterSpacing: -4
        font.pixelSize: 12
        objectName: "Text4"
        signal text4Changed(string msg)
        onAccepted: {
            textInput4.focus = false;
            Qt.inputMethod.hide();
            textInput4.text4Changed(textInput4.text);
        }
    }

    Button {
        id: button2
        x: 503
        y: 139
        text: qsTr("Update")
        objectName: "Button2"
        signal button2Callback(string msg)
        onClicked: {
            button2.focus = false;
            button2.button2Callback("clicked");
        }
    }


    Button {
        id: button3
        x: 503
        y: 321
        text: qsTr("Update")
        objectName: "Button3"
        signal button3Callback(string msg)
        onClicked: {
            button3.focus = false;
            button3.button3Callback("clicked");
        }
    }

    Button {
        id: button4
        x: 503
        y: 220
        text: qsTr("Update")
        objectName: "Button4"
        signal button4Callback(string msg)
        onClicked: {
            button4.focus = false;
            button4.button4Callback("clicked");
        }
    }

    Text {
        id: text1
        x: 37
        y: 100
        width: 138
        height: 27
        text: qsTr("Filter Limit: Min")
        leftPadding: 4
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 37
        y: 178
        width: 138
        height: 27
        text: qsTr("Filter Limit: Max")
        leftPadding: 4
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
    }

    Text {
        id: text3
        x: 37
        y: 264
        width: 138
        height: 27
        text: qsTr("Marker points: Total")
        leftPadding: 4
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
    }

    Text {
        id: text4
        x: 37
        y: 360
        width: 138
        height: 27
        text: qsTr("Marker points: Size")
        leftPadding: 4
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
    }
}
