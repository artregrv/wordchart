#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);

    QQmlApplicationEngine engine;
    engine.loadFromModule("wc", "Main");

    return application.exec();
}
