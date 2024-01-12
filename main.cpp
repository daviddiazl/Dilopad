#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("windows");
    a.setApplicationDisplayName("Dilopad");
    a.setStyleSheet("QApplication { background-color : white ; color : yellow}");

    MainWindow w;
    w.show();
    return a.exec();
}
