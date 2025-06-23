#ifndef TEMPERATURECONTROLLER_H
#define TEMPERATURECONTROLLER_H

#include <QObject>
#include "temperaturemodel.h"

class TemperatureController : public QObject {
    Q_OBJECT
public:
    explicit TemperatureController(TemperatureModel* model, QObject* parent = nullptr);

    Q_INVOKABLE void updateFromCelsius(const QString& value);
    Q_INVOKABLE void updateFromFahrenheit(const QString& value);
    Q_INVOKABLE void updateFromKelvin(const QString& value);

private:
    TemperatureModel* m_model;
};

#endif
