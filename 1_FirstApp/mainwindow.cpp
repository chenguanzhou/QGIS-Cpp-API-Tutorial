#include "mainwindow.h"
#include <QtCore>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <qgsmaplayerregistry.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),canvas(new QgsMapCanvas(this))
{
    this->resize(800,600);

    QMenuBar *menuBar = new QMenuBar(this);
    menuBar->addAction(tr("Open File"),this,SLOT(open()));
    this->setMenuBar(menuBar);

    this->setCentralWidget(canvas);
}

void MainWindow::open()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Open File"),QString(),
                                                "ESRI Shapefile(*.shp)");
    if (path.isEmpty())
        return;

    QgsVectorLayer *layer = new QgsVectorLayer(path,QFileInfo(path).completeBaseName(),"ogr");
    if (!layer->isValid())
    {
        QMessageBox::critical(this,tr("Error"),tr("Open file failed!\nReason:%1").arg(layer->lastError()));
        return;
    }

    QgsMapLayerRegistry::instance()->addMapLayer(layer);
    canvas->setLayerSet(QList<QgsMapCanvasLayer>()<<QgsMapCanvasLayer(layer));
    canvas->zoomToFullExtent();
}
