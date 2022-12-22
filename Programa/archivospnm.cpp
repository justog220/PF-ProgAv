#include "archivospnm.h"

ArchivosPNM::ArchivosPNM()
{

}

Imagen ArchivosPNM::leer(string ruta)
{
    Imagen img;
    archi.open(ruta, ios::in);

    if(!archi.is_open())
    {
        cout<<"Error al abrir la imagen."<<endl;
        cout<<ruta;
    }
    else
    {
        getline(archi, identificador);

        img.setIdentificador(identificador);

        string comentario;
        int filasAux, columnasAux;

        int contadorPixeles = 0;

        int posCom = archi.tellg();

        getline(archi, comentario);

        if(comentario[0] != '#' and comentario[0] != '\n')
        {
            archi.seekg(posCom);
        }else {
            img.setInformacion(comentario);
        }

        archi>>columnasAux>>filasAux;

        if (columnasAux == 0 or filasAux == 0)
            throw ExcepcionArchivoCorrupto();

        img.setFilas(filasAux);
        img.setColumnas(columnasAux);

        img.setTamanio();

        if(identificador[1]!=1 and identificador[1]!=4)
        {
            int rangoAux;
            archi>>rangoAux;
            img.setRango(rangoAux);
        }

        Pixel pixAux;

        string linea;

        unsigned char r, g, b;


        int intEscala;

        int posFinal;

        switch(identificador[1])
        {
        case '1':
            img.setRango(1);
            for(int fila=0; fila<filasAux; fila++)
            {
                for(int columna=0; columna<columnasAux; columna++)
                {
                  archi>>intEscala;

                  if((int)intEscala>img.getRango())
                      throw ExcepcionArchivoCorrupto();

                  pixAux.setPixelMonocr((int)intEscala);
                  img.setPixel(fila, columna, pixAux);
                  contadorPixeles++;
                }
            }
            archi.close();
            break;
        case '2':
            for(int fila=0; fila<filasAux; fila++)
            {
                for(int columna=0; columna<columnasAux; columna++)
                {
                   archi>>intEscala;
                   if((int)intEscala>img.getRango())
                       throw ExcepcionArchivoCorrupto();
                   pixAux.setPixelEscala((int)intEscala);
                   img.setPixel(fila, columna, pixAux);
                   contadorPixeles++;

                }
            }
            archi.close();
            break;
        case '3':
            int R, G, B;
            for(int fila=0; fila<filasAux; fila++)
            {
                for(int columna=0; columna<columnasAux; columna++)
                {
                    archi>>R>>G>>B;
                    if(R>img.getRango() or G>img.getRango() or B>img.getRango())
                        throw ExcepcionArchivoCorrupto();

                    pixAux.setPixelRGB(R, G, B);
                    img.setPixel(fila, columna, pixAux);
                    contadorPixeles++;
                }
            }
            archi.close();
            break;
        case '4':
            img.setRango(1);
            for(int fila=0; fila<filasAux; fila++)
            {
                for(int columna=0; columna<columnasAux; columna++)
                {
                    archi.read((char*)&r, sizeof(r));

                    if((int)r>img.getRango())
                        throw ExcepcionArchivoCorrupto();

                    pixAux.setPixelMonocr((int)r);
                    img.setPixel(fila, columna, pixAux);
                    contadorPixeles++;
                }
            }
            archi.close();
            break;
        case '5':
            getline(archi, linea, '\n');

            posFinal = archi.tellg();

            archi.close();
            archi.open(ruta, ios::in | ios::binary);

            archi.seekg(posFinal);

            for(int fila=0; fila<filasAux; fila++)
            {
                for(int columna=0; columna<columnasAux; columna++)
                {
                    archi.read((char*)&r, sizeof(r));

                    if((int)r>img.getRango())
                        throw ExcepcionArchivoCorrupto();

                    pixAux.setPixelEscala((int)r);
                    img.setPixel(fila, columna, pixAux);
                    contadorPixeles++;
                }
            }
            archi.close();
            break;
        case '6':


            getline(archi, linea, '\n');

            posFinal = archi.tellg();

            archi.close();
            archi.open(ruta, ios::in | ios::binary);

            archi.seekg(posFinal);

            for(int fila=0; fila<filasAux; fila++)
            {
                for(int columna=0; columna<columnasAux; columna++)
                {
                    archi.read((char*)&r, sizeof(r));

                    archi.read((char*)&g, sizeof(g));

                    archi.read((char*)&b, sizeof(b));

                    if((int)r>img.getRango() or (int)g>img.getRango() or (int)b>img.getRango())
                        throw ExcepcionArchivoCorrupto();

                    pixAux.setPixelRGB((int)r, (int)g, (int)b);

                    img.setPixel(fila, columna, pixAux);
                    contadorPixeles++;
                    }
                }

            archi.close();

            break;


        }

        if(contadorPixeles != filasAux*columnasAux)
            throw ExcepcionArchivoCorrupto();

    }
    return img;
}

void ArchivosPNM::guardar(Imagen *img)
{
    string id = img->getIdentificador();

    string rutaGuardado = obtieneRutaGuardado(id);


    archi.open(rutaGuardado, ios::out);

    if(!archi.is_open()){
        cout<<"Error al abrir la imagen."<<endl;
        cout<<rutaGuardado;
    }
    else
    {

        escribeEncabezado(img);

        switch(id[1])
        {
        case '1':
            escribeP1(rutaGuardado, img);
            break;
        case '2':
            escribeP2(rutaGuardado, img);
            break;
        case '3':
            escribeP3(rutaGuardado, img);
            break;
        case '4':
            escribeP4(rutaGuardado, img);
            break;
        case '5':
            escribeP5(rutaGuardado, img);
            break;
        case '6':
            escribeP6(rutaGuardado, img);
            break;
        }

    }


}


void ArchivosPNM::escribeEncabezado(Imagen *img)
{
    string id = img->getIdentificador();

    archi<<id<<"\n";

    char numId;
    numId=id[1];

    archi<<img->getInformacion()<<"\n";

    int filasAux = img->getFilas(), columnasAux = img->getColumnas();

    archi<<columnasAux<<" "<<filasAux<<endl;

    if(numId!=1 and numId!=4)
    {
        int rangoAux = img->getRango();
        archi<<rangoAux<<endl;
    }

    archi.close();
}

void ArchivosPNM::escribeP1(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::app);

    Pixel pixAux;

    int intEscala;

    int filasAux = img->getFilas(), columnasAux = img->getColumnas();

    for(int fila=0; fila<filasAux; fila++)
    {
        for(int columna=0; columna<columnasAux; columna++)
        {
          pixAux = img->getPixel(fila, columna);
          intEscala = pixAux.getR();
          if(intEscala == 1)
              intEscala = 0;
          else
              intEscala = 1;
          archi<<intEscala<<" ";
        }
        archi<<"\n";
    }
    archi.close();
}

void ArchivosPNM::escribeP2(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::app);

    Pixel pixAux;

    int intEscala;

    int filasAux = img->getFilas(), columnasAux = img->getColumnas();

    for(int fila=0; fila<filasAux; fila++)
    {
        for(int columna=0; columna<columnasAux; columna++)
        {
           pixAux = img->getPixel(fila, columna);
           intEscala = pixAux.getR();
           archi<<intEscala<<" ";
        }
        archi<<endl;
    }
    archi.close();
}

void ArchivosPNM::escribeP3(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::app);

    Pixel pixAux;

    unsigned char r, g, b;

    int filasAux = img->getFilas(), columnasAux = img->getColumnas();

    for(int fila=0; fila<filasAux; fila++)
    {
        for(int columna=0; columna<columnasAux; columna++)
        {
            pixAux = img->getPixel(columna, fila);
            r = pixAux.getR();
            g = pixAux.getG();
            b = pixAux.getB();
            archi<<r<<g<<b;
        }
        archi<<endl;
    }
    archi.close();
}

void ArchivosPNM::escribeP4(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::binary |ios::app);

    int filasAux = img->getFilas(), columnasAux = img->getColumnas();

    unsigned char escala;

    Pixel pixAux;

    for(int fila=0; fila<filasAux; fila++)
    {
        for(int columna=0; columna<columnasAux; columna++)
        {
            pixAux = img->getPixel(fila, columna);
            escala = pixAux.getR();
            archi.write((char*)&escala, sizeof(escala));
        }
    }
    archi.close();
}

void ArchivosPNM::escribeP5(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::binary |ios::app);

    int filasAux = img->getFilas(), columnasAux = img->getColumnas();

    unsigned char escala;

    Pixel pixAux;

    for(int fila=0; fila<filasAux; fila++)
    {
        for(int columna=0; columna<columnasAux; columna++)
        {
            pixAux = img->getPixel(fila, columna);

            escala = (unsigned char)pixAux.getR();

            archi.write((char*)&(escala), sizeof(escala));
        }
    }

    archi.close();
}

void ArchivosPNM::escribeP6(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::binary | ios::app);

    int filasAux = img->getFilas(), columnasAux = img->getColumnas();

    unsigned char r, g, b;

    Pixel pixAux;

    for(int fila=0; fila<filasAux; fila++)
    {
        for(int columna=0; columna<columnasAux; columna++)
        {

            pixAux = img->getPixel(fila, columna);

            r = (unsigned char)pixAux.getR();

            g = (unsigned char)pixAux.getG();

            b = (unsigned char)pixAux.getB();

            archi.write((char*)&r, sizeof(r));

            archi.write((char*)&g, sizeof(g));

            archi.write((char*)&b, sizeof(b));
        }
    }
    archi.close();
}

string ArchivosPNM::obtieneRutaGuardado(string idImagen)
{
    string rutaGuardado = "./Imagenes/Imagenes_guardadas/", nombre;
    cout<<"\t  Ingrese nombre con el que desea guardar la imágen. (No utilice '/')\n\t\t>";
    cin>>nombre;

    switch(idImagen[1])
    {
    case '1':
        nombre = nombre + ".pbm";
        break;
    case '2':
        nombre = nombre + ".pgm";
        break;
    case '3':
        nombre = nombre + ".ppm";
        break;
    case '4':
        nombre = nombre + ".pbm";
        break;
    case '5':
        nombre = nombre + ".pgm";
        break;
    case '6':
        nombre = nombre + ".ppm";
        break;
    }

    rutaGuardado = rutaGuardado + nombre;

    return rutaGuardado;
}
