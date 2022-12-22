#include "pixel.h"

Pixel::Pixel()
{

}

Pixel::Pixel(int red, int green, int blue)
{
    r = red;
    g = green;
    b = blue;
}

void Pixel::setPixelRGB(int valor_r, int valor_g, int valor_b)
{
    r=valor_r;
    g=valor_g;
    b=valor_b;
}

void Pixel::setPixelMonocr(int valor)
{
    if(valor == 0)
    {
        r=1;
        g=1;
        b=1;
    }
    else
    {
        r=0;
        g=0;
        b=0;
    }

}

void Pixel::setPixelEscala(int valor)
{
    r=valor;
    g=valor;
    b=valor;
}

int Pixel::getR()
{
    return r;
}

int Pixel::getG()
{
    return g;
}

int Pixel::getB()
{
    return b;
}

int Pixel::getIntensidad()
{
    return (r+g+b)/3;
}

void Pixel::ajusteContraste(vector<int> maximo_minimo_R, vector<int> maximo_minimo_G, vector<int> maximo_minimo_B, int rango)
{
    float R, G, B;
    R = ((float(r)-float(maximo_minimo_R[1]))/(float(maximo_minimo_R[0])-float(maximo_minimo_R[1])));
    r = int(R*rango);
    G = ((float(g)-float(maximo_minimo_G[1]))/(float(maximo_minimo_G[0])-float(maximo_minimo_G[1])));
    g = int(G*rango);
    B = ((float(b)-float(maximo_minimo_B[1]))/(float(maximo_minimo_B[0])-float(maximo_minimo_B[1])));
    b = int(B*rango);

}








