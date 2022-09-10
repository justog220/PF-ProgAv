/*!
 *  \class      Gestor de archivos
 *  \brief      Clase abstracta de la cual heredan metodos para leer y escribir archivos otras clases.
 *  \details    Tiene una imagen, la cual es capaz de cargar. Conoce el ancho
 *              y alto de la ventana y la escala utilizada. Se asocia con un
 *              espacio de trabajo para conocer distintas rutas y archivos. Por
 *              otro lado, es capaz de responder ante distintos eventos de mouse y teclado.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug        La ventana no se abre con el tamaño de la imagen.
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
