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

    //nuevo
    void cargarCarpetas();

    void getListaDeArchivos(string ruta);

    string getRuta(int opcDir, int opcArch);

    void setOpciones(int dir, int arch);

    void setEspacio(EspacioDeTrabajo &esp);

private:
    int anchoV, altoV;

    float escala;
    float desplx, desply;

    Imagen imagen;

    EspacioDeTrabajo *espacio;

    string raiz="./Imagenes/";

    //string raiz="/home/justo/PF_Garcia/Imagenes/";

    vector<string> carpetas;

    vector<string> listaDeArchivos; //solo de la carpeta en uso

    int opcDir;

    int opcArch;

protected:
    void keyPressEvent(QKeyEvent *event) override;

}

;

#endif // GRAFICADOR_H
