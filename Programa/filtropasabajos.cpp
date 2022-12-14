#include "filtropasabajos.h"

FiltroPasaBajos::FiltroPasaBajos()
{

}

Imagen FiltroPasaBajos::aplicarFiltro(Imagen &imag)
{
    Imagen img = imag;
    float auxR, auxG, auxB;
    Pixel pixAux;
    int columnas = imag.getColumnas();
    int filas = imag.getFilas();


    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
        {
            pixAux = imag.getPixel(i, j);
            auxR = (float)pixAux.getR()/9;
            auxG = (float)pixAux.getG()/9;
            auxB = (float)pixAux.getB()/9;

            if(imag.formaParteDeLaImagen(i-1, j-1))
            {
                pixAux = imag.getPixel(i-1, j-1);
                auxR += (float)pixAux.getR()/9;
                auxG += (float)pixAux.getG()/9;
                auxB += (float)pixAux.getB()/9;
            }

            if(imag.formaParteDeLaImagen(i-1, j))
            {
                pixAux = imag.getPixel(i-1, j);
                auxR += (float)pixAux.getR()/9;
                auxG += (float)pixAux.getG()/9;
                auxB += (float)pixAux.getB()/9;
            }

            if(imag.formaParteDeLaImagen(i-1, j+1))
            {
                pixAux = imag.getPixel(i-1, j+1);
                auxR += (float)pixAux.getR()/9;
                auxG += (float)pixAux.getG()/9;
                auxB += (float)pixAux.getB()/9;
            }

            if(imag.formaParteDeLaImagen(i, j+1))
            {
                pixAux = imag.getPixel(i, j+1);
                auxR += (float)pixAux.getR()/9;
                auxG += (float)pixAux.getG()/9;
                auxB += (float)pixAux.getB()/9;
            }

            if(imag.formaParteDeLaImagen(i+1, j+1))
            {
                pixAux = imag.getPixel(i+1, j+1);
                auxR += (float)pixAux.getR()/9;
                auxG += (float)pixAux.getG()/9;
                auxB += (float)pixAux.getB()/9;
            }

            if(imag.formaParteDeLaImagen(i+1, j))
            {
                pixAux = imag.getPixel(i+1, j);
                auxR += (float)pixAux.getR()/9;
                auxG += (float)pixAux.getG()/9;
                auxB += (float)pixAux.getB()/9;
            }

            if(imag.formaParteDeLaImagen(i+1, j-1))
            {
                pixAux = imag.getPixel(i+1, j-1);
                auxR += (float)pixAux.getR()/9;
                auxG += (float)pixAux.getG()/9;
                auxB += (float)pixAux.getB()/9;
            }


            if(imag.formaParteDeLaImagen(i, j-1))
            {
                pixAux = imag.getPixel(i, j-1);
                auxR += (float)pixAux.getR()/9;
                auxG += (float)pixAux.getG()/9;
                auxB += (float)pixAux.getB()/9;
            }

            pixAux.setPixelRGB((int)auxR, (int)auxG, (int)auxB);
            img.setPixel(i, j, pixAux);
        }

    return img;
}
