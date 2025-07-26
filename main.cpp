#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Registro de Internet");
    w.show();
    return a.exec();
}
