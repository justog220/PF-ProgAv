#include "filtropasaaltos.h"

FiltroPasaAltos::FiltroPasaAltos()
{

}

Imagen FiltroPasaAltos::aplicarFiltro(Imagen &imag)
{
    //    /* Kernel 3x3 utilizado:
    //        * | 0   -1   0 |
    //        * | -1   5  -1 |
    //        * | 0   -1   0 |
    //         */
            Pixel pixAux;

            unsigned int auxR, auxG, auxB;

            int filas = imag.getFilas();
            int columnas = imag.getColumnas();

            Imagen img = imag;

            for(int i = 0; i < filas; i++)
                for(int j = 0; j < columnas; j++)
                {
                    pixAux = imag.getPixel(i, j);
                    auxR = pixAux.getR()*5;
                    auxG = pixAux.getG()*5;
                    auxB = pixAux.getB()*5;

                    if(imag.formaParteDeLaImagen(i, j-1))
                    {
                        pixAux = imag.getPixel(i, j-1);
                        auxR += pixAux.getR()*(-1);
                        auxG += pixAux.getG()*(-1);
                        auxB += pixAux.getB()*(-1);
                    }

                    if(imag.formaParteDeLaImagen(i+1, j))
                    {
                        pixAux = imag.getPixel(i+1, j);
                        auxR += pixAux.getR()*(-1);
                        auxG += pixAux.getG()*(-1);
                        auxB += pixAux.getB()*(-1);
                    }

                    if(imag.formaParteDeLaImagen(i, j+1))
                    {
                        pixAux = imag.getPixel(i, j+1);
                        auxR += pixAux.getR()*(-1);
                        auxG += pixAux.getG()*(-1);
                        auxB += pixAux.getB()*(-1);
                    }

                    if(imag.formaParteDeLaImagen(i-1, j))
                    {
                        pixAux = imag.getPixel(i-1, j);
                        auxR += pixAux.getR()*(-1);
                        auxG += pixAux.getG()*(-1);
                        auxB += pixAux.getB()*(-1);
                    }

                    pixAux.setPixelRGB(auxR, auxG, auxB);

                    img.setPixel(i, j, pixAux);

                }

            return img;
}
