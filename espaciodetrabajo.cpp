#include "espaciodetrabajo.h"
#include <algorithm>
#include <thread>

EspacioDeTrabajo::EspacioDeTrabajo()
{
  cargarCarpetas();
}


void EspacioDeTrabajo::cargarCarpetas()
{
    if(carpetas.size()==0)
    {
        carpetas.push_back("grupo_imagenes_1/");
        carpetas.push_back("grupo_imagenes_2/");
        carpetas.push_back("grupo_imagenes_3_corruptas/");
        carpetas.push_back("Imagenes_guardadas/");
    }



}

vector<string> EspacioDeTrabajo::getCarpetas()
{
    return carpetas;
}

vector<string> EspacioDeTrabajo::getListaDeArchivos(string ruta)
{
    if(!listaDeArchivos.empty())
        listaDeArchivos.clear();

    if(getNroArchivos() == 0)
    {
        DIR *dir = opendir(ruta.c_str());
        if (dir != NULL)
        {
            string pto("."), ptopto("..");
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL)
            {
                if( entry->d_name != pto and entry->d_name != ptopto )
                {
                    listaDeArchivos.push_back(entry->d_name);
                }
            }
            closedir(dir);
        }
    }

    sort(listaDeArchivos.begin(), listaDeArchivos.end());

    return listaDeArchivos;
}

string EspacioDeTrabajo::getRuta(int opcDir, int opcArch)
{
    cargarCarpetas();

    string ruta;

    ruta = raiz;

    switch(opcDir)
    {
    case 1:
        ruta = ruta.append(carpetas[opcDir-1]);
        break;
    case 2:
        ruta = ruta.append(carpetas[opcDir-1]);
        break;
    case 3:
        ruta = ruta.append(carpetas[opcDir-1]);
        break;
    case 4:
        ruta = ruta.append(carpetas[opcDir-1]);
        break;

    }

    if(opcArch == -8)
    {
        return ruta;
    }else{
        getListaDeArchivos(ruta);

        ruta.append(listaDeArchivos[opcArch-1]);

        return ruta;
    }

}

string EspacioDeTrabajo::getPNMoAIC(string ruta)
{
    string nom_archivo = getNombreArchivo(ruta);

    if (esPNM(nom_archivo))
        return "pnm";
    else if (esAIC(nom_archivo))
        return "aic";
    else
        throw ExcepcionArchivoNoSoportado();


}

bool EspacioDeTrabajo::esPNM(string archivo)
{
    string extension = archivo.substr(archivo.length()-3);

    if(extension == "pnm" or extension == "pgm" or extension == "ppm" or extension == "pbm")
        return true;
    else
        return false;
}

bool EspacioDeTrabajo::esAIC(string archivo)
{
    string extension = archivo.substr(archivo.length()-3);

    if(extension == "aic")
        return true;
    else
        return false;
}

int EspacioDeTrabajo::getNroArchivos()
{
    return listaDeArchivos.size();
}

void EspacioDeTrabajo::llevarRegistro(int opcDir, int opcArch)
{
    ofstream registro;
    registro.open("registro.txt");

    registro << opcDir << " " << opcArch;
}

void EspacioDeTrabajo::guardarImagen(Imagen *img)
{

    char opcFormato;
    cout<<"\t|>[P]NM\n\t|>[A]IC\n\t  Seleccione el formato de guardado:";
    cin>>opcFormato;

    opcFormato= toupper(opcFormato);

    while (opcFormato != 'P' and opcFormato != 'A') {
        cout<<"\t\t|__Inserte una opcion valida: ";
        cin>>opcFormato;
        opcFormato = toupper(opcFormato);
    }

    bool estaDeAcuerdo;

    if(opcFormato == 'A' and img->getIdentificador() != "P2" and img->getIdentificador() != "P2C" and img->getIdentificador() != "P5")
    {
        char acuerdo;
        cout<<"\nSolo pueden ser almacenadas con formato AIC imágenes en escala de grises. Se procederá a guardar en formato PNM.\nPresione cualquier tecla para continuar.";
        cout<<"\n¿Está de acuerdo?\n[S]i | [N]o: ";
        cin>>acuerdo;

        acuerdo = toupper(acuerdo);

        while (acuerdo != 'S' and acuerdo != 'N') {
            cout<<"\nInserte una opcion valida: ";
            cin>>acuerdo;
            acuerdo = toupper(acuerdo);
        }


        if(acuerdo == 'S')
        {
            estaDeAcuerdo = true;
            opcFormato = 'P';
        }
        else
            estaDeAcuerdo = false;

        if(estaDeAcuerdo)
        {
            GestorDeArchivos* archi;

            archi = new ArchivosPNM;


            archi->guardar(img);
        }else
        {
            cout<<"\n\t|__No se pudo guardar la Imagen.";
            cout.flush();
        }

    }

    GestorDeArchivos *archi;

    if(opcFormato == 'A')
    {
        archi = new ArchivosAIC;

        archi->guardar(img);
    }else
    {
        archi = new ArchivosPNM;

        archi->guardar(img);
    }


}

string EspacioDeTrabajo::getNombreArchivo(string ruta)
{
    return ruta.substr(ruta.rfind('/')+1);

}






