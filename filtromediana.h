#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H

#include "filtros.h"

class FiltroMediana : public Filtros
{
public:
    FiltroMediana();

    Imagen aplicarFiltro(Imagen &imag) override;

private:
    Imagen realizarOperaciones(Imagen &imag);
};

#endif // FILTROMEDIANA_H
