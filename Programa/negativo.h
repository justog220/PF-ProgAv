/*!
 *  \class      Negativo
 *  \brief      Clase que hereda de la clase Filtros métodos y los redefine para obtener el negativo de una Imagen.
 *  \details    Permite obtener el negativo de una Imagen.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 12-12-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef NEGATIVO_H
#define NEGATIVO_H

#include "filtros.h"

class Negativo : public Filtros
{
public:
    /*!
     * \brief Negativo Constructor del objeto Negativo.
     */
    Negativo();

    /*!
     * \brief aplicarFiltro Método heredado de la case Filtros, redefinido
     * para obtener el negativo de una imagen.
     * \param[in] imag Imagen a la cual se le obtiene el negativo.
     * \return Imagen que es el negativo de una Imagen.
     */
    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // NEGATIVO_H
