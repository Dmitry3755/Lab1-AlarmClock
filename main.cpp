#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    mainWindow.setStyleSheet("background: rgb(190, 190, 190);");
    return app.exec();
}
