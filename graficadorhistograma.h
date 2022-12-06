/*!
 *  \class      GraficadorHistograma
 *  \brief      Clase encargada de mostrar por pantalla el histograma de una Imagen.
 *  \details    Se construye a partir de las frecuencias de los distintos valores de
 * R, G y B de una Imagen y luego es capaz de graficar el histograma.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 24-11-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef GRAFICADORHISTOGRAMA_H
#define GRAFICADORHISTOGRAMA_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <vector>
#include "imagen.h"
#include "procesadorestadistico.h"

using namespace std;

class GraficadorHistograma: public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    /*!
     * \brief GraficadorHistograma Constructor del objeto GraficadorHistograma
     * \param[in] img Imagen de la cual se busca graficar el Histograma.
     */
    GraficadorHistograma(Imagen &img);

    /*!
     * \brief initializeGL Inicializa los recursos necesarios para utilizar OpenGL.
     */
    void initializeGL();

    /*!
     * \brief resizeGL Se modifica el tamaño cuando se modifica el tamaño de la ventana.
     * \param[in] rango Nuevo ancho.
     * \param[in] frecuencia Nuevo alto.
     */
    void resizeGL(int pAncho, int pAlto);

    /*!
     * \brief paintGL Permite graficar.
     */
    void paintGL();

    /*!
     * \brief graficarHistograma Permite la representación gráfica del histograma
     * haciendo uso de la librería OpenGL.
     */
    void graficarHistograma();



private:
    /*!
     * \param histograma
     */
    Imagen imagenAnalisis;

    /*!
     * \param frecuenciaR Vector que representa las frecuencias para los distintos
     * niveles de rojo. Cada posición equivale a un nivel de rojo y el entero almacenado la frecuencia
     * de este nivel.
     */
    vector<int> frecuenciaR;

    /*!
     * \param frecuenciaG Vector que representa las frecuencias para los distintos
     * niveles de verde. Cada posición equivale a un nivel de verde y el entero almacenado la frecuencia
     * de este nivel.
     */
    vector<int> frecuenciaG;

    /*!
     * \param maximaFrecuenciaR Atributo que representa cuantas veces aparece el nivel de mas
     * frecuente, sin importar si corresponde a R, G o B.
     */
    int maximaFrecuencia;

    /*!
     * \param frecuenciaB Vector que representa las frecuencias para los distintos
     * niveles de azul. Cada posición equivale a un nivel de azul y el entero almacenado la frecuencia
     * de este nivel.
     */
    vector<int> frecuenciaB;

    /*!
     * \param anchoV Ancho de la ventana.
     */
    int anchoV;

    /*!
     * \param altoV Alto de la ventana.
     */
    int altoV;

    /*!
     * \param escala Atributo que representa cuanto debe reescalarse para poder ser representada
     * correctamente en la ventana.
     */
    float escala;

    /*!
     * \param desplx Atributo que representa cuanto se desplaza en x el histograma en la ventana
     */
    float desplx;

    /*!
     * \param desply Atributo que representa cuanto se desplaza en y el histograma en la ventana
     */
    float desply;

    /*!
     * \brief histograma Imagen que representa el Histograma.
     */
    Imagen histograma;

    /*!
     * \brief construirHistograma Método protegido que permite la representacion de un Histograma como Imagen.
     */
    void construirHistograma();
};

#endif // GRAFICADORHISTOGRAMA_H
