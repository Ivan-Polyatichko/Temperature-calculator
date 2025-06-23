#include "temperaturecontroller.h"

TemperatureController::TemperatureController(TemperatureModel* model, QObject* parent)
    : QObject(parent), m_model(model) {}

void TemperatureController::updateFromCelsius(const QString& value) {
    bool ok = false;
    double c = value.toDouble(&ok);
    if (!ok || c < -273.15) return;

    double f = c * 9.0 / 5.0 + 32.0;
    double k = c + 273.15;

    m_model->setCelsius(c);
    m_model->setFahrenheit(f);
    m_model->setKelvin(k);
}

void TemperatureController::updateFromFahrenheit(const QString& value) {
    bool ok = false;
    double f = value.toDouble(&ok);
    if (!ok) return;

    double c = (f - 32.0) * 5.0 / 9.0;
    if (c < -273.15) return;

    double k = c + 273.15;

    m_model->setCelsius(c);
    m_model->setFahrenheit(f);
    m_model->setKelvin(k);
}

void TemperatureController::updateFromKelvin(const QString& value) {
    bool ok = false;
    double k = value.toDouble(&ok);
    if (!ok || k < 0.0) return;

    double c = k - 273.15;
    double f = c * 9.0 / 5.0 + 32.0;

    m_model->setCelsius(c);
    m_model->setFahrenheit(f);
    m_model->setKelvin(k);
}
