#include "algoritmodelpintor.h"
#include <limits>

AlgoritmoDelPintor::AlgoritmoDelPintor(Imagen img)
{
    imag = img;
}

Imagen AlgoritmoDelPintor::aplicarAlgoritmo(int f_0, int c_0)
{
    Pixel pixelInicial = imag.getPixel(f_0, c_0);

    inicializarMatrizDeAnalisis(imag.getFilas(), imag.getColumnas());

    unsigned int rangoTolerancia = preguntarRangoDeTolerancia(imag.getRango());

    profundidad = 0;

    pintarVecinos(f_0, c_0, pixelInicial, rangoTolerancia);

    return imag;
}

void AlgoritmoDelPintor::pintarVecinos(int f, int c, Pixel pixelComparacion, unsigned int tolerancia)
{
    ++profundidad;

    if (imag.formaParteDeLaImagen(f, c) and profundidad < 58100){

        if (esVecino(pixelComparacion, imag.getPixel(f, c), tolerancia))
        {
           if(!fueAnalizado.at(f).at(c))
           {
                fueAnalizado[f][c] = true;
                for ( int vecino = 0; vecino < 8; vecino++){
                    pintarVecinos(f + vecinos[vecino].f, c + vecinos[vecino].c, pixelComparacion, tolerancia);
                }
                imag.setPixel(f, c, Pixel(0, 0, 255));
           }
        }
    }

    --profundidad;

}

unsigned int AlgoritmoDelPintor::preguntarRangoDeTolerancia(int maximoRangoImag)
{
    int tolerancia;

    cout<<"\t|__Ingrese el rango de tolerancia que desea considerar: ";
    cin>>tolerancia;

    while(tolerancia < 0 or tolerancia > maximoRangoImag or !cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t|__Ingrese un valor de tolerancia dentro del rango admitido por la imagen [0, "<<maximoRangoImag<<"]: ";
        cin>>tolerancia;
    }

    return tolerancia;
}

void AlgoritmoDelPintor::inicializarMatrizDeAnalisis(int f, int c)
{
    vector<vector<bool>> matriz(f, vector<bool> (c, false));

    fueAnalizado = matriz;
}

bool AlgoritmoDelPintor::esVecino(Pixel pixelPintado, Pixel analisis, unsigned int tolerancia)
{
    bool rEnRango = analisis.getR() <= pixelPintado.getR()+int(tolerancia) and analisis.getR() >= pixelPintado.getR()- int(tolerancia);
    bool bEnRango = analisis.getB() <= pixelPintado.getB()+int(tolerancia) and analisis.getB() >= pixelPintado.getB()- int(tolerancia);
    bool gEnRango = analisis.getG() <= pixelPintado.getG()+int(tolerancia) and analisis.getG() >= pixelPintado.getG()- int(tolerancia);

    if (rEnRango and gEnRango and bEnRango)
    {
        return true;
    }
    else
    {
        return false;
    }

}
