#include <QApplication>

#include "espaciodetrabajo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EspacioDeTrabajo espacio;

    espacio.ejecutar(&a);

    return 0;
}
