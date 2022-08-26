#ifndef ARCHIVOSAIC_H
#define ARCHIVOSAIC_H
#include "gestordearchivos.h"
#include <fstream>


class ArchivosAIC : public GestorDeArchivos
{
public:
    ArchivosAIC();

    Imagen leer(string ruta) override;

    void guardar(string ruta, Imagen *img) override;

private:
    fstream archi;
};

#endif // ARCHIVOSAIC_H
