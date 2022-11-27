/*!
 *  \class      VentanaDeGraficacion
 *  \brief      Clase encargada de mostrar por pantalla una imagen y responder a eventos.
 *  \details    Tiene una imagen, la cual es capaz de cargar. Conoce el ancho
 *              y alto de la ventana y la escala utilizada. Se asocia con un
 *              espacio de trabajo para conocer distintas rutas y archivos. Por
 *              otro lado, es capaz de responder ante distintos eventos de mouse y teclado.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 24-11-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QWheelEvent>


#include <iostream>

#include "espaciodetrabajo.h"
#include "imagen.h"
#include "pixel.h"
#include "archivospnm.h"
#include "filtros.h"
#include "graficadorhistograma.h"
#include "algoritmodelpintor.h"
#include "tablalut.h"

class VentanaDeGraficacion: public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    /*!
     * \brief Graficador Constructor del objeto Graficador.
     */
    VentanaDeGraficacion();

    /*!
     * \brief initializeGL Inicializa los recursos necesarios para utilizar OpenGL.
     */
    void initializeGL();

    /*!
     * \brief resizeGL Se modifica el tamaño cuando se modifica el tamaño de la ventana.
     * \param[in] pAncho Nuevo ancho.
     * \param[in] pAlto Nuevo alto.
     */
    void resizeGL(int pAncho, int pAlto);

    /*!
     * \brief paintGL Permite graficar.
     */
    void paintGL();

    /*!
     * \brief graficarImagen Permite la representacion de una Imagen, haciendo uso de la librería
     * OpenGL.
     */
    void graficarImagen();

    /*!
     * \brief graficarImagenPseudocoloreada Permite la representación de una Imagen, haciendo uso de la
     * librería OpenGL, pseudocoloreandola con una tabla LUT.
     * \param[in] opc Tabla LUT que se desea usar.
     */
    void graficarImagenPseudocoloreada(int opc);

    /*!
     * \brief cargarImagen Permite cargar una Imagen al Graficador
     */
    void cargarImagen();

    /*!
     * \brief recuperarImagen  Permite cargar una Imagen a partir de una ruta.
     * \param[in] ruta  String que es la ruta de la cual se recupera una Imagen.
     */
    void recuperarImagen(string ruta);

    /*!
     * \brief setEspacio Permite asociarle un espacio de trabajo.
     * \param[in] esp EspacioDeTrabajo que se asocia.
     */
    void setEspacio(EspacioDeTrabajo &esp);

    /*!
     * \brief setOpciones Método que permite establecer las opciones de
     * directorio y archivo que eligió el usuario.
     * \param[in] opcDir Opcion de Directorio.
     * \param[in] opcArch Opcion de Archivo.
     */
    void setOpciones(int opcDir, int opcArch);

    /*!
     * \brief graficarHistograma Método que permite graficar el Histograma de una Imagen.
     */
    void graficarHistograma();

    /*!
     * \brief set_app Método que permite asociar una QApplication.
     * \param[in] app Puntero a QApplication que se asocia.
     */
    void setApp(QApplication* app);

private:
    /*!
     * \param anchoV Ancho de la ventana.
     */
    int anchoV;

    /*!
     * \param altoV Alto de la ventana.
     */
    int altoV;

    /*!
     * \param escala Escalado de la imagen para su representación
     * en la ventana.
     */
    float escala;

    /*!
     * \param desplx Desplazamiento en x de la imagen.
     */
    float desplx;

    /*!
     * \param desply Desplazamiento en y de la imagen.
     */
    float desply;

    /*!
     * \param imagen Imagen que se grafica.
     */
    Imagen imagen;

    /*!
     * \param espacio EspacioDeTrabajo asociado.
     */
    EspacioDeTrabajo *espacio;

    /*!
     * \param appl QApplication asociada.
     */
    QApplication* appl;

    /*!
     * \param seGraficaPseudocoloreada Bool que indica si la imagen se grafica
     * pseudocoloreada o no.
     */
    bool seGraficaPseudocoloreada = false;

    /*!
     * \param tablaDePseudocoloreo uint que indica la tabla de pseudocoloreado que se utiliza,
     * si no se utilza ninguna toma valor cero.
     */
    uint tablaDePseudocoloreo = 0;

protected:
    /*!
     * \brief keyPressEvent Método heredado que permite captar y responder a un evento de teclado.
     * \param[in] event Evento que es captado.
     */
    void keyPressEvent(QKeyEvent *event) override;

    /*!
     * \brief mousePressEvent Método heredado que permite captar y responde a un evento de mouse.
     * \param[in] event Evento captado.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /*!
     * \param opcDir Directorio elegido por el usuario.
     */
    int opcDir,

    /*!
     * \param opcArch Archivo elegido por el usuario.
     */
    opcArch;
}

;

#endif // GRAFICADOR_H
