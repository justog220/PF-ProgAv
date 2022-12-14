#include "algoritmodelpintor.h"

AlgoritmoDelPintor::AlgoritmoDelPintor(Imagen img)
{
    imag = img;
}

Imagen AlgoritmoDelPintor::aplicarAlgoritmo(int f_0, int c_0)
{
    Pixel pixel_inicial = imag.getPixel(f_0, c_0);

    inicializarMatrizDeAnalisis(imag.getFilas(), imag.getColumnas());

    unsigned int rango_tolerancia = preguntarRangoDeTolerancia(imag.getRango());

    profundidad = 0;

    pintarVecinos(f_0, c_0, pixel_inicial, rango_tolerancia);

    return imag;
}

void AlgoritmoDelPintor::pintarVecinos(int f, int c, Pixel pixelComparacion, unsigned int tolerancia)
{
    ++profundidad;

    if (imag.formaParteDeLaImagen(f, c) and profundidad < 58100){

        if (esVecino(pixelComparacion, imag.getPixel(f, c), tolerancia)){
           if(!fue_analizado.at(f).at(c))
           {
                fue_analizado[f][c] = true;
                for ( int vecino = 0; vecino < 8; vecino++){
                    pintarVecinos(f + vecinos[vecino].f, c + vecinos[vecino].c, pixelComparacion, tolerancia);
                }
                imag.setPixel(f, c, Pixel(0, 0, 255));}
        }
    }

    --profundidad;

}

unsigned int AlgoritmoDelPintor::preguntarRangoDeTolerancia(int maximo_rango_imag)
{
    int tolerancia;

    cout<<"\t|__Ingrese el rango de tolerancia que desea considerar: ";
    cin>>tolerancia;

    while(tolerancia < 0 or tolerancia > maximo_rango_imag){
        cout << "\t|__Ingrese un valor de tolerancia dentro del rango admitido por la imagen [0, "<<maximo_rango_imag<<"]: ";
        cin>>tolerancia;
    }

    return tolerancia;
}

void AlgoritmoDelPintor::inicializarMatrizDeAnalisis(int f, int c)
{
    vector<vector<bool>> matriz(f, vector<bool> (c, false));

    fue_analizado = matriz;
}

bool AlgoritmoDelPintor::esVecino(Pixel pixel_pintado, Pixel analisis, unsigned int tolerancia)
{
    bool rEnRango = analisis.getR() <= pixel_pintado.getR()+int(tolerancia) and analisis.getR() >= pixel_pintado.getR()- int(tolerancia);
    bool bEnRango = analisis.getB() <= pixel_pintado.getB()+int(tolerancia) and analisis.getB() >= pixel_pintado.getB()- int(tolerancia);
    bool gEnRango = analisis.getG() <= pixel_pintado.getG()+int(tolerancia) and analisis.getG() >= pixel_pintado.getG()- int(tolerancia);

    if (rEnRango and gEnRango and bEnRango){
        return true;
    }else{
        return false;
    }

}
