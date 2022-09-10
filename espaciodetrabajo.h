/*!
 *  \class      Espacio de trabajo
 *  \brief      Clase capaz de gestionar donde se encuentran guardados los archivos.
 *  \details    Conoce la raiz de la ruta, las carpetas y es capaz de leer los
 *              archivos de una carpeta y almacenar el nombre de ellos en memoria.
 *              Es capaz de concatenar cadenas para devolver la ruta de un archivo en
 *              específico y de devolver el número de archivos.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug
 *  \warning
*/
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
