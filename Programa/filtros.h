/*!
 *  \class      Filtros
 *  \brief      Clase que virtualiza métodos para la aplicacion de diversos filtros.
 *  \details    A partir de una Imagen, se le aplican distintas modificaciones.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 24-11-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROS_H
#define FILTROS_H

#include <algorithm>

#include "imagen.h"
#include "procesadorestadistico.h"

class Filtros
{
public:
    /*!
     * \brief aplicarFiltro Método virtual para la aplicación de Filtros.
     * \param[in] imag Imagen sobre la cual se aplica un filtro.
     * \return Imagen con el filtro aplicado.
     */
    virtual Imagen aplicarFiltro(Imagen &imag) = 0;
};

#endif // FILTROS_H
