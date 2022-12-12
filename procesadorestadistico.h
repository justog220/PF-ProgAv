/*!
 *  \class      ProcesadorEstadistico
 *  \brief      Clase que permite realizar diversos cálculos estadísticos.
 *  \details    Permite hacer diversos cálculo estadísticos como encontrar la frecuencia de R, G o B, devolver estos
 * valores más frecuentes o hallar los valores máximo y mínimos.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 24-11-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H

#include "imagen.h"
#include <iostream>

class ProcesadorEstadistico
{
public:
    /*!
     * \brief ProcesadorEstadistico Constructor de ProcesadorEstadistico
     */
    ProcesadorEstadistico();

    /*!
     * \brief devuelveFrecuenciaR Devuelve la frecuencia de los distintos niveles de R
     * \param[in] img Imagen de la cual se desea conocer la frecuencia de R.
     * \return vector de enteros donde cada posicion del vector es el nivel de R y el entero almacenado la frecuencia con
     * la que aparece este nivel.
     */
    vector<int> devuelveFrecuenciaR(Imagen &img);

    /*!
     * \brief devuelveFrecuenciaG Devuelve la frecuencia de los distintos niveles de G.
     * \param[in] img Imagen de la cual se desea conocer la frecuencia de G.
     * \return vector de enteros donde cada posicion del vector es el nivel de G y el entero almacenado la frecuencia con
     * la que aparece este nivel.
     */
    vector<int> devuelveFrecuenciaG(Imagen &img);

    /*!
     * \brief devuelveFrecuenciaB Devuelve la frecuencia de los distintos niveles de B
     * \param[in] img Imagen de la cual se desea conocer la frecuencia de B.
     * \return vector de enteros donde cada posicion del vector es el nivel de B y el entero almacenado la frecuencia con
     * la que aparece este nivel.
     */
    vector<int> devuelveFrecuenciaB(Imagen &img);

    /*!
     * \brief devuelveFrecuenciaIntensidad Devuelve la frecuencia de los distintos niveles de intensidad.
     * \param[in] img Imagen de la cual se desea conocer la frecuencia de las intensidades.
     * \return vector de enteros donde cada posición del vector es el nivel de intensidad y el entero almacenado
     * la frecuencia con la que aparece este nivel.
     */
    vector<int> devuelveFrecuenciaIntensidad(Imagen &img);

    /*!
     * \brief devolverFrecuenciaPromedio Devuelve el promedio de la frecuencia de RGB para cada nivel de intensidad.
     * \param[in] img Imagen de la cual se desea conocer la frecuencia promedio de las intensidades.
     * \return vector de eneteros donde cada posición del vector es el nivel de intensidad y el entero almacenado
     * la frecuencia con la que aparece este nivel.
     */
    vector<int> devolverFrecuenciaPromedio(Imagen &img);

    /*!
     * \brief devuelveRMasFrecuente Devuelve el nivel de R que mas se repite.
     * \param[in] img Imagen de la cuál se desea conocer el nivel de R más frecuente
     * \return El nivel de R que mas se repite.
     */
    int devuelveRMasFrecuente(Imagen &img);

    /*!
     * \brief devuelveRMasFrecuente Devuelve el nivel de G que mas se repite.
     * \param[in] img Imagen de la cuál se desea conocer el nivel de G más frecuente
     * \return El nivel de G que mas se repite.
     */
    int devuelveGMasFrecuente(Imagen &img);

    /*!
     * \brief devuelveRMasFrecuente Devuelve el nivel de B que más se repite.
     * \param[in] img Imagen de la cuál se desea conocer el nivel de B más frecuente
     * \return El nivel de B que mas se repite.
     */
    int devuelveBMasFrecuente(Imagen &img);

    /*!
     * \brief devuelveRMasFrecuente Devuelve el nivel de intensidad que más se repite.
     * \param[in] img Imagen de la cuál se desea conocer el nivel de intensidad más frecuente
     * \return El nivel de intensidad que mas se repite.
     */
    int devuelveIntensidadMasFrecuente(Imagen &img);

    /*!
     * \brief hallarMaximoMinimoR Halla el mínimo y máximo nivel de R que aparece en una Imagen.
     * \param[in] img Imagen a la cuál se le desea conocer los niveles extremos de R.
     * \return vector de enteros con el máximo nivel en la primer posicion del vector y el mínimo en la segunda.
     */
    vector<int> hallarMaximoMinimoR(Imagen &img);

    /*!
     * \brief hallarMaximoMinimoG Halla el mínimo y máximo nivel de G que aparece en una Imagen.
     * \param[in] img Imagen a la cuál se le desea conocer los niveles extremos de G.
     * \return vector de enteros con el máximo nivel en la primer posicion del vector y el mínimo en la segunda.
     */
    vector<int> hallarMaximoMinimoG(Imagen &img);

    /*!
     * \brief hallarMaximoMinimoB Halla el mínimo y máximo nivel de B que aparece en una Imagen.
     * \param[in] img Imagen a la cuál se le desea conocer los niveles extremos de B.
     * \return vector de enteros con el máximo nivel en la primer posicion del vector y el mínimo en la segunda.
     */
    vector<int> hallarMaximoMinimoB(Imagen &img);

    /*!
     * \brief devuelveIntensidadMedia Devuelve el valor medio de la intensidad de una Imagen.
     * \param[in] img Imagen a la cuál se le desea conocer la intensidad media.
     * \return  Valor de la intensidad media de una Imagen.
     */
    int devolverIntensidadMedia(Imagen &img);

    /*!
     * \brief informarDatosEstadisticos Método que permite informar diversos datos
     * estadísticos.
     * \param[in] img Imagen de la cuál se desea conocer los datos estadísticos.
     */
    void informarDatosEstadisticos(Imagen &img);

    /*!
     * \brief devolverPromedioRGB Método que devuelve el promedio de la intensidad de R, G y B
     * en una Imagen
     * \param[in] img Imagen de la cual se desea conocer el promedio de R, G y B
     * \return vector que contiene el promedio de r (vector[0]), g (vector[1]) y b (vector[2])
     */
    vector<float> devolverPromedioRGB(Imagen &img);

    /*!
     * \brief devolverDesviacionEstandarRGB Método que devuelve las desviaciones estandar de R, G y B.
     * \param[in] img Imagen de la cual se desea conocer las desviaciones estandares.
     * \return  Desviacion de R(vector[0]), G (vector[1]) y B (vector[2]).
     */
    vector<float> devolverDesviacionEstandarRGB(Imagen &img);
};

#endif // PROCESADORESTADISTICO_H
