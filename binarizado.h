#ifndef BINARIZADO_H
#define BINARIZADO_H

#include "filtros.h"

class Binarizado : public Filtros
{
public:
    Binarizado();

    Imagen aplicarFiltro(Imagen &imagen) override;

private:
    bool sePuedeBinarizar(Imagen &imagen);

    int obtenerPuntoBinarizacion(Imagen &imagen);


};

#endif // BINARIZADO_H
