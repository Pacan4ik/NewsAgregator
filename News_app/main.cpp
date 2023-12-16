#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("Новостной агрегатор");
    QApplication a(argc, argv);
    MainWindow mw;
    mw.setFixedSize(1000, 600);
    mw.show();
    return a.exec();
}
