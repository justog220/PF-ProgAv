#include "filtromediana.h"

FiltroMediana::FiltroMediana()
{

}

Imagen FiltroMediana::aplicarFiltro(Imagen &imag)
{
    Imagen img  = imag;
    unsigned int auxR, auxG, auxB;
    int medio;

    vector<int> auxCalculoMedianaR, auxCalculoMedianaG, auxCalculoMedianaB;

    Pixel pix_aux;

    int columnas = imag.getColumnas(), filas= imag.getFilas();

    for(int i=0; i<filas; i++)
        for(int j=0; j<columnas; j++)
        {
            if(imag.formaParteDeLaImagen(i, j))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i, j).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i, j).getG());
                auxCalculoMedianaG.push_back(imag.getPixel(i, j).getB());
            }

            if(imag.formaParteDeLaImagen(i-1, j))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i-1, j).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i-1, j).getG());
                auxCalculoMedianaB.push_back(imag.getPixel(i-1, j).getB());
            }

            if(imag.formaParteDeLaImagen(i-1, j+1))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i-1, j+1).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i-1, j+1).getG());
                auxCalculoMedianaB.push_back(imag.getPixel(i-1, j+1).getB());
            }

            if(imag.formaParteDeLaImagen(i, j+1))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i, j+1).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i, j+1).getG());
                auxCalculoMedianaB.push_back(imag.getPixel(i, j+1).getB());
            }

            if(imag.formaParteDeLaImagen(i+1, j+1))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i+1, j+1).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i+1, j+1).getG());
                auxCalculoMedianaB.push_back(imag.getPixel(i+1, j+1).getB());
            }

            if(imag.formaParteDeLaImagen(i+1, j))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i+1, j).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i+1, j).getG());
                auxCalculoMedianaB.push_back(imag.getPixel(i+1, j).getB());
            }

            if(imag.formaParteDeLaImagen(i+1, j-1))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i+1, j-1).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i+1, j-1).getG());
                auxCalculoMedianaB.push_back(imag.getPixel(i+1, j-1).getB());
            }

            if(imag.formaParteDeLaImagen(i, j-1))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i, j-1).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i, j-1).getG());
                auxCalculoMedianaB.push_back(imag.getPixel(i, j-1).getB());
            }

            if(imag.formaParteDeLaImagen(i-1, j-1))
            {
                auxCalculoMedianaR.push_back(imag.getPixel(i-1, j-1).getR());
                auxCalculoMedianaG.push_back(imag.getPixel(i-1, j-1).getG());
                auxCalculoMedianaB.push_back(imag.getPixel(i-1, j-1).getB());
            }

            sort(auxCalculoMedianaR.begin(), auxCalculoMedianaR.end());
            sort(auxCalculoMedianaG.begin(), auxCalculoMedianaG.end());
            sort(auxCalculoMedianaB.begin(), auxCalculoMedianaB.end());

            if(auxCalculoMedianaR.size() % 2 != 0)
            {
                medio = (auxCalculoMedianaR.size()/2) + 1;
                auxR = auxCalculoMedianaR[medio];
                auxG = auxCalculoMedianaG[medio];
                auxB = auxCalculoMedianaB[medio];
            }
            else
            {
                medio = auxCalculoMedianaR.size()/2;
                auxR = (auxCalculoMedianaR[medio] + auxCalculoMedianaR[medio+1]) / 2;
                auxG = (auxCalculoMedianaG[medio] + auxCalculoMedianaG[medio+1]) / 2;
                auxB = (auxCalculoMedianaB[medio] + auxCalculoMedianaB[medio+1]) / 2;
            }


            pix_aux.setPixelRGB(auxR, auxG, auxB);

            img.setPixel(i, j, pix_aux);

            auxCalculoMedianaR.clear();
            auxCalculoMedianaG.clear();
            auxCalculoMedianaB.clear();
        }

    return img;
}
