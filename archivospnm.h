#ifndef ARCHIVOSPNM_H
#define ARCHIVOSPNM_H
#include "gestordearchivos.h"
#include <fstream>

class ArchivosPNM : public GestorDeArchivos
{
public:
    ArchivosPNM();

    Imagen leer(string ruta) override;

    void guardar(string ruta, Imagen *img) override;

private:
    fstream archi;

    string identificador;
};

#endif // ARCHIVOSPNM_H
