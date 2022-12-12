/*!
 *  \class      Binarizado
 *  \brief      Clase que hereda de la clase Filtros métodos y los redefine para binarizar una Imagen.
 *  \details    Obtiene un nivel y a partir de él binariza una Imagen.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 12-12-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef BINARIZADO_H
#define BINARIZADO_H

#include "filtros.h"

class Binarizado : public Filtros
{
public:
    /*!
     * \brief Binarizado Constructor del objeto Binarizado.
     */
    Binarizado();

    /*!
     * \brief aplicarFiltro Método heredado de la case Filtros, redefinido
     * para la aplicación del binarizado de una imagenes de intensidades a partir
     * de un nivel especificado por el usuario.
     * \param[in] imagen Imagen que se busca binarizar.
     * \return Imagen binarizada.
     */
    Imagen aplicarFiltro(Imagen &imagen) override;

private:
    /*!
     * \brief sePuedeBinarizar Evalúa si una Imagen se puede binarizar.
     * \param[in] imagen Imagen que se evalúa.
     * \return Retorna verdadero si se puede binarizar y verdadero en el caso
     * contrario.
     */
    bool sePuedeBinarizar(Imagen &imagen);

    /*!
     * \brief obtenerPuntoBinarizacion Obtiene el nivel a partir del
     * cual binarizar.
     * \param[in] imagen Imagen que se busca binarizar.
     * \return Nivel a partir del que se binariza.
     */
    int obtenerPuntoBinarizacion(Imagen &imagen);


};

#endif // BINARIZADO_H
