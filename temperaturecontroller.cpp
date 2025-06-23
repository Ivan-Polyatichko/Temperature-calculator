#include "temperaturecontroller.h"

TemperatureController::TemperatureController(TemperatureModel* model, QObject* parent)
    : QObject(parent), m_model(model) {}

void TemperatureController::updateFromCelsius(const QString& value) {
    bool ok = false;
    double val = value.toDouble(&ok);
    if (ok && val >= -273.15) {
        m_model->setCelsius(val);
        m_model->setFahrenheit(val * 9.0 / 5.0 + 32.0);
        m_model->setKelvin(val + 273.15);
    }
}

void TemperatureController::updateFromFahrenheit(const QString& value) {
    bool ok = false;
    double val = value.toDouble(&ok);
    double c = (val - 32.0) * 5.0 / 9.0;
    if (ok && c >= -273.15) {
        m_model->setCelsius(c);
        m_model->setFahrenheit(val);
        m_model->setKelvin(c + 273.15);
    }
}

void TemperatureController::updateFromKelvin(const QString& value) {
    bool ok = false;
    double val = value.toDouble(&ok);
    double c = val - 273.15;
    if (ok && val >= 0.0) {
        m_model->setCelsius(c);
        m_model->setFahrenheit(c * 9.0 / 5.0 + 32.0);
        m_model->setKelvin(val);
    }
}
