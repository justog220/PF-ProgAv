#ifndef SISTEMA_H
#define SISTEMA_H

#include "espaciodetrabajo.h"
#include "graficador.h"

class Sistema
{
public:
    Sistema();

    void ejecutar(QApplication *a);

private:
    EspacioDeTrabajo espDeTrabajo;
    Graficador graf;
};

#endif // SISTEMA_H
