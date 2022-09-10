/*!
 *  \class      Imagen
 *  \brief      Permite la representacion de una imagen a partir de un arreglo de Pixeles
 *  \details    Es un arreglo bidimensional de Pixeles. Conoce sus pixeles, su tamaño y el
 *              rango de sus pixeles. Puede cambiar su tamaño o sus pixeles y puede informar
 *              su tamaño y un pixel en espeifico. *
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug        Cualquier error encontrado se anota aquí, por ejemplo, un fallo
 *              de acceso a disco, fallas en liberación de memoria,
 *              malfuncionamientos de rutinas que se hayan encontrado, etc.
 *  \warning    Debe evitarse realizar muchas instancias de ella porque se requiere de mucha memoria
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
