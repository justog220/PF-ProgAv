#include "archivosaic.h"

ArchivosAIC::ArchivosAIC()
{

}

Imagen ArchivosAIC::leer(string ruta)
{
    Imagen img;
    archi.open(ruta, ios::in);

    if(!archi.is_open()){
        cout<<"Error al abrir la imagen."<<endl;
        cout<<ruta;
    }else{
        string linea;

        getline(archi, linea);

        while(linea[0]!='#')
            getline(archi, linea);
        string ocurrencia = "escala:";

        int pos = linea.find(ocurrencia);
        cout<<pos;



    }

    return img;
}

void ArchivosAIC::guardar(string ruta, Imagen *img)
{

}
