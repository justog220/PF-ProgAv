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
     * \brief       setColumnas Método que permite establecer el número de columnas de la imágen.
     * \param[in]   c Es la cantidad de columnas que se busca establecer.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void setColumnas(int c);

    /*!
     * \brief setRango Define el rango leído de la imágen, para luego graficarla correctamente.
     * \param valor Es el valor de rango a establecer.
     */
    void setRango(int valor);

    /*!
     * \brief getFilas Se utiliza para conocer el número de filas de la imágen.
     * \return Devuelve un entero de 4 bytes que representa el número de filas de la imágen.
     */
    int getFilas();

    /*!
     * \brief getColumnas Se utiliza para conocer el número de columnas de la imágen.
     * \return Devuelve un entero de 4 bytes que representa el número de filas de la imágen.
     */
    int getColumnas();

    /*!
     * \brief getRango Se utiliza para conocer el rango de los píxeles de la imágen.
     * \return Devuelve un entero de 4 bytes que representa el rango.
     */
    int getRango();

private:
    /*! \param imag Es la imágen que se busca graficar.\n\n Es un arreglo
     *              bidimensional de Pixeles, cuyo tamaño estará dado por
     *              el número de filas y columnas leídos de la imágen.
    */
    vector<vector<Pixel>> imag;

    /*! \param filas Parámetro que representa la cantidad de filas de Pixeles que tiene la imágen.
    */
    int filas;

    /*! \param columnas Parámetro que representa la cantidad de columnas de Pixeles que tiene la imágen.
    */
    int columnas;

    /*! \param rango Parámetro que almacena el valor del rango de la imágen .
    */
    float rango;

};

#endif // IMAGEN_H
