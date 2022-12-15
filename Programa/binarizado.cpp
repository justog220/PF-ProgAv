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
        for(int f = 0; f < imagen.getFilas(); f++)
            for(int c = 0; c < imagen.getColumnas(); c++)
            {
                if(imagen.getPixel(f, c).getIntensidad() >= puntoBinarizacion)
                    imagen.setPixel(f, c, Pixel(imagen.getRango(), imagen.getRango(), imagen.getRango()));
                else
                    imagen.setPixel(f, c, Pixel(0, 0, 0));

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

    while(punto < 0 or punto > imagen.getRango() or !cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\t|__Ingrese un nivel válido [0, "<<imagen.getRango()<<"]: ";
        cin>>punto;
    }

    return punto;
}
