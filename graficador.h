/*!
 *  \class      Graficador
 *  \brief      Clase encargada de mostrar por pantalla una imagen y responder a eventos.
 *  \details    Tiene una imagen, la cual es capaz de cargar. Conoce el ancho
 *              y alto de la ventana y la escala utilizada. Se asocia con un
 *              espacio de trabajo para conocer distintas rutas y archivos. Por
 *              otro lado, es capaz de responder ante distintos eventos de mouse y teclado.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug        La ventana no se abre con el tamaño de la imagen.
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

class Graficador: public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    Graficador();

    void initializeGL();

    void resizeGL(int pAncho, int pAlto);

    void paintGL();

    void graficarImagen();

    void cargarImagen();

    void setEspacio(EspacioDeTrabajo &esp);

    void setOpciones(int opcDir, int opcArch);

private:
    int anchoV;

    int altoV;

    float escala;
    float desplx;
    float desply;

    Imagen imagen;

    EspacioDeTrabajo *espacio;

protected:
    /*!
     * \brief keyPressEvent
     * \param event
     * Lista de eventos:
     *    - Eventos de ratón:
     *         -# Evento de movimiento de ratón.
     *         -# Evento de clic con ratón\n
     *            Más información relacionada al evento clic.
     *         -# Evento de doble clic con ratón.
     *    - Eventos de teclado:
     *         1. Presionar una tecla.
     *         2. Dejar de presionar una tecla.
     *
  */

    void keyPressEvent(QKeyEvent *event) override;

    int opcDir, opcArch;
}

;

#endif // GRAFICADOR_H
