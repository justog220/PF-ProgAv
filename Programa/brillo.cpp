#include "brillo.h"

#include <math.h>

Brillo::Brillo(int opc)
{
    if(opc == 1)
    {
        seAumenta = true;
        seReduce = false;
    }else if(opc == 2)
    {
        seAumenta = false;
        seReduce = true;
    }
}

Imagen Brillo::aplicarFiltro(Imagen &imagen)
{
    if(seAumenta)
        aumentarBrillo(imagen);

    if(seReduce)
        reducirBrillo(imagen);

    return imagen;
}

void Brillo::aumentarBrillo(Imagen &imagen)
{
    consultarDiferencia(imagen);

    int auxR, auxG, auxB;
    Pixel pixAux;

    for(int i = 0; i < imagen.getFilas(); i++)
        for(int j = 0; j < imagen.getColumnas(); j++)
        {
            pixAux = imagen.getPixel(i, j);
            auxR = pixAux.getR() + diferencia;
            if(auxR > imagen.getRango())
                auxR = imagen.getRango();

            auxG = pixAux.getG() + diferencia;
            if(auxG > imagen.getRango())
                auxG = imagen.getRango();

            auxB = pixAux.getB() + diferencia;
            if(auxB > imagen.getRango())
                auxB = imagen.getRango();

            pixAux.setPixelRGB(auxR, auxG, auxB);

            imagen.setPixel(i, j, pixAux);
        }

}

void Brillo::reducirBrillo(Imagen &imagen)
{
    consultarDiferencia(imagen);

    int auxR, auxG, auxB;
    Pixel pixAux;

    for(int i = 0; i < imagen.getFilas(); i++)
        for(int j = 0; j < imagen.getColumnas(); j++)
        {
            pixAux = imagen.getPixel(i, j);
            auxR = pixAux.getR() - diferencia;
            if(auxR < 0)
                auxR = 0;

            auxG = pixAux.getG() - diferencia;
            if(auxG < 0)
                auxG = 0;

            auxB = pixAux.getB() - diferencia;
            if(auxB < 0)
                auxB = 0;

            pixAux.setPixelRGB(auxR, auxG, auxB);

            imagen.setPixel(i, j, pixAux);
        }
}

void Brillo::cambiaOpcion()
{
    if(seAumenta)
    {
        seAumenta = false;
        seReduce = true;
    }else
    {
        seAumenta = true;
        seReduce = false;
    }
}

void Brillo::consultarDiferencia(Imagen &imagen)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char opc;
    cout<<"\t¿Desea especificar cuanto aumentar/reducir?\n\t|__[S]i\n\t|__[N]o\n\t\t>>";
    cout.flush();
    cin>>opc;

    opc = toupper(opc);

    while(opc != 'N' and opc != 'S')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\t|__Ingrese una opcion válida: ";
        cin>>opc;
        opc = toupper(opc);
    }

    if(opc == 'N')
        diferencia = 50;
    else
    {
        diferencia = -1;
        while(diferencia <= 0 or diferencia >= imagen.getRango())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\t|__Ingrese una cantidad dentro del rango [0, "<<imagen.getRango()<<"]: ";
            cout.flush();
            cin>>diferencia;
        }
    }
}
