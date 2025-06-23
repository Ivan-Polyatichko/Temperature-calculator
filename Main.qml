import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 400
    height: 270
    visible: true
    title: "Temperature Converter"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 12

        RowLayout {
            spacing: 10
            Label { text: "Celsius:" }

            TextField {
                id: celsiusField
                text: model.celsius.toFixed(2)
                onTextEdited: {
                    controller.updateFromCelsius(text)
                }
                validator: RegularExpressionValidator {
                    regularExpression: /^-?\d*\.?\d*$/
                }
                background: Rectangle {
                    radius: 4
                    border.color: parseFloat(celsiusField.text) >= -273.15 ? "black" : "red"
                    border.width: 1
                }
            }
        }

        RowLayout {
            spacing: 10
            Label { text: "Fahrenheit:" }

            TextField {
                id: fahrenheitField
                text: model.fahrenheit.toFixed(2)
                onTextEdited: {
                    controller.updateFromFahrenheit(text)
                }
                validator: RegularExpressionValidator {
                    regularExpression: /^-?\d*\.?\d*$/
                }
                background: Rectangle {
                    radius: 4
                    border.color: !isNaN(parseFloat(fahrenheitField.text)) ? "black" : "red"
                    border.width: 1
                }
            }
        }

        RowLayout {
            spacing: 10
            Label { text: "Kelvin:" }

            TextField {
                id: kelvinField
                text: model.kelvin.toFixed(2)
                onTextEdited: {
                    controller.updateFromKelvin(text)
                }
                validator: RegularExpressionValidator {
                    regularExpression: /^-?\d*\.?\d*$/
                }
                background: Rectangle {
                    radius: 4
                    border.color: parseFloat(kelvinField.text) >= 0 ? "black" : "red"
                    border.width: 1
                }
            }
        }
    }

    Connections {
        target: model

        function onCelsiusChanged() {
            celsiusField.text = model.celsius.toFixed(2)
        }

        function onFahrenheitChanged() {
            fahrenheitField.text = model.fahrenheit.toFixed(2)
        }

        function onKelvinChanged() {
            kelvinField.text = model.kelvin.toFixed(2)
        }
    }
}
