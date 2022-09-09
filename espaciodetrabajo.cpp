#include "espaciodetrabajo.h"

EspacioDeTrabajo::EspacioDeTrabajo()
{

}


void EspacioDeTrabajo::cargarCarpetas()
{
    carpetas.push_back("grupo_imagenes_1/");
    carpetas.push_back("grupo_imagenes_2/");
    carpetas.push_back("grupo_imagenes_3_corruptas/");


}

vector<string> EspacioDeTrabajo::getListaDeArchivos(string ruta)
{
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

int EspacioDeTrabajo::getNroArchivos()
{
    return listaDeArchivos.size();
}






