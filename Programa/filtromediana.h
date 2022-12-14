/*!
 *  \class      FiltroMediana
 *  \brief      Clase que hereda de la clase Filtros métodos y los redefine para aplicar el filtro de la mediana.
 *  \details    Aplica el filtro de la mediana sobre una Imagen.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 12-12-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H

#include "filtros.h"

class FiltroMediana : public Filtros
{
public:
    /*!
     * \brief FiltroMediana Constructor del objeto FiltroMediana
     */
    FiltroMediana();

    /*!
     * \brief aplicarFiltro Método heredado de la case Filtros, redefinido
     * para aplicar el filtro de la mediana.
     * \param[in] imag Imagen a la cual se le desea aplicar el filtro.
     * \return Imagen con el filtro aplicado.
     */
    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // FILTROMEDIANA_H
