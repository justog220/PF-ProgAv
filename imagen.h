/*!
 *  \class      Imagen
 *  \brief      Permite la representacion de una imagen a partir de un arreglo de Pixeles
 *  \details    Es un arreglo bidimensional de Pixeles. Conoce sus pixeles, su tamaño y el
 *              rango de sus pixeles. Puede cambiar su tamaño o sus pixeles y puede informar
 *              su tamaño y un pixel en espeifico. *
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug        Cualquier error encontrado se anota aquí, por ejemplo, un fallo
 *              de acceso a disco, fallas en liberación de memoria,
 *              malfuncionamientos de rutinas que se hayan encontrado, etc.
 *  \warning    Debe evitarse realizar muchas instancias de ella porque se requiere de mucha memoria
*/
#ifndef IMAGEN_H
#define IMAGEN_H

#include <vector>
#include "pixel.h"

using namespace std;

class Imagen
{
public:
    Imagen();

    /*!
     * \brief       setTamanio Método que permite cambiar el tamaño de una imágen
     *              cambia el valor de las columnas y filas.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void setTamanio();

    /*!
     * \brief       setPixel Método que permite modificar un Pixel de la imágen.
     * \param[in]   f Es el valor de la fila en la cual se modifica el Pixel.
     *              c Es el valor de la columna en la cual se modifica el Pixel.
     *              pixelNuevo Se pasa como parámetro un objeto Pixel que será el nuevo en
     *              la posicion indicada por f y c.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void setPixel(int f, int c, Pixel pixelNuevo);

    /*!
     * \brief       getPixel Método que permite devolver un Pixel de la imágen.
     * \param[in]   f Es el valor de la fila de la cual se devuelve el Pixel.
     *              c Es el valor de la columna de la cual se devuelve el Pixel.
     * \return      Devuelve un objeto de tipo Pixel.
     */
    Pixel getPixel(int f, int c);

    /*!
     * \brief       setFilas Método que permite establecer el número de filas de la imágen.
     * \param[in]   f Es la cantidad de filas que se busca establecer.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void setFilas(int f);

    /*!
     * \brief       setFilas Método que permite establecer el número de filas de la imágen.
     * \param[in]   f Es la cantidad de filas que se busca establecer.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void setColumnas(int c);

    void setRango(int valor);

    int getFilas();

    int getColumnas();

    int getRango();

private:
    vector<vector<Pixel>> imag;
    int filas, columnas;
    float rango;

};

#endif // IMAGEN_H
