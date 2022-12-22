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

void Imagen::setIdentificador(string id)
{
    identificador = id;
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

string Imagen::getIdentificador()
{
    return identificador;
}

bool Imagen::formaParteDeLaImagen(int f, int c)
{
    return (f >= 0 and f < filas and c >= 0 and c < columnas);
}

bool Imagen::elPixelEsEsquina(int f, int c)
{
    bool esEsquina = false;

    if (f == 0 and c == 0)
    {
        esEsquina = true;
    }
    else if (f == 0 and c == columnas-1)
    {
        esEsquina = true;
    }
    else if (f == filas-1 and c == 0)
    {
        esEsquina = true;
    }
    else if (f == filas-1 and c == columnas-1)
    {
        esEsquina = true;
    }

    return esEsquina;
}

void Imagen::borrarImagen()
{
    imag.clear();
}

bool Imagen::esDeIntensidades()
{
    return (identificador == "P1" or identificador == "P2" or identificador == "P4" or identificador == "P5");
}

int Imagen::getNroPixeles()
{
    return filas*columnas;
}

string Imagen::getInformacion()
{
    return informacion;
}

void Imagen::setInformacion(string value)
{
    informacion = value;
}


