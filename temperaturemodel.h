#ifndef TEMPERATUREMODEL_H
#define TEMPERATUREMODEL_H

#include <QObject>

class TemperatureModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(double celsius READ celsius WRITE setCelsius NOTIFY celsiusChanged)
    Q_PROPERTY(double fahrenheit READ fahrenheit WRITE setFahrenheit NOTIFY fahrenheitChanged)
    Q_PROPERTY(double kelvin READ kelvin WRITE setKelvin NOTIFY kelvinChanged)

public:
    explicit TemperatureModel(QObject* parent = nullptr);

    double celsius() const;
    double fahrenheit() const;
    double kelvin() const;

    void setCelsius(double value);
    void setFahrenheit(double value);
    void setKelvin(double value);

signals:
    void celsiusChanged();
    void fahrenheitChanged();
    void kelvinChanged();

private:
    double m_celsius = 0.0;
    double m_fahrenheit = 32.0;
    double m_kelvin = 273.15;
};

#endif
