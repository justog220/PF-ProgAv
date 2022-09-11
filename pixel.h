/*!
 *  \class      Pixel
 *  \brief      Modela un pixel de una imagen..
 *  \details    Representa un pixel de los distintos tipos de imagen, indistintamente
 *              si es de intensidades, RGB o monocromatico. Tiene valores enteros para
 *              rojo, verde y azul. Puede cambiar estos valores y devolverlos en caso de
 *              ser necesario.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre        Idealmente deben inicializarse solo para formar parte de la representacion
 *              de una imagen.
 *  \bug        Ingreso int pero mis parametros son flotantes. Al momento de la implementacion
 *              se penso en flotantes por operaciones que podrian realizarse luego (filtros, pseudocoloreado, etc)
 *              sin embargo de los archivos leo enteros.
 *  \warning
*/
#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:
    ///Constructor del objeto Pixel
    Pixel();

    /*!
     * \brief       setPixelRGB Método que permite cambiar los valores de R, G y B de un tipo de pixel RGB.
     * \param[in]   valor_r Es el valor de R que se quiere establecer.
     *              valor_g Es el valor de G que se quiere establecer.
     *              valor_b Es el valor de B que se quiere establecer.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void setPixelRGB(int valor_r, int valor_g, int valor_b);

    /*!
     * \brief       setPixelMonocr Método que permite establecer los valores de R, G y B de un tipo de pixel monocromático
     * \param[in]   valor   Es el valor que se establecerá en los tres parámetros.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void setPixelMonocr(int valor);

    /*!
     * \brief       setPixelEscala Metodo que permite establecer los valores de R, G y B para un pixel
     *              que forme parte de una imágen en escala de grises.
     * \param[in]   valor   Es el valor que se establecerá en los tres parámetros.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void setPixelEscala(int valor);

    /*!
     * \brief getR Devuelve el valor de R.
     * \return El método retorna como salida de un valor flotante de
     *         8 bytes
     */
    float getR();

    /*!
     * \brief getG Devuelve el valor de G.
     * \return El método retorna como salida de un valor flotante de
     *         8 bytes
     */
    float getG();

    /*!
     * \brief getB Devuelve el valor de B.
     * \return El método retorna como salida de un valor flotante de
     *         8 bytes
     */
    float getB();

private:
    /*! \param r Parámetro que alamcena el valor de rojo.
    */
    float r;

    /*! \param g Parámetro que alamcena el valor de verde.
    */
    float g;

    /*! \param b Parámetro que alamcena el valor de azul.
    */
    float b;

};

#endif // PIXEL_H
