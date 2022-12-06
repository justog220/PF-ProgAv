#ifndef CONTRASTE_H
#define CONTRASTE_H

#include "filtros.h"

class Contraste : public Filtros
{
public:
    Contraste();

    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // CONTRASTE_H
