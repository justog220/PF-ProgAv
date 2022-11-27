#include "espaciodetrabajo.h"
#include <algorithm>
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
    system("clear");
    char opcFormato;
    cout<<">[P]NM\n>[A]IC\nSeleccione el formato de guardado:";
    cin>>opcFormato;

    opcFormato= toupper(opcFormato);

    while (opcFormato != 'P' and opcFormato != 'A') {
        cout<<"\nInserte una opcion valida: ";
        cin>>opcFormato;
    }

    GestorDeArchivos* archi;

    if(opcFormato == 'P')
        archi = new ArchivosPNM;
    else
        archi = new ArchivosAIC;

    archi->guardar(img);
}

string EspacioDeTrabajo::getNombreArchivo(string ruta)
{
    return ruta.substr(ruta.rfind('/')+1);

}






