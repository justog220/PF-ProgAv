/*!
 *  \class      AlgoritmoDelPintor
 *  \brief      Objeto capaz de aplicarle el algoritmo del pintor a una Imagen.
 *  \details    A partir de un Pixel inicial, busca los vecinos de este teniendo en cuenta cierta
 *              nivel de tolerancia. Habiendo identificado un Pixel como vecino, lo pinta de azul.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 24-11-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef ALGORITMODELPINTOR_H
#define ALGORITMODELPINTOR_H

#include <iostream>
#include <vector>
#include "imagen.h"

///Struct Posicion que consta de ambas coordenadas
struct Posicion
{ int f, c;
};




class AlgoritmoDelPintor
{
public:
    /*!
     * \brief       AlgoritmoDelPintor Constructor del objeto algoritmo del pintor.
     * \param[in]   img Imagen sobre la que se desea pintar una región.
     */
    AlgoritmoDelPintor(Imagen img);


    /*!
     * \brief       aplicarAlgoritmo Método que permite aplicar el algoritmo.
     * \param[in]   f_0 Es el valor de la fila desde la cuál se desean pintar los vecinos.
     * \param[in]   c_0 Es el valor de la columna desde la cuál se desean pintar los vecinos.
     * \return      Devuelve la Imagen a la cual se le han modificado el pixel de inicio
     *              y sus vecinos.
     */
    Imagen aplicarAlgoritmo(int f_0, int c_0);

private:
    /*!
     * \param       imag Imagen sobre la cual se aplica el algoritmo.
     */
    Imagen imag;

    /*!
     * \brief       pintarVecinos Método privado que permite pintar aquellos Pixel que sean vecinos.
     * \param[in]   f Fila del Pixel bajo análisis.
     * \param[in]   c Columna del Pixel bajo análisis
     * \param[in]   pixelComparacion Pixel respecto al cual se analiza si es vecino.
     * \param[in]    tolerancia Rango de tolerancia segun el cual se juzga si es vecino o no.
     */
    void pintarVecinos(int f, int c, Pixel pixelComparacion, unsigned int tolerancia);

    /*!
     * \brief       preguntarRangoDeTolerancia Método que permite preguntarle al usuario el rango de tolerancia.
     * \param[in]   maximo_rango_imag El máximo rango de una Imagen.
     * \return      Devuelve un uint que es el rango de tolerancia.
     */
    unsigned int preguntarRangoDeTolerancia(int maximo_rango_imag);

    /*!
     * \param       fue_analizado Matriz de booleanos del tamaño de imag, cada elemento
     * representa un Pixel de la Imagen y el booleano almacenado tiene cierto valor dependiendo
     * de si fue analizado o no.
     */
    vector<vector<bool>> fue_analizado;

    /*!
     * \brief       inicializarMatrizDeAnalisis Método que permite inicializar el
     *              atributo fue_analizado.
     * \param[in]   f Número de filas que tiene la imágen.
     * \param[in]   c Número de columnas que tiene la imágen.
     */
    void inicializarMatrizDeAnalisis(int f, int c);

    /*!
     * \brief       esVecino Método que devuelve si un pixel es vecino de otro o no.
     * \param[in]   pixel_pintado Pixel respecto al cual se compara.
     * \param[in]   analisis Pixel bajo análisis
     * \return      Crea el objeto.
     */
    bool esVecino(Pixel pixel_pintado, Pixel analisis, unsigned int tolerancia);

    /*!
     * \param       vecinos Vector de Posiciones, que representa la de los vecinos.
    */

    /*      7 0 1
            6 p 2
            5 4 3  */
    vector < Posicion > vecinos = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

    /*!
     * \param profundidad Profundidad del método recursiva.
     */
    int profundidad;

};

#endif // ALGORITMODELPINTOR_H
