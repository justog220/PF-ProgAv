#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QWheelEvent>

#include <iostream>

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

    string getRuta(int opcDir, int opcArch);

    void setOpciones(int dir, int arch);

private:
    int anchoV, altoV;

    float escala;
    float desplx, desply;

    Imagen imagen;

    string raiz="./Imagenes/";

    //string raiz="/home/justo/PF_Garcia/Imagenes/";

    vector<string> carpetas;

    vector<string> carpeta_1;
    vector<string> carpeta_2;
    vector<string> carpeta_3;

    int opcDir;

    int opcArch;
protected:
    void keyPressEvent(QKeyEvent *event) override;

}

;

#endif // GRAFICADOR_H
