#include "pixel.h"

Pixel::Pixel()
{

}

void Pixel::setPixelRGB(int valor_r, int valor_g, int valor_b)
{
    r=valor_r;
    g=valor_g;
    b=valor_b;
}

void Pixel::setPixelMonocr(int valor)
{
    r=valor;
    g=valor;
    b=valor;
}

void Pixel::setPixelEscala(int valor)
{
    r=valor;
    g=valor;
    b=valor;
}

float Pixel::getR()
{
    return r;
}

float Pixel::getG()
{
    return g;
}

float Pixel::getB()
{
    return b;
}



