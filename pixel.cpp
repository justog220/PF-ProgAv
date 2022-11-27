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
    return getB();
}

void Pixel::aumentarBrillo()
{
    r++;
    g++;
    b++;
}

void Pixel::reducirBrillo()
{
    if (r>0 and g>0 and b>0){
        r--;
        g--;
        b--;
    }

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








