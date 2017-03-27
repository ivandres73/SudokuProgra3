#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();//Muestra la ventana principal
    w.ejecutar();//crea el arreglo de QlineEdits
    w.pintar();//Muestra los QLineEdits

    return a.exec();
}
