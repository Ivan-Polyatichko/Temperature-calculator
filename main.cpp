#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "temperaturemodel.h"
#include "temperaturecontroller.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    auto model = new TemperatureModel();
    auto controller = new TemperatureController(model);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("model", model);
    engine.rootContext()->setContextProperty("controller", controller);

    engine.loadFromModule("TemperatureConverter", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
