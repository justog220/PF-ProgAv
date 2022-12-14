/*!
 *  \class      FiltroMediana
 *  \brief      Clase que hereda de la clase Filtros métodos y los redefine para aplicar el filtro pasa bajos sobre una Imagen.
 *  \details    Permite que sobre una Imagen se aplique el filtro de pasa bajos.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 12-12-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H

#include "filtros.h"

class FiltroPasaBajos : public Filtros
{
public:
    /*!
     * \brief FiltroPasaBajos Constructor del objeto FiltroPasaBajos.
     */
    FiltroPasaBajos();

    /*!
     * \brief aplicarFiltro Método heredado de la case Filtros, redefinido
     * para aplicar el filtro pasa bajos.
     * \param[in] imag Imagen a la cual se le aplica el filtro.
     * \return Imagen con el filtro aplicado.
     */
    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // FILTROPASABAJOS_H
