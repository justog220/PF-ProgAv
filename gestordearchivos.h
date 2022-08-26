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
