/*!
 *  \class      Imagen
 *  \brief      Permite la representacion de una imagen a partir de un arreglo de Pixeles
 *  \details    Es un arreglo bidimensional de Pixeles.
 *  \author     Justo Garcia
 *  \date       Fechca de última modificación: 10-09-2022
 *  \pre        Idealmente deben inicializarse solo para formar parte de la representacion
 *              de una imagen.
 *  \bug        Cualquier error encontrado se anota aquí, por ejemplo, un fallo
 *              de acceso a disco, fallas en liberación de memoria,
 *              malfuncionamientos de rutinas que se hayan encontrado, etc.
 *  \warning
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

    void setTamanio();

    void setPixel(int f, int c, Pixel pixelNuevo);

    Pixel getPixel(int f, int c);

    void setFilas(int f);

    void setColumnas(int c);

    void setRango(int valor);

    int getFilas();

    int getColumnas();

    int getRango();

private:
    vector<vector<Pixel>> imag;
    int filas, columnas;
    float rango;

};

#endif // IMAGEN_H
