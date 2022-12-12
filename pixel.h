/*!
 *  \class      Pixel
 *  \brief      Clase que modela un pixel de una imagen.
 *  \details    Representa un pixel de los distintos tipos de imagen, indistintamente
 *              si es de intensidades, RGB o monocromatico. Tiene valores enteros para
 *              rojo, verde y azul. Puede cambiar estos valores y devolverlos en caso de
 *              ser necesario.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre        Idealmente deben inicializarse solo para formar parte de la representacion
 *              de una imagen.
 *  \bug
 *  \warning
*/
#ifndef PIXEL_H
#define PIXEL_H

#include <vector>

using namespace std;

class Pixel
{
public:
    ///Constructor del objeto Pixel
    Pixel();

    Pixel(int r, int green, int blue);
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
    int getR();

    /*!
     * \brief getG Devuelve el valor de G.
     * \return El método retorna como salida de un valor flotante de
     *         8 bytes
     */
    int getG();

    /*!
     * \brief getB Devuelve el valor de B.
     * \return El método retorna como salida de un valor flotante de
     *         8 bytes
     */
    int getB();

    /*!
     * \brief getIntensidad Devuelve la intensidad del Pixel, si es de intensidades.
     * \return Entero que representa la intensidad de un Pixel.
     */
    int getIntensidad();

    /*!
     * \brief aumentarBrillo Método que permite aumentar el brillo de un
     * Pixel.
     */
    void aumentarBrillo(int aumento);

    /*!
     * \brief reducirBrillo Método que permite reducir el brillo de
     * un Pixel.
     */
    void reducirBrillo();

    /*!
     * \brief ajusteContraste Método que ajusta (R, G, B) para ajustar el contraste de una Imagen.
     * \param[in] maximo_minimo_R Vector con el valor de máximo y mínimo de R.
     * \param[in] maximo_minimo_G Vector con el valor de máximo y mínimo de G.
     * \param[in] maximo_minimo_B Vector con el valor de máximo y mínimo de B.
     * \param[in] rango Valor del rango de una Imagen.
     */
    void ajusteContraste(vector<int> maximo_minimo_R, vector<int> maximo_minimo_G, vector<int> maximo_minimo_B, int rango);

private:
    /*! \param r Parámetro que almacena el valor de rojo.
    */
    int r;

    /*! \param g Parámetro que almacena el valor de verde.
    */
    int g;

    /*! \param b Parámetro que almacena el valor de azul.
    */
    int b;


};

#endif // PIXEL_H
