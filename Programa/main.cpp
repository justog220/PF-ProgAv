#include <QApplication>

#include "sistema.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString nombre = QString::fromStdString("Software de Procesamiento Digital de Imágen");

    a.setApplicationName(nombre);

    Sistema sistema;

    sistema.ejecutar(&a);

    return 0;
}
