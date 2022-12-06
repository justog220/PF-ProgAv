#include "brillo.h"

#include <math.h>

Brillo::Brillo(int opc)
{
    if(opc == 1)
    {
        seAumenta = true;
        seReduce = false;
    }else
    {
        seAumenta = false;
        seReduce = true;
    }
}

Imagen Brillo::aplicarFiltro(Imagen &imagen)
{
    if(seAumenta)
        aumentarBrillo(&imagen);

    if(seReduce)
        aumentarBrillo(&imagen);

    return imagen;
}

void Brillo::aumentarBrillo(Imagen *imagen)
{
    consultarDiferencia(imagen);

    int auxR, auxG, auxB;
    Pixel pix_aux;

    for(int i = 0; i < imagen->getFilas(); i++)
        for(int j = 0; j < imagen->getColumnas(); j++)
        {
            pix_aux = imagen->getPixel(i, j);
            auxR = pix_aux.getR() + diferencia;
            if(auxR > imagen->getRango())
                auxR = imagen->getRango();

            auxG = pix_aux.getG() + diferencia;
            if(auxG > imagen->getRango())
                auxG = imagen->getRango();

            auxB = pix_aux.getB() + diferencia;
            if(auxB > imagen->getRango())
                auxB = imagen->getRango();

            pix_aux.setPixelRGB(auxR, auxG, auxB);

            imagen->setPixel(i, j, pix_aux);
        }

}

void Brillo::reducirBrillo(Imagen *imagen)
{
    consultarDiferencia(imagen);

    int auxR, auxG, auxB;
    Pixel pix_aux;

    for(int i = 0; i < imagen->getFilas(); i++)
        for(int j = 0; j < imagen->getColumnas(); j++)
        {
            pix_aux = imagen->getPixel(i, j);
            auxR = pix_aux.getR() - diferencia;
            if(auxR < 0)
                auxR = imagen->getRango();

            auxG = pix_aux.getG() - diferencia;
            if(auxG < 0)
                auxG = imagen->getRango();

            auxB = pix_aux.getB() - diferencia;
            if(auxB < 0)
                auxB = imagen->getRango();

            pix_aux.setPixelRGB(auxR, auxG, auxB);

            imagen->setPixel(i, j, pix_aux);
        }
}

void Brillo::consultarDiferencia(Imagen *imagen)
{
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
        int cantidad;
        diferencia = -1;
        while(diferencia <= 0 or diferencia >= imagen->getRango())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\tIngrese una cantidad dentro del rango [0, "<<imagen->getRango()<<"]: ";
            cout.flush();
            cin>>cantidad;
            diferencia = cantidad;
        }
    }
}
