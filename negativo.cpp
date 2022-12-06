#include "negativo.h"

Negativo::Negativo()
{

}

Imagen Negativo::aplicarFiltro(Imagen &imag)
{
    Pixel pix_aux;

    Imagen img = imag;
    unsigned int difR, difG, difB;
    for(int i=1; i<img.getFilas()-1; i++)
        for(int j=1; j<img.getColumnas()-1; j++)
        {
            pix_aux = img.getPixel(i, j);

            difR = img.getRango() - pix_aux.getR();

            difG = img.getRango() - pix_aux.getG();

            difB = img.getRango() - pix_aux.getB();

            pix_aux.setPixelRGB(difR, difG, difB);

            img.setPixel(i, j, pix_aux);
        }

    return img;
}
