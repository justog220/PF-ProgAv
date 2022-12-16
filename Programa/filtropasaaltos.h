/*!
 *  \class      FiltroPasaAltos
 *  \brief      Clase que hereda de la clase Filtros métodos y los redefine para aplicar el filtro pasa altos sobre una Imagen.
 *  \details    Permite que sobre una Imagen se aplique el filtro de pasa altos.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 12-12-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROPASAALTOS_H
#define FILTROPASAALTOS_H

#include "filtros.h"

class FiltroPasaAltos : public Filtros
{
public:
    /*!
     * \brief FiltroPasaAltos Constructor del objeto FiltroPasaAltos.
     */
    FiltroPasaAltos();

    /*!
     * \brief aplicarFiltro Método heredado de la case Filtros, redefinido
     * para aplicar el filtro pasa altos.
     * \param[in] imag Imagen a la cual se le aplica el filtro.
     * \return Imagen con el filtro pasa altos aplicado.
     */
    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // FILTROPASAALTOS_H
