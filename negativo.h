#ifndef NEGATIVO_H
#define NEGATIVO_H

#include "filtros.h"

class Negativo : public Filtros
{
public:
    Negativo();

    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // NEGATIVO_H
