#include "temperaturemodel.h"
#include <QtMath>

TemperatureModel::TemperatureModel(QObject* parent)
    : QObject(parent) {}

double TemperatureModel::celsius() const { return m_celsius; }
double TemperatureModel::fahrenheit() const { return m_fahrenheit; }
double TemperatureModel::kelvin() const { return m_kelvin; }

void TemperatureModel::setCelsius(double value) {
    if (qFuzzyCompare(m_celsius, value)) return;
    m_celsius = value;
    emit celsiusChanged();
}

void TemperatureModel::setFahrenheit(double value) {
    if (qFuzzyCompare(m_fahrenheit, value)) return;
    m_fahrenheit = value;
    emit fahrenheitChanged();
}

void TemperatureModel::setKelvin(double value) {
    if (qFuzzyCompare(m_kelvin, value)) return;
    m_kelvin = value;
    emit kelvinChanged();
}
