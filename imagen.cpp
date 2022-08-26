#include "imagen.h"

Imagen::Imagen()
{

}

void Imagen::setTamanio()
{
    imag.resize(filas);
    for(int i=0; i<filas; i++)
    {
        imag[i].resize(columnas);
    }
}

void Imagen::setPixel(int f, int c, Pixel pixelNuevo)
{
    imag[f][c]=pixelNuevo;
}

Pixel Imagen::getPixel(int f, int c)
{
    return imag[f][c];
}

void Imagen::setFilas(int f)
{
    filas=f;
}

void Imagen::setColumnas(int c)
{
    columnas=c;
}

void Imagen::setRango(int valor)
{
    rango = valor;
}

int Imagen::getFilas()
{
    return filas;
}

int Imagen::getColumnas()
{
    return columnas;
}

int Imagen::getRango()
{
    return rango;
}


