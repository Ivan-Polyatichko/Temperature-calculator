import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 400
    height: 250
    visible: true
    title: "Temperature Converter"

    function format(value) {
        return (typeof value === "number") ? value.toFixed(2) : ""
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 12

        RowLayout {
            spacing: 10
            Label { text: "Celsius:" }

            TextField {
                id: celsiusField
                text: format(model.celsius)
                onEditingFinished: controller.updateFromCelsius(celsiusField.text)
                validator: RegularExpressionValidator {
                    regularExpression: /^-?\d*\.?\d*$/
                }
                background: Rectangle {
                    radius: 4
                    border.width: 1
                    border.color: {
                        let v = parseFloat(celsiusField.text)
                        return (!isNaN(v) && v >= -273.15) ? "black" : "red"
                    }
                }
            }
        }

        RowLayout {
            spacing: 10
            Label { text: "Fahrenheit:" }

            TextField {
                id: fahrenheitField
                text: format(model.fahrenheit)
                onEditingFinished: controller.updateFromFahrenheit(fahrenheitField.text)
                validator: RegularExpressionValidator {
                    regularExpression: /^-?\d*\.?\d*$/
                }
                background: Rectangle {
                    radius: 4
                    border.width: 1
                    border.color: {
                        let v = parseFloat(fahrenheitField.text)
                        return !isNaN(v) ? "black" : "red"
                    }
                }
            }
        }

        RowLayout {
            spacing: 10
            Label { text: "Kelvin:" }

            TextField {
                id: kelvinField
                text: format(model.kelvin)
                onEditingFinished: controller.updateFromKelvin(kelvinField.text)
                validator: RegularExpressionValidator {
                    regularExpression: /^-?\d*\.?\d*$/
                }
                background: Rectangle {
                    radius: 4
                    border.width: 1
                    border.color: {
                        let v = parseFloat(kelvinField.text)
                        return (!isNaN(v) && v >= 0.0) ? "black" : "red"
                    }
                }
            }
        }
    }

    Connections {
        target: model
        function onCelsiusChanged()    { celsiusField.text = format(model.celsius) }
        function onFahrenheitChanged() { fahrenheitField.text = format(model.fahrenheit) }
        function onKelvinChanged()     { kelvinField.text = format(model.kelvin) }
    }
}
