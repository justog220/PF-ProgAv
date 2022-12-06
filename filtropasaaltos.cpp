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
            Pixel pix_aux;

            unsigned int auxR, auxG, auxB;

            int filas = imag.getFilas();
            int columnas = imag.getColumnas();

            Imagen img = imag;

            for(int i = 0; i < filas; i++)
                for(int j = 0; j < columnas; j++)
                {
                    pix_aux = imag.getPixel(i, j);
                    auxR = pix_aux.getR()*5;
                    auxG = pix_aux.getG()*5;
                    auxB = pix_aux.getB()*5;

                    if(imag.formaParteDeLaImagen(i, j-1))
                    {
                        pix_aux = imag.getPixel(i, j-1);
                        auxR += pix_aux.getR()*(-1);
                        auxG += pix_aux.getG()*(-1);
                        auxB += pix_aux.getB()*(-1);
                    }

                    if(imag.formaParteDeLaImagen(i+1, j))
                    {
                        pix_aux = imag.getPixel(i+1, j);
                        auxR += pix_aux.getR()*(-1);
                        auxG += pix_aux.getG()*(-1);
                        auxB += pix_aux.getB()*(-1);
                    }

                    if(imag.formaParteDeLaImagen(i, j+1))
                    {
                        pix_aux = imag.getPixel(i, j+1);
                        auxR += pix_aux.getR()*(-1);
                        auxG += pix_aux.getG()*(-1);
                        auxB += pix_aux.getB()*(-1);
                    }

                    if(imag.formaParteDeLaImagen(i-1, j))
                    {
                        pix_aux = imag.getPixel(i-1, j);
                        auxR += pix_aux.getR()*(-1);
                        auxG += pix_aux.getG()*(-1);
                        auxB += pix_aux.getB()*(-1);
                    }

                    pix_aux.setPixelRGB(auxR, auxG, auxB);

                    img.setPixel(i, j, pix_aux);

                }

            return img;
}
