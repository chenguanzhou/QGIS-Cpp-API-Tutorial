#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QgsMapCanvas;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
public slots:
    void open();//Open file

private:
    QgsMapCanvas *canvas;
};

#endif // MAINWINDOW_H
