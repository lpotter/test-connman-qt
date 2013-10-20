#include <QCoreApplication>
#include <connman-qt5/networkmanager.h>
#include <connman-qt5/networkservice.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetworkManager *netman = NetworkManagerFactory::createInstance();
    qDebug()  <<"Default route:"
             << netman->defaultRoute()->name()
             << netman->defaultRoute()->type()
             << netman->defaultRoute()->state();
    qDebug() << "\n";

    Q_FOREACH (NetworkService *service, netman->getServices("wifi")) {
        if (service->state() == "online" || service->state() == "ready")
            qDebug() << service->name() << service->state() << service->state() << service->connected() << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
        else
        qDebug() << (service->name().isEmpty() ? "<Hidden>" : service->name()) << service->state() << service->state() << service->connected();
    }
    qDebug() << "\n";
    qDebug() << "Network state is:"<< netman->state();
    qDebug() << "\n";
    Q_FOREACH (NetworkTechnology *tech, netman->getTechnologies()) {
        qDebug() << tech->name() << tech->type() <<"Powered:"<< tech->powered() <<"Connected:"<< tech->connected();
    }
    qDebug() << "\n";
    exit(0);
    return a.exec();
}
