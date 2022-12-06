#include "procesadorestadistico.h"
#include <math.h>
#include <algorithm>

ProcesadorEstadistico::ProcesadorEstadistico()
{

}

vector<int> ProcesadorEstadistico::devuelveFrecuenciaR(Imagen &img)
{
    unsigned int auxR;
    vector<int> frecuenciaR;
    frecuenciaR.resize(img.getRango()+1, 0);
    Pixel pixelAux;


    for(int i=0; i<img.getFilas(); i++)
        for(int j=0; j<img.getColumnas(); j++)
        {
            pixelAux = img.getPixel(i, j);
            auxR = pixelAux.getR();
            frecuenciaR[auxR]++;
        }


    return frecuenciaR;
}

vector<int> ProcesadorEstadistico::devuelveFrecuenciaG(Imagen &img)
{
    unsigned int auxG;
    vector<int> frecuenciaG;
    frecuenciaG.resize(img.getRango()+1, 0);
    Pixel pixelAux;


    for(int i=0; i<img.getFilas(); i++)
        for(int j=0; j<img.getColumnas(); j++)
        {
            pixelAux = img.getPixel(i, j);
            auxG = pixelAux.getG();
            frecuenciaG[auxG]++;
        }

    return frecuenciaG;

}

vector<int> ProcesadorEstadistico::devuelveFrecuenciaB(Imagen &img)
{
    unsigned int auxB;
    vector<int> frecuenciaB;
    frecuenciaB.resize(img.getRango()+1, 0);
    Pixel pixelAux;


    for(int i=0; i<img.getFilas(); i++)
        for(int j=0; j<img.getColumnas(); j++)
        {
            pixelAux = img.getPixel(i, j);
            auxB = pixelAux.getB();
            frecuenciaB[auxB]++;
        }

    return frecuenciaB;
}

vector<int> ProcesadorEstadistico::devuelveFrecuenciaIntensidad(Imagen &img)
{
    return devuelveFrecuenciaR(img);
}

int ProcesadorEstadistico::devuelveRMasFrecuente(Imagen &img)
{
    vector<int> frecuenciasR = devuelveFrecuenciaR(img);

    int mayor = 0, r = 0;

    for(int i = 0; i < frecuenciasR.size(); i++)
        if (frecuenciasR[i] > mayor){
            r = i;
            mayor = frecuenciasR[i];
        }

    return r;
}

int ProcesadorEstadistico::devuelveGMasFrecuente(Imagen &img)
{
    vector<int> frecuenciasG = devuelveFrecuenciaG(img);
    int mayor = 0, g = 0;

    for(int i = 0; i<frecuenciasG.size(); i++)
        if (frecuenciasG[i] > mayor){
            g = i;
            mayor = frecuenciasG[i];
        }

    return g;
}

int ProcesadorEstadistico::devuelveBMasFrecuente(Imagen &img)
{
    vector<int> frecuenciasB = devuelveFrecuenciaB(img);

    int mayor = 0, b = 0;

    for(int i = 0; i<frecuenciasB.size(); i++)
        if (frecuenciasB[i] > mayor){
            b = i;
            mayor = frecuenciasB[i];
        }

    return b;
}

int ProcesadorEstadistico::devuelveIntensidadMasFrecuente(Imagen &img)
{
    return devuelveRMasFrecuente(img);
}



vector<int> ProcesadorEstadistico::hallarMaximoMinimoR(Imagen &img)
{
    vector<int> maximo_y_minimo(2);
    maximo_y_minimo[0] = 0;
    maximo_y_minimo[1] = img.getPixel(0, 0).getR();
    Pixel pixelAux;
    for(int i=0; i<img.getFilas(); i++)
        for(int j=0; j<img.getColumnas(); j++)
        {
            pixelAux = img.getPixel(i,j);
            if(pixelAux.getR() > maximo_y_minimo[0])
            {
                maximo_y_minimo[0] = pixelAux.getR();
            }
            if(pixelAux.getR() < maximo_y_minimo[1])
            {
                maximo_y_minimo[1] = pixelAux.getR();
            }
        }

    return maximo_y_minimo;
}

vector<int> ProcesadorEstadistico::hallarMaximoMinimoG(Imagen &img)
{
    vector<int> maximo_y_minimo(2);
    maximo_y_minimo[0] = 0;
    maximo_y_minimo[1] = img.getPixel(0, 0).getG();
    Pixel pixelAux;
    for(int i=0; i<img.getFilas(); i++)
        for(int j=0; j<img.getColumnas(); j++)
        {
            pixelAux = img.getPixel(i,j);
            if(pixelAux.getG() > maximo_y_minimo[0])
            {
                maximo_y_minimo[0] = pixelAux.getG();
            }
            if(pixelAux.getG() < maximo_y_minimo[1])
            {
                maximo_y_minimo[1] = pixelAux.getG();
            }
        }

    return maximo_y_minimo;
}

vector<int> ProcesadorEstadistico::hallarMaximoMinimoB(Imagen &img)
{
    vector<int> maximo_y_minimo(2);
    maximo_y_minimo[0] = 0;
    maximo_y_minimo[1] = img.getPixel(0, 0).getB();
    Pixel pixelAux;
    for(int i=0; i<img.getFilas(); i++)
        for(int j=0; j<img.getColumnas(); j++)
        {
            pixelAux = img.getPixel(i,j);
            if(pixelAux.getB() > maximo_y_minimo[0])
            {
                maximo_y_minimo[0] = pixelAux.getB();
            }
            if(pixelAux.getB() < maximo_y_minimo[1])
            {
                maximo_y_minimo[1] = pixelAux.getB();
            }
        }

    return maximo_y_minimo;
}

int ProcesadorEstadistico::devolverIntensidadMedia(Imagen &img)
{
//    vector<int> intensidades = devuelveFrecuenciaIntensidad(img);

//    uint menor, mayor;
//    bool seGuardoMenor = false;

//    for (int i = 0; i < intensidades.size(); i++)
//        if (intensidades[i] != 0) {
//            if (not seGuardoMenor){
//                menor = i;
//                seGuardoMenor = true;
//            }
//            mayor = i;
//        }

//    return (mayor+menor)/2;

    uint acumulador = 0, pixeles = 0;//(img->getFilas()*img->getColumnas());

    for(int i=0; i<img.getFilas(); i++)
        for(int j=0; j<img.getColumnas(); j++)
        {
            acumulador += img.getPixel(i, j).getIntensidad();
            pixeles++;
        }
    return acumulador/pixeles;
}

int ProcesadorEstadistico::devolverModaR(Imagen &img)
{
    return devuelveRMasFrecuente(img);
}

int ProcesadorEstadistico::devolverModaG(Imagen &img)
{
    return devuelveGMasFrecuente(img);
}

int ProcesadorEstadistico::devolverModaB(Imagen &img)
{
    return devuelveBMasFrecuente(img);
}


void ProcesadorEstadistico::informarDatosEstadisticos(Imagen &img)
{
    vector<float> promediosRGB = devolverPromedioRGB(img);
    vector<int> maximoMinimoR = hallarMaximoMinimoR(img), maximoMinimoG = hallarMaximoMinimoG(img), maximoMinimoB = hallarMaximoMinimoB(img);
    vector<float> desviaciones = devolverDesviacionEstandarRGB(img);
    cout<<"\t----Datos estadisticos----";
    cout<<"\n\t---------Promedio---------\n\tR: "<<promediosRGB[0]<<"\n\tG: "<<promediosRGB[1]<<"\n\tB: "<<promediosRGB[2];
    cout<<"\n\t---------Minimo---------\n\tR: "<<maximoMinimoR.at(1)<<"\n\tG: "<<maximoMinimoG.at(1)<<"\n\tB: "<<maximoMinimoB.at(1);
    cout<<"\n\t---------Maximo---------\n\tR: "<<maximoMinimoR.at(0)<<"\n\tG: "<<maximoMinimoG.at(0)<<"\n\tB: "<<maximoMinimoB.at(0);
    cout<<"\n\t---------Moda---------\n\tR: "<<devolverModaR(img)<<"\n\tG: "<<devolverModaG(img)<<"\n\tB: "<<devolverModaB(img);
    cout<<"\n\t---------Desviaciones estandar---------\n\tR: "<<desviaciones.at(0)<<"\n\tG: "<<desviaciones.at(1)<<"\n\tB: "<<desviaciones.at(2);



    cout.flush();
}

vector<float> ProcesadorEstadistico::devolverPromedioRGB(Imagen &img)
{
    vector<float> promedios;

    vector<int> frecuenciasR = devuelveFrecuenciaR(img);
    vector<int> frecuenciasG = devuelveFrecuenciaG(img);
    vector<int> frecuenciasB = devuelveFrecuenciaB(img);

    float acumuladorR = 0;
    float acumuladorG = 0;
    float acumuladorB = 0;
    for(uint nivel = 0; nivel < frecuenciasR.size(); nivel ++)
    {
        acumuladorR += (frecuenciasR[nivel]*nivel);
        acumuladorG += (frecuenciasG[nivel]*nivel);
        acumuladorB += (frecuenciasB[nivel]*nivel);
    }

    promedios.push_back(acumuladorR/img.getNroPixeles());
    promedios.push_back(acumuladorG/img.getNroPixeles());
    promedios.push_back(acumuladorB/img.getNroPixeles());

    return promedios;
}

vector<float> ProcesadorEstadistico::devolverDesviacionEstandarRGB(Imagen &img)
{
    vector<float> desviacionesRGB;
    vector<float> promedios = devolverPromedioRGB(img);

    vector<int> frecuenciasR = devuelveFrecuenciaR(img);
    vector<int> frecuenciasG = devuelveFrecuenciaG(img);
    vector<int> frecuenciasB = devuelveFrecuenciaB(img);

    float acumuladorR = 0;
    float acumuladorG = 0;
    float acumuladorB = 0;
    for(uint nivel = 0; nivel < frecuenciasR.size(); nivel ++)
    {
        acumuladorR += pow((nivel - promedios.at(0)), 2) * frecuenciasR[nivel];
        acumuladorG += pow((nivel - promedios.at(1)), 2) * frecuenciasG[nivel];
        acumuladorB += pow((nivel - promedios.at(2)), 2) * frecuenciasB[nivel];
    }

    desviacionesRGB.push_back(acumuladorR/img.getNroPixeles());
    desviacionesRGB.push_back(acumuladorG/img.getNroPixeles());
    desviacionesRGB.push_back(acumuladorB/img.getNroPixeles());

    return desviacionesRGB;
}
