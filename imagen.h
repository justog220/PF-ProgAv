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
