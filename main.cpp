#include "mainwindow.h"
#include <QApplication>

#include <TDARecordFile.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Proyecto de Organizacion de Archivos");

    MainWindow w;
    w.show();
    
    return a.exec();
}
