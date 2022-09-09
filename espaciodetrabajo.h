#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H

#include <string>


#include "archivosaic.h"
#include "archivospnm.h"
#include <dirent.h>


class EspacioDeTrabajo
{
public:
    EspacioDeTrabajo();

    void cargarCarpetas();

    vector<string> getListaDeArchivos(string ruta);

    string getRuta(int opcDir, int opcArch=-8);

    int getNroArchivos();

private:
    string raiz="./Imagenes/";

    vector<string> carpetas;

    vector<string> listaDeArchivos;

};

#endif // ESPACIODETRABAJO_H
