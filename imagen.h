/*!
 *  \class      Imagen
 *  \brief      Permite la representacion de una imagen a partir de un arreglo de Pixeles
 *  \details    Es un arreglo bidimensional de Pixeles. Conoce sus pixeles, su tamaño y el
 *              rango de sus pixeles. Puede cambiar su tamaño o sus pixeles y puede informar
 *              su tamaño y un pixel en espeifico. *
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug
 *  \warning    Debe evitarse realizar muchas instancias de ella porque se requiere de mucha memoria
*/
#ifndef IMAGEN_H
#define IMAGEN_H

#include <vector>
#include <string>
#include "pixel.h"

using namespace std;

class Imagen
{
public:
    /*!
     * \brief Imagen Constructor del objeto Imagen.
     */
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
     * \brief setIdentificador Permite establecer el identificador de la Imagen.
     * \param[in] id Nuevo identificador de la Imagen.
     */
    void setIdentificador(string id);

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

    /*!
     * \brief getIdentificador Devuelve el identificador de la Imagen.
     * \return string que representa el identificado de la Imagen.
     */
    string getIdentificador();

    /*!
     * \brief formaParteDeLaImagen Devuelve si una coordenada (f, c) está dentro
     * de la Imagen o no.
     * \param[in] f Valor de la fila.
     * \param[in] c Valor de la columna.
     * \return bool que indica si forma parte de la Imagen o no.
     */
    bool formaParteDeLaImagen(int f, int c);

    /*!
     * \brief elPixelEsEsquina Devuelve si un Pixel es esquina o no
     * \param[in] f Valor de la fila.
     * \param[in] c Valor de la columna.
     * \return bool que indica si es esquina o no.
     */
    bool elPixelEsEsquina(int f, int c);

    /*!
     * \brief borrarImagen Método que permite vaciar el arreglo de Pixel.
     */
    void borrarImagen();

    /*!
     * \brief esDeIntensidades Devuelve si una imagen es de intensidades o no.
     * \return bool que indica si una Imagen es de intensidades o no.
     */
    bool esDeIntensidades();

    /*!
     * \brief getNroPixeles Devuelve el número de Pixel de una Imagen.
     * \return Número de pixeles.
     */
    int getNroPixeles();

    /*!
     * \brief getInformacion Devuelve la información de la Imagen.
     * \return Información de la Imagen.
     */
    string getInformacion();

    /*!
     * \brief setInformacion Establece la información de la Imagen.
     * \param value Nueva información de la Imagen.
     */
    void setInformacion(string value);

private:
    /*! \param imag Es la imágen que se busca graficar.\n\n Es un arreglo
     *              bidimensional de Pixeles, cuyo tamaño estará dado por
     *              el número de filas y columnas leídos de la imágen.
    */
    vector<vector<Pixel>> imag;

    /*! \param filas Atributo que representa la cantidad de filas de Pixeles que tiene la imágen.
    */
    int filas;

    /*! \param columnas Atributo que representa la cantidad de columnas de Pixeles que tiene la imágen.
    */
    int columnas;

    /*! \param rango Atributo que almacena el valor del rango de la imágen .
    */
    float rango;

    /*!
     * \param identificador Identificador de la Imagen.
     */
    string identificador;

    /*!
     * \param informacion Información de la Imagen.
     */
    string informacion;

};

#endif // IMAGEN_H
