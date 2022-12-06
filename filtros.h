/*!
 *  \class      Filtros
 *  \brief      Objeto capaz de aplicarle distintos filtros o modificaciones a una Imagen.
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
     * \brief Filtros Constructor del objeto Filtros
     */
//    Filtros();

    virtual Imagen aplicarFiltro(Imagen &imag) = 0;

    /*!
     * \brief aplicaFiltroPasaBajos Método que permite aplicarle el filtro de pasa bajos a una Imagen
     * \param[in] img Puntero a Imagen que se va a modificar.
     * \param[out] img Se modifica la imagen.
     */
//    Imagen aplicaFiltroPasaBajos(Imagen &img);

    /*!
     * \brief aplicaFiltroPasaAltos Método que permite aplicarle el filtro de pasa altos a una Imagen
     * \param[in] img Puntero a Imagen que se va a modificar.
     * \return Imagen con el filtro de pasa altos aplicado.
     */
//    Imagen aplicaFiltroPasaAltos(Imagen &pImg);

    /*!
     * \brief aplicaNegativo Método que permite obtener la negativa de la Imagen
     * \param[in] img Imagen a modificar.
     * \param[out] img Se modifica la Imagen.
     */
//    Imagen aplicaNegativo(Imagen &pImg);

    /*!
     * \brief ajusteContraste Método que permite ajustar el contraste de una Imagen
     * \param[in] img Imagen a la cual se le desea ajustar el contraste
     * \param[out] img Imagen ya modificada.
     */
//    void ajusteContraste(Imagen *img);

    /*!
     * \brief aumentarBrillo Método que permite aumentar el brillo de una Imagen.
     * \param[in] img Imagen a la cual se le desea aumentar el brillo.
     * \param[out] img Imagen modificada.
     */
//    void aumentarBrillo(Imagen *img);

    /*!
     * \brief reducirBrillo Método que permite reducir el brillo de una Imagen
     * \param[in] img Imagen a la cual se le desea reducir el brillo.
     * \param[out] img Imagen modificada.
     */
//    void reducirBrillo(Imagen *img);

    /*!
     * \brief aplicaFiltroMediana Método que permite aplicar el filtro de la mediana.
     * \param[in] img Imagen a la cual se le desea aplicar el filtro de la mediana.
     * \param[out] img Imagen modificada.
     */
//    Imagen aplicaFiltroMediana(Imagen &img);

//protected:
    /*!
     * \brief aplicaFiltroMedianaEsquinas Método protegido auxiliar que permite aplicar el filtro de la mediana
     * en las esquinas de la Imagen.
     * \param[in] imag Imagen a la cual se le aplica el filtro de la mediana
     * \param[out] imag Imagen ya modificada.
     */
//    Imagen aplicaFiltroMedianaEsquinas(Imagen &imag);

    /*!
     * \brief aplicaFiltroMedianaBordes Método protegido auxiliar que permite aplicar el filtro de la mediana
     * en los bordes de la Imagen.
     * \param[in] imag Imagen a la cual se le aplica el filtro de la mediana
     * \param[out] imag Imagen ya modificada.
     */
//    Imagen aplicaFiltroMedianaBordes(Imagen &imag);

    /*!
     * \brief aplicaFiltroMedianaCentro Método protegido auxiliar que permite aplicar el filtro de la mediana
     * en el centro de la Imagen.
     * \param[in] imag Imagen a la cual se le aplica el filtro de la mediana
     * \param[out] imag Imagen ya modificada.
     */
//    Imagen aplicaFiltroFiMedianaCentro(Imagen &imag);

};

#endif // FILTROS_H
