#include "archivosaic.h"
#include <cstring>

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
        try{
            string linea;

            getline(archi, linea);

            identificador = linea.substr(0, 3);

            img.setIdentificador(identificador);
            getline(archi, linea);

            int auxPosicion = 0;
            while(linea[0]=='#')
            {
                img.setInformacion(linea);
                 auxPosicion = archi.tellg();
                getline(archi, linea);
            }

            Pixel pixAux;


            archi.seekg(auxPosicion);

            unsigned int filas = 0;

            unsigned int acumuladorColumnas = 0;

            bool seGuardoColumnas = false;

            vector<int> datosLinea;

            while(!archi.eof())
            {
                getline(archi, linea);

                if(!seGuardoColumnas)
                {
                    int tamanio = linea.length();
                    char lineaChar[tamanio];
                    strcpy(lineaChar, linea.c_str());
                    char *split;
                    split = strtok(lineaChar, " ");
                    while (split != NULL)
                      {
                        datosLinea.push_back(stoi(split));
                        split = strtok (NULL, " ");
                      }
                    for(uint i=0; i < datosLinea.size(); i++)
                        if ((i+1)%2 == 0)
                            acumuladorColumnas += datosLinea[i];
                    seGuardoColumnas = true;
                }

                ++filas;
            }

            img.setFilas(filas);
            img.setColumnas(acumuladorColumnas);
            img.setTamanio();
            img.setRango(255);

            archi.close();

            archi.open(ruta, ios::in);

            archi.seekg(auxPosicion);

            filas = 0;
            acumuladorColumnas = 0;
            int nivelDeGris, cantidadRepite;

            Pixel pixelAux;

            int contadorPixeles = 0;
            while(getline(archi, linea))
            {
                datosLinea.clear();

                acumuladorColumnas = 0;

                int tamanio = linea.length();
                char lineaChar[tamanio];
                strcpy(lineaChar, linea.c_str());
                char *split;
                split = strtok(lineaChar, " ");
                while (split != NULL)
                  {
                    datosLinea.push_back(stoi(split));
                    split = strtok (NULL, " ");
                  }

                for(uint i = 0; i < datosLinea.size(); i = i+2)
                {
                    nivelDeGris = datosLinea.at(i);
                    cantidadRepite = datosLinea.at(i+1);
                    for(int columna = 0; columna < cantidadRepite; columna++)
                    {
                        pixelAux.setPixelEscala(nivelDeGris);
                        img.setPixel(filas, columna+acumuladorColumnas, pixelAux);
                        contadorPixeles += 1;
                    }
                    acumuladorColumnas += cantidadRepite;


                }
                ++filas;
            }

            if (contadorPixeles != img.getFilas()*img.getColumnas())
                throw ExcepcionArchivoCorrupto();

            return img;
    } catch(exception){
        throw ExcepcionArchivoCorrupto();
    }

    }
}

void ArchivosAIC::guardar(Imagen *img)
{
    string ruta = obtieneRutaGuardado();
    archi.open(ruta, ios::out);

    if(!archi.is_open())
    {
        cout<<"No se pudo abrir el archivo.";
    }else{
        escribirEncabezado(img);

        escribirPixeles(img, ruta);
    }
}

string ArchivosAIC::obtieneRutaGuardado()
{
    string rutaGuardado = "./Imagenes/Imagenes_guardadas/", nombre;
    cout<<"\t  Ingrese nombre con el que desea guardar la imágen. (No utilice '/')\n\t\t>";
    cin>>nombre;

    return rutaGuardado+nombre+".aic";
}

void ArchivosAIC::escribirPixeles(Imagen *img, string ruta)
{
    archi.open(ruta, ios::out | ios::app);

    int nivelDeGris, cantidadQueSeRepite, intensidadAnterior, acumuladorColumnas;

    for (int fila = 0; fila < img->getFilas(); fila++)
    {
        acumuladorColumnas = 0;
        intensidadAnterior = img->getPixel(fila, 0).getIntensidad();
        cantidadQueSeRepite = 0;

        for (int columna = 0; columna < img->getColumnas(); columna++)
        {
            if (img->getPixel(fila, columna).getIntensidad() != intensidadAnterior)
            {
                archi<<nivelDeGris<<" "<<cantidadQueSeRepite<<" ";
                acumuladorColumnas += cantidadQueSeRepite;
                nivelDeGris = img->getPixel(fila, columna).getIntensidad();
                intensidadAnterior = nivelDeGris;
                cantidadQueSeRepite = 1;
            }
            else
            {
                nivelDeGris = img->getPixel(fila, columna).getIntensidad();
                cantidadQueSeRepite += 1;
            }
        }
        if (acumuladorColumnas != img->getColumnas())
        {
            archi<<nivelDeGris<<" "<<cantidadQueSeRepite;
        }
        if (fila != img->getFilas()-1)
            archi<<"\n";
    }

    archi.close();
}


void ArchivosAIC::escribirEncabezado(Imagen *img)
{
    archi<<img->getIdentificador()<<"\n";
    archi<<img->getInformacion()<<"\n";

    archi.close();
}
