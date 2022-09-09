#include <QApplication>

#include "sistema.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Sistema sistema;

    sistema.ejecutar(&a);

    return 0;
}
