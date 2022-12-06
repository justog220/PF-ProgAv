#ifndef FILTROPASAALTOS_H
#define FILTROPASAALTOS_H

#include "filtros.h"

class FiltroPasaAltos : public Filtros
{
public:
    FiltroPasaAltos();

    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // FILTROPASAALTOS_H
