#ifndef BRILLO_H
#define BRILLO_H

#include "filtros.h"
#include <limits>

class Brillo : public Filtros
{
public:
    Brillo(int opc);

    Imagen aplicarFiltro(Imagen &imagen) override;

    void aumentarBrillo(Imagen *imagen);

    void reducirBrillo(Imagen *imagen);

private:
    int diferencia;

    void consultarDiferencia(Imagen *imagen);

    bool seAumenta;

    bool seReduce;
};

#endif // BRILLO_H
