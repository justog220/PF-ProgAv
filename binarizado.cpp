#include "binarizado.h"

Binarizado::Binarizado()
{

}

Imagen Binarizado::aplicarFiltro(Imagen &imagen)
{
    if(!sePuedeBinarizar(imagen))
    {
        cout<<"La imagen no se puede binarizar.";
    }else
    {
        int puntoBinarizacion = obtenerPuntoBinarizacion(imagen);
        for(int i = 0; i < imagen.getFilas(); i++)
            for(int j = 0; j < imagen.getColumnas(); j++)
            {
                if(imagen.getPixel(i, j).getIntensidad() >= puntoBinarizacion)
                    imagen.setPixel(i, j, Pixel(imagen.getRango(), imagen.getRango(), imagen.getRango()));
                else
                    imagen.setPixel(i, j, Pixel(0, 0, 0));
            }
    }

    return imagen;
}

bool Binarizado::sePuedeBinarizar(Imagen &imagen)
{
    if(imagen.getIdentificador() == "P2" or imagen.getIdentificador() == "P5")
        return true;
    else
        return false;
}

int Binarizado::obtenerPuntoBinarizacion(Imagen &imagen)
{
    int punto;
    cout<<"\t|__Ingrese nivel a partir del cual se binariza [0, "<<imagen.getRango()<<"]: ";
    cin>>punto;

    while(punto < 0 or punto > imagen.getRango())
    {
        cout<<"\t|__Ingrese un nivel válido [0, "<<imagen.getRango()<<"]: ";
        cin>>punto;
    }

    return punto;
}
