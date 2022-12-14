/*!
 *  \class      GestorDeArchivos
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
#include "ExcepcionArchivoCorrupto.h"

using namespace std;

class GestorDeArchivos
{
public:
    /*!
     * \brief leer Método virtual que al ser redefinido permite
     * leer una Imagen
     * \param[in] ruta Ruta donde está almacenada la Imagen
     * \return Imagen leída.
     */
    virtual Imagen leer(string ruta) = 0;

    /*!
     * \brief guardar Método virtual que al ser redefinido permite
     * guardar una Imagen.
     * \param[in] img Imagen que se desea guardar.
     */
    virtual void guardar(Imagen *img) = 0;
};

#endif // GESTORDEARCHIVOS_H
