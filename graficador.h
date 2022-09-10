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
    int anchoV, altoV;

    float escala;
    float desplx, desply;

    Imagen imagen;

    EspacioDeTrabajo *espacio;

protected:
    void keyPressEvent(QKeyEvent *event) override;

    int opcDir, opcArch;
}

;

#endif // GRAFICADOR_H
