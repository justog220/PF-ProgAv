/*!
 *  \class      Gestor de archivos
 *  \brief      Clase abstracta de la cual heredan metodos para leer y escribir archivos otras clases.
 *  \details    Virtualiza metodos para leer y escribir archivos, que luego serán utilizados por sus clases
 *              hijas.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H

#include <string>
#include "imagen.h"
#include <iostream>

using namespace std;

class GestorDeArchivos
{
public:
    //GestorDeArchivos();

    virtual Imagen leer(string ruta) = 0;

    virtual void guardar(string ruta, Imagen *img) = 0;
};

#endif // GESTORDEARCHIVOS_H
