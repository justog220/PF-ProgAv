/*!
 *  \class      Contraste
 *  \brief      Clase que hereda de la clase Filtros métodos y los redefine para corregir el contraste de una Imagen.
 *  \details    Corrige el contraste de una Imagen.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 12-12-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef CONTRASTE_H
#define CONTRASTE_H

#include "filtros.h"

class Contraste : public Filtros
{
public:
    /*!
     * \brief Contraste Constructor del objeto Contraste.
     */
    Contraste();

    /*!
     * \brief aplicarFiltro Método heredado de la case Filtros, redefinido
     * para la corrección del contraste.
     * \param[in] imag Imagen a la cual se le aplica la correción de contraste.
     * \return Imagen con la correción de contraste aplicada.
     */
    Imagen aplicarFiltro(Imagen &imag) override;
};

#endif // CONTRASTE_H
