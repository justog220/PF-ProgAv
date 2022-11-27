#include "filtros.h"

Filtros::Filtros()
{

}

Imagen Filtros::aplicaFiltroPasaBajos(Imagen &pImg)
{
    Imagen img = pImg;
    unsigned int auxR, auxG, auxB;
    Pixel pixAux;
    int columnas = pImg.getColumnas();
    int filas = pImg.getFilas();

    //Se modifican las esquinas
    //Para imag[0][0]
    auxR = (pImg.getPixel(0,1).getR()/9)+(pImg.getPixel(1,1).getR()/9)+(pImg.getPixel(1,0).getR()/9)+(pImg.getPixel(0,0).getR()/9);
    auxG = (pImg.getPixel(0,1).getG()/9)+(pImg.getPixel(1,1).getG()/9)+(pImg.getPixel(1,0).getG()/9)+(pImg.getPixel(0,0).getG()/9);
    auxB = (pImg.getPixel(0,1).getB()/9)+(pImg.getPixel(1,1).getB()/9)+(pImg.getPixel(1,0).getB()/9)+(pImg.getPixel(0,0).getB()/9);
    pixAux.setPixelRGB(auxR, auxG, auxB);
    img.setPixel(0, 0, pixAux);


    //Para imag [filas][0]
    auxR = (pImg.getPixel(filas-2, 0).getR()/9)+(pImg.getPixel(filas-2, 1).getR()/9)+(pImg.getPixel(filas-1, 1).getR()/9)+(pImg.getPixel(filas-1, 0).getR()/9);
    auxG = (pImg.getPixel(filas-2, 0).getG()/9)+(pImg.getPixel(filas-2, 1).getG()/9)+(pImg.getPixel(filas-1, 1).getG()/9)+(pImg.getPixel(filas-1, 0).getG()/9);
    auxB = (pImg.getPixel(filas-2, 0).getB()/9)+(pImg.getPixel(filas-2, 1).getB()/9)+(pImg.getPixel(filas-1, 1).getB()/9)+(pImg.getPixel(filas-1, 0).getB()/9);
    pixAux.setPixelRGB(auxR, auxG, auxB);
    img.setPixel(pImg.getFilas()-1, 0, pixAux);

//    //Para imag[0][columnas]

    auxR = (pImg.getPixel(0,columnas-2).getR()/9)+(pImg.getPixel(1,columnas-2).getR()/9)+(pImg.getPixel(1,columnas-1).getR()/9)+(pImg.getPixel(0,columnas-1).getR()/9);
    auxG = (pImg.getPixel(0,columnas-2).getG()/9)+(pImg.getPixel(1,columnas-2).getG()/9)+(pImg.getPixel(1,columnas-1).getG()/9)+(pImg.getPixel(0,columnas-1).getG()/9);
    auxB = (pImg.getPixel(0,columnas-2).getB()/9)+(pImg.getPixel(1,columnas-2).getB()/9)+(pImg.getPixel(1,columnas-1).getB()/9)+(pImg.getPixel(0,columnas-1).getB()/9);
    pixAux.setPixelRGB(auxR, auxG, auxB);
    img.setPixel(0, pImg.getColumnas()-1, pixAux);

    //Para imag[filas][columnas]
    auxR = (pImg.getPixel(filas-1, columnas-2).getR()/9)+(pImg.getPixel(filas-2, columnas-2).getR()/9)+(pImg.getPixel(filas-2, columnas-1).getR()/9)+(pImg.getPixel(filas-1, columnas-1).getR()/9);
    auxG = (pImg.getPixel(filas-1, columnas-2).getG()/9)+(pImg.getPixel(filas-2, columnas-2).getG()/9)+(pImg.getPixel(filas-2, columnas-1).getG()/9)+(pImg.getPixel(filas-1, columnas-1).getG()/9);
    auxB = (pImg.getPixel(filas-1, columnas-2).getB()/9)+(pImg.getPixel(filas-2, columnas-2).getB()/9)+(pImg.getPixel(filas-2, columnas-1).getB()/9)+(pImg.getPixel(filas-1, columnas-1).getB()/9);
    pixAux.setPixelRGB(auxR, auxG, auxB);
    img.setPixel(filas-1, columnas-1, pixAux);

    //Los bordes de la imagen
    for(int i=1; i<filas-1; i++)
    {
        auxR = (pImg.getPixel(i-1, 0).getR()/9)+(pImg.getPixel(i-1, 1).getR()/9)+(pImg.getPixel(i, 1).getR()/9)+(pImg.getPixel(i+1, 1).getR()/9)+(pImg.getPixel(i+1, 0).getR()/9)+(pImg.getPixel(i, 0).getR()/9);
        auxG = (pImg.getPixel(i-1, 0).getG()/9)+(pImg.getPixel(i-1, 1).getG()/9)+(pImg.getPixel(i, 1).getG()/9)+(pImg.getPixel(i+1, 1).getG()/9)+(pImg.getPixel(i+1, 0).getG()/9)+(pImg.getPixel(i, 0).getG()/9);
        auxB = (pImg.getPixel(i-1, 0).getB()/9)+(pImg.getPixel(i-1, 1).getB()/9)+(pImg.getPixel(i, 1).getB()/9)+(pImg.getPixel(i+1, 1).getB()/9)+(pImg.getPixel(i+1, 0).getB()/9)+(pImg.getPixel(i, 0).getB()/9);
        pixAux.setPixelRGB(auxR, auxG, auxB);
        img.setPixel(i, 0, pixAux);
    }

    for(int i=1; i<filas-1; i++)
    {
        auxR = (pImg.getPixel(i-1, columnas-1).getR()/9)+(pImg.getPixel(i-1, columnas-2).getR()/9)+(pImg.getPixel(i, columnas-2).getR()/9)+(pImg.getPixel(i+1, columnas-2).getR()/9)+(pImg.getPixel(i+1, columnas-1).getR()/9)+(pImg.getPixel(i, columnas-1).getR()/9);
        auxG = (pImg.getPixel(i-1, columnas-1).getG()/9)+(pImg.getPixel(i-1, columnas-2).getG()/9)+(pImg.getPixel(i, columnas-2).getG()/9)+(pImg.getPixel(i+1, columnas-2).getG()/9)+(pImg.getPixel(i+1, columnas-1).getG()/9)+(pImg.getPixel(i, columnas-1).getG()/9);
        auxB = (pImg.getPixel(i-1, columnas-1).getB()/9)+(pImg.getPixel(i-1, columnas-2).getB()/9)+(pImg.getPixel(i, columnas-2).getB()/9)+(pImg.getPixel(i+1, columnas-2).getB()/9)+(pImg.getPixel(i+1, columnas-1).getB()/9)+(pImg.getPixel(i, columnas-1).getB()/9);
        pixAux.setPixelRGB(auxR, auxG, auxB);
        img.setPixel(i, columnas-1, pixAux);
    }

    for(int i=1; i<columnas-1; i++)
    {
        auxR = (pImg.getPixel(0, i-1).getR()/9)+(pImg.getPixel(1, i-1).getR()/9)+(pImg.getPixel(1, i).getR()/9)+(pImg.getPixel(1, i+1).getR()/9)+(pImg.getPixel(0, i+1).getR()/9)+(pImg.getPixel(0, i).getR()/9);
        auxG = (pImg.getPixel(0, i-1).getG()/9)+(pImg.getPixel(1, i-1).getG()/9)+(pImg.getPixel(1, i).getG()/9)+(pImg.getPixel(1, i+1).getG()/9)+(pImg.getPixel(0, i+1).getG()/9)+(pImg.getPixel(0, i).getG()/9);
        auxB = (pImg.getPixel(0, i-1).getB()/9)+(pImg.getPixel(1, i-1).getB()/9)+(pImg.getPixel(1, i).getB()/9)+(pImg.getPixel(1, i+1).getB()/9)+(pImg.getPixel(0, i+1).getB()/9)+(pImg.getPixel(0, i).getB()/9);
        pixAux.setPixelRGB(auxR, auxG, auxB);
        img.setPixel(0, i, pixAux);
    }

    for(int i=1; i<columnas-1; i++)
    {
        auxR = (pImg.getPixel(filas-1, i-1).getR()/9)+(pImg.getPixel(filas-2, i-1).getR()/9)+(pImg.getPixel(filas-2, i).getR()/9)+(pImg.getPixel(filas-2, i+1).getR()/9)+(pImg.getPixel(filas-1, i+1).getR()/9)+(pImg.getPixel(filas-1, i).getR()/9);
        auxG = (pImg.getPixel(filas-1, i-1).getG()/9)+(pImg.getPixel(filas-2, i-1).getG()/9)+(pImg.getPixel(filas-2, i).getG()/9)+(pImg.getPixel(filas-2, i+1).getG()/9)+(pImg.getPixel(filas-1, i+1).getG()/9)+(pImg.getPixel(filas-1, i).getG()/9);
        auxB = (pImg.getPixel(filas-1, i-1).getB()/9)+(pImg.getPixel(filas-2, i-1).getB()/9)+(pImg.getPixel(filas-2, i).getB()/9)+(pImg.getPixel(filas-2, i+1).getB()/9)+(pImg.getPixel(filas-1, i+1).getB()/9)+(pImg.getPixel(filas-1, i).getB()/9);
        pixAux.setPixelRGB(auxR, auxG, auxB);
        img.setPixel(filas-1, i, pixAux);
    }

    for(int i=1; i<filas-1; i++)
        for(int j=1; j<columnas-1; j++)
        {
            auxR = (pImg.getPixel(i-1, j-1).getR()+pImg.getPixel(i-1, j).getR()+pImg.getPixel(i-1, j+1).getR()+pImg.getPixel(i, j+1).getR()+pImg.getPixel(i+1, j+1).getR()+pImg.getPixel(i+1, j).getR()+pImg.getPixel(i+1, j-1).getR()+pImg.getPixel(i, j-1).getR()+pImg.getPixel(i, j).getR())/9;
            auxG = (pImg.getPixel(i-1, j-1).getG()+pImg.getPixel(i-1, j).getG()+pImg.getPixel(i-1, j+1).getG()+pImg.getPixel(i, j+1).getG()+pImg.getPixel(i+1, j+1).getG()+pImg.getPixel(i+1, j).getG()+pImg.getPixel(i+1, j-1).getG()+pImg.getPixel(i, j-1).getG()+pImg.getPixel(i, j).getG())/9;
            auxB = (pImg.getPixel(i-1, j-1).getB()+pImg.getPixel(i-1, j).getB()+pImg.getPixel(i-1, j+1).getB()+pImg.getPixel(i, j+1).getB()+pImg.getPixel(i+1, j+1).getB()+pImg.getPixel(i+1, j).getB()+pImg.getPixel(i+1, j-1).getB()+pImg.getPixel(i, j-1).getB()+pImg.getPixel(i, j).getB())/9;
            pixAux.setPixelRGB(auxR, auxG, auxB);
            img.setPixel(i, j, pixAux);
        }

    return img;
}

Imagen Filtros::aplicaFiltroPasaAltos(Imagen &pImg)
{
//    /* Kernel 3x3 utilizado:
//        * | 0   -1   0 |
//        * | -1   5  -1 |
//        * | 0   -1   0 |
//         */
        Pixel pix_aux;

        unsigned int auxR, auxG, auxB;

        int filas = pImg.getFilas();
        int columnas = pImg.getColumnas();

        Imagen img = pImg;

//        img_aux.setFilas(filas);
//        img_aux.setColumnas(columnas);
//        img_aux.setTamanio();
//        img_aux.setRango(img->getRango());
//        img_aux.setIdentificador(img->getIdentificador());

        //Se modifican las esquinas
        //Para imag[0][0]
        auxR = (pImg.getPixel(0,1).getR()*(-1))+(pImg.getPixel(1,1).getR()*0)+(pImg.getPixel(1,0).getR()*(-1))+(pImg.getPixel(0,0).getR()*5);
        auxG = (pImg.getPixel(0,1).getG()*(-1))+(pImg.getPixel(1,1).getG()*0)+(pImg.getPixel(1,0).getG()*(-1))+(pImg.getPixel(0,0).getG()*5);
        auxB = (pImg.getPixel(0,1).getB()*(-1))+(pImg.getPixel(1,1).getB()*0)+(pImg.getPixel(1,0).getB()*(-1))+(pImg.getPixel(0,0).getB()*5);
        pix_aux.setPixelRGB(auxR, auxG, auxB);
        img.setPixel(0, 0, pix_aux);

        //Para imag [filas][0]
        auxR = (pImg.getPixel(filas-2,0).getR()*(-1))+(pImg.getPixel(filas-2, 1).getR()*0)+(pImg.getPixel(filas-1, 1).getR()*(-1))+(pImg.getPixel(filas-1, 0).getR()*5);
        auxG = (pImg.getPixel(filas-2,0).getG()*(-1))+(pImg.getPixel(filas-2, 1).getG()*0)+(pImg.getPixel(filas-1, 1).getG()*(-1))+(pImg.getPixel(filas-1, 0).getG()*5);
        auxB = (pImg.getPixel(filas-2,0).getB()*(-1))+(pImg.getPixel(filas-2, 1).getB()*0)+(pImg.getPixel(filas-1, 1).getB()*(-1))+(pImg.getPixel(filas-1, 0).getB()*5);
        pix_aux.setPixelRGB(auxR, auxG, auxB);
        img.setPixel(filas-1, 0, pix_aux);

        //Para imag[0][columnas]
        auxR = (pImg.getPixel(0, columnas-2).getR()*(-1))+(pImg.getPixel(1, columnas-2).getR()*0)+(pImg.getPixel(1, columnas-1).getR()*(-1))+(pImg.getPixel(0, columnas-1).getR()*5);
        auxG = (pImg.getPixel(0, columnas-2).getG()*(-1))+(pImg.getPixel(1, columnas-2).getG()*0)+(pImg.getPixel(1, columnas-1).getG()*(-1))+(pImg.getPixel(0, columnas-1).getG()*5);
        auxB = (pImg.getPixel(0, columnas-2).getB()*(-1))+(pImg.getPixel(1, columnas-2).getB()*0)+(pImg.getPixel(1, columnas-1).getB()*(-1))+(pImg.getPixel(0, columnas-1).getB()*5);
        pix_aux.setPixelRGB(auxR, auxG, auxB);
        img.setPixel(0, columnas-1, pix_aux);

        //Para imag[filas][columnas]
        auxR = (pImg.getPixel(filas-1, columnas-2).getR()*(-1))+(pImg.getPixel(filas-2, columnas-2).getR()*0)+(pImg.getPixel(filas-2, columnas-1).getR()*(-1))+(pImg.getPixel(filas-1, columnas-1).getR()*5);
        auxG = (pImg.getPixel(filas-1, columnas-2).getG()*(-1))+(pImg.getPixel(filas-2, columnas-2).getG()*0)+(pImg.getPixel(filas-2, columnas-1).getG()*(-1))+(pImg.getPixel(filas-1, columnas-1).getG()*5);
        auxB = (pImg.getPixel(filas-1, columnas-2).getB()*(-1))+(pImg.getPixel(filas-2, columnas-2).getB()*0)+(pImg.getPixel(filas-2, columnas-1).getB()*(-1))+(pImg.getPixel(filas-1, columnas-1).getB()*5);
        pix_aux.setPixelRGB(auxR, auxG, auxB);
        img.setPixel(filas-1, columnas-1, pix_aux);

        //Los bordes de la imagen
        for(int i=1; i<filas-2; i++)
        {
            auxR = (pImg.getPixel(i-1, 0).getR()*(-1))+(pImg.getPixel(i-1, 1).getR()*0)+(pImg.getPixel(i, 1).getR()*(-1))+(pImg.getPixel(i+1, 1).getR()*0)+(pImg.getPixel(i+1, 0).getR()*(-1))+(pImg.getPixel(i, 0).getR()*5);
            auxG = (pImg.getPixel(i-1, 0).getG()*(-1))+(pImg.getPixel(i-1, 1).getG()*0)+(pImg.getPixel(i, 1).getG()*(-1))+(pImg.getPixel(i+1, 1).getG()*0)+(pImg.getPixel(i+1, 0).getG()*(-1))+(pImg.getPixel(i, 0).getG()*5);
            auxB = (pImg.getPixel(i-1, 0).getB()*(-1))+(pImg.getPixel(i-1, 1).getB()*0)+(pImg.getPixel(i, 1).getB()*(-1))+(pImg.getPixel(i+1, 1).getB()*0)+(pImg.getPixel(i+1, 0).getB()*(-1))+(pImg.getPixel(i, 0).getB()*5);
            pix_aux.setPixelRGB(auxR, auxG, auxB);
            img.setPixel(i, 0, pix_aux);
        }

        for(int i=1; i<filas-2; i++)
        {
            auxR = (pImg.getPixel(i-1, columnas-1).getR()*(-1))+(pImg.getPixel(i, columnas-2).getR()*(-1))+(pImg.getPixel(i+1, columnas-1).getR()*(-1))+(pImg.getPixel(i, columnas-1).getR()*5);
            auxG = (pImg.getPixel(i-1, columnas-1).getG()*(-1))+(pImg.getPixel(i, columnas-2).getG()*(-1))+(pImg.getPixel(i+1, columnas-1).getG()*(-1))+(pImg.getPixel(i, columnas-1).getG()*5);
            auxB = (pImg.getPixel(i-1, columnas-1).getB()*(-1))+(pImg.getPixel(i, columnas-2).getB()*(-1))+(pImg.getPixel(i+1, columnas-1).getB()*(-1))+(pImg.getPixel(i, columnas-1).getB()*5);
            pix_aux.setPixelRGB(auxR, auxG, auxB);
            img.setPixel(i, columnas-1, pix_aux);
        }

        for(int i=1; i<columnas-2; i++)
        {
            auxR = (pImg.getPixel(0, i-1).getR()*(-1))+(pImg.getPixel(1, i).getR()*(-1))+(pImg.getPixel(0, i+1).getR()*(-1))+(pImg.getPixel(0, i).getR()*5);
            auxG = (pImg.getPixel(0, i-1).getG()*(-1))+(pImg.getPixel(1, i).getG()*(-1))+(pImg.getPixel(0, i+1).getG()*(-1))+(pImg.getPixel(0, i).getG()*5);
            auxB = (pImg.getPixel(0, i-1).getB()*(-1))+(pImg.getPixel(1, i).getB()*(-1))+(pImg.getPixel(0, i+1).getB()*(-1))+(pImg.getPixel(0, i).getB()*5);
            pix_aux.setPixelRGB(auxR, auxG, auxB);
            img.setPixel(0, i, pix_aux);
        }

        for(int i=1; i<columnas-2; i++)
        {
            auxR = (pImg.getPixel(filas-1, i-1).getR()*(-1))+(pImg.getPixel(filas-2, i).getR()*(-1))+(pImg.getPixel(filas-1, i+1).getR()*(-1))+(pImg.getPixel(filas-1, i).getR()*5);
            auxG = (pImg.getPixel(filas-1, i-1).getG()*(-1))+(pImg.getPixel(filas-2, i).getG()*(-1))+(pImg.getPixel(filas-1, i+1).getG()*(-1))+(pImg.getPixel(filas-1, i).getG()*5);
            auxB = (pImg.getPixel(filas-1, i-1).getB()*(-1))+(pImg.getPixel(filas-2, i).getB()*(-1))+(pImg.getPixel(filas-1, i+1).getB()*(-1))+(pImg.getPixel(filas-1, i).getB()*5);
            pix_aux.setPixelRGB(auxR, auxG, auxB);
            img.setPixel(filas-1, i, pix_aux);
        }

        for(int i=1; i<filas-1; i++)
            for(int j=1; j<columnas-1; j++)
            {
                auxR = (pImg.getPixel(i-1, j).getR()*(-1))+(pImg.getPixel(i, j+1).getR()*(-1))+(pImg.getPixel(i+1, j).getR()*(-1))+(pImg.getPixel(i, j-1).getR()*(-1))+(pImg.getPixel(i, j).getR()*5);
                auxG = (pImg.getPixel(i-1, j).getG()*(-1))+(pImg.getPixel(i, j+1).getG()*(-1))+(pImg.getPixel(i+1, j).getG()*(-1))+(pImg.getPixel(i, j-1).getG()*(-1))+(pImg.getPixel(i, j).getG()*5);
                auxB = (pImg.getPixel(i-1, j).getB()*(-1))+(pImg.getPixel(i, j+1).getB()*(-1))+(pImg.getPixel(i+1, j).getB()*(-1))+(pImg.getPixel(i, j-1).getB()*(-1))+(pImg.getPixel(i, j).getB()*5);
                pix_aux.setPixelRGB(auxR, auxG, auxB);
                img.setPixel(i, j, pix_aux);
            }

        return img;
}

Imagen Filtros::aplicaNegativo(Imagen &pImg)
{
        Pixel pix_aux;

        Imagen img = pImg;
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

void Filtros::ajusteContraste(Imagen *img)
{
        ProcesadorEstadistico proce;
        Pixel pix_aux;

        vector<int> maximo_minimo_R = proce.hallarMaximoMinimoR(*img);
        vector<int> maximo_minimo_G = proce.hallarMaximoMinimoG(*img);
        vector<int> maximo_minimo_B = proce.hallarMaximoMinimoB(*img);

        for(int i=0; i<img->getFilas(); i++)
            for(int j=0; j<img->getColumnas(); j++)
            {
                pix_aux = img->getPixel(i,j);
                pix_aux.ajusteContraste(maximo_minimo_R, maximo_minimo_G, maximo_minimo_B, img->getRango());
                img->setPixel(i, j, pix_aux);

            }
}

void Filtros::reducirBrillo(Imagen *img)
{
    Pixel pix_aux;

    for(int i=0; i<img->getFilas(); i++)
        for(int j=0; j<img->getColumnas(); j++)
        {
            pix_aux = img->getPixel(i, j);
            pix_aux.reducirBrillo();
            img->setPixel(i, j, pix_aux);
        }
}

void Filtros::aplicaFiltroMediana(Imagen *img)
{
    Imagen* imag = img;
    aplicaFiltroMedianaEsquinas(imag);

    aplicaFiltroMedianaBordes(imag);

    aplicaFiltroMedianaCentro(imag);

    img = imag;

}

void Filtros::aplicaFiltroMedianaEsquinas(Imagen *imag)
{
    unsigned int auxR, auxG, auxB;

    vector<int> auxCalculoMediana;

    Pixel pix_aux;

    int columnas = imag->getColumnas(), filas= imag->getFilas();
    //Img[0][0]
    auxCalculoMediana.push_back(imag->getPixel(0, 0).getR());
    auxCalculoMediana.push_back(imag->getPixel(0, 1).getR());
    auxCalculoMediana.push_back(imag->getPixel(1, 1).getR());
    auxCalculoMediana.push_back(imag->getPixel(1, 0).getR());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxR = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    auxCalculoMediana.push_back(imag->getPixel(0, 0).getG());
    auxCalculoMediana.push_back(imag->getPixel(0, 1).getG());
    auxCalculoMediana.push_back(imag->getPixel(1, 1).getG());
    auxCalculoMediana.push_back(imag->getPixel(1, 0).getG());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxG = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    auxCalculoMediana.push_back(imag->getPixel(0, 0).getB());
    auxCalculoMediana.push_back(imag->getPixel(0, 1).getB());
    auxCalculoMediana.push_back(imag->getPixel(1, 1).getB());
    auxCalculoMediana.push_back(imag->getPixel(1, 0).getB());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxB = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    pix_aux.setPixelRGB(auxR, auxG, auxB);

    imag->setPixel(0, 0, pix_aux);

    //Img[0][columnas-1]
    auxCalculoMediana.push_back(imag->getPixel(0, columnas-1).getR());
    auxCalculoMediana.push_back(imag->getPixel(0, columnas-2).getR());
    auxCalculoMediana.push_back(imag->getPixel(1, columnas-2).getR());
    auxCalculoMediana.push_back(imag->getPixel(1, columnas-1).getR());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxR = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    auxCalculoMediana.push_back(imag->getPixel(0, columnas-1).getG());
    auxCalculoMediana.push_back(imag->getPixel(0, columnas-2).getG());
    auxCalculoMediana.push_back(imag->getPixel(1, columnas-2).getG());
    auxCalculoMediana.push_back(imag->getPixel(1, columnas-1).getG());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxG = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    auxCalculoMediana.push_back(imag->getPixel(0, columnas-1).getB());
    auxCalculoMediana.push_back(imag->getPixel(0, columnas-2).getB());
    auxCalculoMediana.push_back(imag->getPixel(1, columnas-2).getB());
    auxCalculoMediana.push_back(imag->getPixel(1, columnas-1).getB());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxB = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    pix_aux.setPixelRGB(auxR, auxG, auxB);

    imag->setPixel(0, imag->getColumnas()-1, pix_aux);

    //Img[filas-1][0]
    auxCalculoMediana.push_back(imag->getPixel(filas-1, 0).getR());
    auxCalculoMediana.push_back(imag->getPixel(filas-1, 1).getR());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, 1).getR());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, 0).getR());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxR = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    auxCalculoMediana.push_back(imag->getPixel(filas-1, 0).getG());
    auxCalculoMediana.push_back(imag->getPixel(filas-1, 1).getG());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, 1).getG());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, 0).getG());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxG = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    auxCalculoMediana.push_back(imag->getPixel(filas-1, 0).getB());
    auxCalculoMediana.push_back(imag->getPixel(filas-1, 1).getB());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, 1).getB());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, 0).getB());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxB = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    pix_aux.setPixelRGB(auxR, auxG, auxB);

    imag->setPixel(0, imag->getColumnas()-1, pix_aux);

    //Img[filas-1][columnas-1]
    auxCalculoMediana.push_back(imag->getPixel(filas-1, columnas-1).getR());
    auxCalculoMediana.push_back(imag->getPixel(filas-1, columnas-2).getR());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, columnas-2).getR());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, columnas-1).getR());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxR = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    auxCalculoMediana.push_back(imag->getPixel(filas-1, columnas-1).getG());
    auxCalculoMediana.push_back(imag->getPixel(filas-1, columnas-2).getG());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, columnas-2).getG());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, columnas-1).getG());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxG = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    auxCalculoMediana.push_back(imag->getPixel(filas-1, columnas-1).getB());
    auxCalculoMediana.push_back(imag->getPixel(filas-1, columnas-2).getB());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, columnas-2).getB());
    auxCalculoMediana.push_back(imag->getPixel(filas-2, columnas-1).getB());
    sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
    auxB = (auxCalculoMediana[1] + auxCalculoMediana[2])/2;
    auxCalculoMediana.clear();

    pix_aux.setPixelRGB(auxR, auxG, auxB);

    imag->setPixel(0, imag->getColumnas()-1, pix_aux);
}

void Filtros::aplicaFiltroMedianaBordes(Imagen *imag)
{
    unsigned int auxR, auxG, auxB;

    vector<int> auxCalculoMediana;

    Pixel pix_aux;

    int columnas = imag->getColumnas(), filas= imag->getFilas();

    //Img[i][0]
    for(int i=1; i<filas-2; i++)
    {
        auxCalculoMediana.push_back(imag->getPixel(i, 0).getR());
        auxCalculoMediana.push_back(imag->getPixel(i-1, 0).getR());
        auxCalculoMediana.push_back(imag->getPixel(i-1, 1).getR());
        auxCalculoMediana.push_back(imag->getPixel(i, 1).getR());
        auxCalculoMediana.push_back(imag->getPixel(i+1, 1).getR());
        auxCalculoMediana.push_back(imag->getPixel(i+1, 0).getR());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxR = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        auxCalculoMediana.push_back(imag->getPixel(i, 0).getG());
        auxCalculoMediana.push_back(imag->getPixel(i-1, 0).getG());
        auxCalculoMediana.push_back(imag->getPixel(i-1, 1).getG());
        auxCalculoMediana.push_back(imag->getPixel(i, 1).getG());
        auxCalculoMediana.push_back(imag->getPixel(i+1, 1).getG());
        auxCalculoMediana.push_back(imag->getPixel(i+1, 0).getG());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxG = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        auxCalculoMediana.push_back(imag->getPixel(i, 0).getB());
        auxCalculoMediana.push_back(imag->getPixel(i-1, 0).getB());
        auxCalculoMediana.push_back(imag->getPixel(i-1, 1).getB());
        auxCalculoMediana.push_back(imag->getPixel(i, 1).getB());
        auxCalculoMediana.push_back(imag->getPixel(i+1, 1).getB());
        auxCalculoMediana.push_back(imag->getPixel(i+1, 0).getB());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxB = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        pix_aux.setPixelRGB(auxR, auxG, auxB);

        imag->setPixel(i, 0, pix_aux);
    }

    //Img[i][columnas-1]
    for(int i=1; i<filas-2; i++)
    {
        auxCalculoMediana.push_back(imag->getPixel(i, columnas-1).getR());
        auxCalculoMediana.push_back(imag->getPixel(i-1, columnas-1).getR());
        auxCalculoMediana.push_back(imag->getPixel(i-1, columnas-2).getR());
        auxCalculoMediana.push_back(imag->getPixel(i, columnas-2).getR());
        auxCalculoMediana.push_back(imag->getPixel(i+1, columnas-2).getR());
        auxCalculoMediana.push_back(imag->getPixel(i+1, columnas-1).getR());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxR = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        auxCalculoMediana.push_back(imag->getPixel(i, columnas-1).getG());
        auxCalculoMediana.push_back(imag->getPixel(i-1, columnas-1).getG());
        auxCalculoMediana.push_back(imag->getPixel(i-1, columnas-2).getG());
        auxCalculoMediana.push_back(imag->getPixel(i, columnas-2).getG());
        auxCalculoMediana.push_back(imag->getPixel(i+1, columnas-2).getG());
        auxCalculoMediana.push_back(imag->getPixel(i+1, columnas-1).getG());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxG = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        auxCalculoMediana.push_back(imag->getPixel(i, columnas-1).getB());
        auxCalculoMediana.push_back(imag->getPixel(i-1, columnas-1).getB());
        auxCalculoMediana.push_back(imag->getPixel(i-1, columnas-2).getB());
        auxCalculoMediana.push_back(imag->getPixel(i, columnas-2).getB());
        auxCalculoMediana.push_back(imag->getPixel(i+1, columnas-2).getB());
        auxCalculoMediana.push_back(imag->getPixel(i+1, columnas-1).getB());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxB = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        pix_aux.setPixelRGB(auxR, auxG, auxB);

        imag->setPixel(i, columnas-1, pix_aux);
    }

    //Img[0][i]
    for(int i=1; i<filas-2; i++)
    {
        auxCalculoMediana.push_back(imag->getPixel(0, i).getR());
        auxCalculoMediana.push_back(imag->getPixel(0, i-1).getR());
        auxCalculoMediana.push_back(imag->getPixel(1, i-1).getR());
        auxCalculoMediana.push_back(imag->getPixel(1, i).getR());
        auxCalculoMediana.push_back(imag->getPixel(1, i+1).getR());
        auxCalculoMediana.push_back(imag->getPixel(0, i+1).getR());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxR = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        auxCalculoMediana.push_back(imag->getPixel(0, i).getG());
        auxCalculoMediana.push_back(imag->getPixel(0, i-1).getG());
        auxCalculoMediana.push_back(imag->getPixel(1, i-1).getG());
        auxCalculoMediana.push_back(imag->getPixel(1, i).getG());
        auxCalculoMediana.push_back(imag->getPixel(1, i+1).getG());
        auxCalculoMediana.push_back(imag->getPixel(0, i+1).getG());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxG = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        auxCalculoMediana.push_back(imag->getPixel(0, i).getB());
        auxCalculoMediana.push_back(imag->getPixel(0, i-1).getB());
        auxCalculoMediana.push_back(imag->getPixel(1, i-1).getB());
        auxCalculoMediana.push_back(imag->getPixel(1, i).getB());
        auxCalculoMediana.push_back(imag->getPixel(1, i+1).getB());
        auxCalculoMediana.push_back(imag->getPixel(0, i+1).getB());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxB = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        pix_aux.setPixelRGB(auxR, auxG, auxB);

        imag->setPixel(0, i, pix_aux);
    }

    //Img[filas-1][i]
    for(int i=1; i<filas-2; i++)
    {
        auxCalculoMediana.push_back(imag->getPixel(filas-1, i).getR());
        auxCalculoMediana.push_back(imag->getPixel(filas-1, i-1).getR());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i-1).getR());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i).getR());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i+1).getR());
        auxCalculoMediana.push_back(imag->getPixel(filas-1, i+1).getR());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxR = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        auxCalculoMediana.push_back(imag->getPixel(filas-1, i).getG());
        auxCalculoMediana.push_back(imag->getPixel(filas-1, i-1).getG());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i-1).getG());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i).getG());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i+1).getG());
        auxCalculoMediana.push_back(imag->getPixel(filas-1, i+1).getG());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxG = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        auxCalculoMediana.push_back(imag->getPixel(filas-1, i).getB());
        auxCalculoMediana.push_back(imag->getPixel(filas-1, i-1).getB());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i-1).getB());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i).getB());
        auxCalculoMediana.push_back(imag->getPixel(filas-2, i+1).getB());
        auxCalculoMediana.push_back(imag->getPixel(filas-1, i+1).getB());
        sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
        auxB = (auxCalculoMediana[2] + auxCalculoMediana[3])/2;
        auxCalculoMediana.clear();

        pix_aux.setPixelRGB(auxR, auxG, auxB);

        imag->setPixel(filas-1, i, pix_aux);
    }
}

void Filtros::aplicaFiltroMedianaCentro(Imagen *imag)
{
    //Imagen* imag = img;
    unsigned int auxR, auxG, auxB;

    vector<int> auxCalculoMediana;

    Pixel pix_aux;

    int columnas = imag->getColumnas(), filas= imag->getFilas();

    for(int i=1; i<filas-2; i++)
        for(int j=1; j<columnas-2; j++)
        {
            if (i == 50 and j == 60)
                int hola;
            auxCalculoMediana.push_back(imag->getPixel(i, j).getR());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j).getR());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j+1).getR());
            auxCalculoMediana.push_back(imag->getPixel(i, j+1).getR());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j+1).getR());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j).getR());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j-1).getR());
            auxCalculoMediana.push_back(imag->getPixel(i, j-1).getR());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j-1).getR());
            sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
            auxR = auxCalculoMediana[4];
            auxCalculoMediana.clear();

            auxCalculoMediana.push_back(imag->getPixel(i, j).getG());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j).getG());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j+1).getG());
            auxCalculoMediana.push_back(imag->getPixel(i, j+1).getG());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j+1).getG());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j).getG());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j-1).getG());
            auxCalculoMediana.push_back(imag->getPixel(i, j-1).getG());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j-1).getG());
            sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
            auxG = auxCalculoMediana[4];
            auxCalculoMediana.clear();

            auxCalculoMediana.push_back(imag->getPixel(i, j).getB());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j).getB());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j+1).getB());
            auxCalculoMediana.push_back(imag->getPixel(i, j+1).getB());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j+1).getB());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j).getB());
            auxCalculoMediana.push_back(imag->getPixel(i+1, j-1).getB());
            auxCalculoMediana.push_back(imag->getPixel(i, j-1).getB());
            auxCalculoMediana.push_back(imag->getPixel(i-1, j-1).getB());
            sort(auxCalculoMediana.begin(), auxCalculoMediana.end());
            auxB = auxCalculoMediana[4];
            auxCalculoMediana.clear();

            pix_aux.setPixelRGB(auxR, auxG, auxB);

            imag->setPixel(i, j, pix_aux);
        }

    //img = imag;
}


void Filtros::aumentarBrillo(Imagen *img)
{
    Pixel pix_aux;

    for(int i=0; i<img->getFilas(); i++)
        for(int j=0; j<img->getColumnas(); j++)
        {
            pix_aux = img->getPixel(i, j);
            pix_aux.aumentarBrillo();
            img->setPixel(i, j, pix_aux);
        }
}
