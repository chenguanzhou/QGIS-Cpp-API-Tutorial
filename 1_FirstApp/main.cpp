#include "mainwindow.h"
#include <QDir>
#include <qgsapplication.h>

int main(int argc, char *argv[])
{
    QgsApplication a(argc, argv, true);
    QgsApplication::setPluginPath(QDir::currentPath()+"/plugins");
    QgsApplication::initQgis();
    MainWindow w;
    w.show();

    return a.exec();
}
