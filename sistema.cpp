#include "sistema.h"

Sistema::Sistema()
{
    graf.setEspacio(espDeTrabajo);
}

void Sistema::ejecutar(QApplication *a)
{
    espDeTrabajo.cargarCarpetas();

    ArchivosPNM archi;
    Imagen img;

    int opcDir, opcArch;

    cout<<"1)Carpeta 1\n"<<"2)Carpeta 2\n"<<"3)Carpeta 3\n"<<"4)Carpeta 4\n"<<"5)Carpeta 5\n"<<"Seleccione la carpeta: ";
    cin>>opcDir;

    while(opcDir<1 or opcDir>5)
    {
        cout<<"\nIngrese una opcion valida: ";
        cin>>opcDir;
    }

    system("clear");

//    string ruta = raiz+carpetas[opcDir-1];

//    getListaDeArchivos(ruta);

    string ruta = espDeTrabajo.getRuta(opcDir);

    vector<string> listaDeArchivos = espDeTrabajo.getListaDeArchivos(ruta);

    for(unsigned int i=0; i<listaDeArchivos.size(); i++)
        cout<<i+1<<") "<<listaDeArchivos[i]<<"\n";
    cout<<"Seleccione el archivo: ";

    cin>>opcArch;

    graf.setOpciones(opcDir, opcArch);

    graf.cargarImagen();

    graf.show();

    a->exec();
}
