#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H

#include "filtros.h"

class FiltroPasaBajos : public Filtros
{
public:
    FiltroPasaBajos();

    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // FILTROPASABAJOS_H
