#include "archivospnm.h"

ArchivosPNM::ArchivosPNM()
{

}

Imagen ArchivosPNM::leer(string ruta)
{
    Imagen img;
    archi.open(ruta, ios::in);

    if(!archi.is_open()){
        cout<<"Error al abrir la imagen."<<endl;
        cout<<ruta;
    }else{
        getline(archi, identificador);

        img.setIdentificador(identificador);
        char num_id;
        num_id=identificador[1];

        string comentario;
        int filas_aux, columnas_aux;

        int contador_pixeles = 0;
        bool fuera_de_rango = false;

        int pos_com = archi.tellg();

        getline(archi, comentario);

        if(comentario[0] != '#' and comentario[0] != '\n')
        {
            archi.seekg(pos_com);
        }else {
            img.setInformacion(comentario);
        }

        archi>>columnas_aux>>filas_aux;

        if (columnas_aux == 0 or filas_aux == 0)
            throw ExcepcionArchivoCorrupto();

        img.setFilas(filas_aux);
        img.setColumnas(columnas_aux);

        img.setTamanio();


        if(num_id!=1 and num_id!=4)
        {
            int rango_aux;
            archi>>rango_aux;
            img.setRango(rango_aux);
        }

        Pixel pix_aux;

        string linea;

        unsigned char r, g, b;

        int intEscala;

        int pos_final;

        switch(num_id)
        {
        case '1':
            getline(archi, linea,'\n');
            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                  archi>>intEscala;
                  pix_aux.setPixelMonocr((int)intEscala);
                  img.setPixel(j, i, pix_aux);
                  contador_pixeles++;
                }
            }
            archi.close();
            break;
        case '2':
            getline(archi, linea,'\n');
            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                   archi>>intEscala;
                   if((int)intEscala>img.getRango())
                       throw ExcepcionArchivoCorrupto();
                   pix_aux.setPixelEscala((int)intEscala);
                   img.setPixel(j, i, pix_aux);
                   contador_pixeles++;

                }
            }
            archi.close();
            break;
        case '3':
            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                    archi>>r>>g>>b;
                    if((int)r>img.getRango() or (int)g>img.getRango() or (int)b>img.getRango())
                        throw ExcepcionArchivoCorrupto();
                    pix_aux.setPixelRGB((int)r, (int)g, (int)b);
                    img.setPixel(j, i, pix_aux);
                    contador_pixeles++;
                }
            }
            archi.close();
            break;
        case '4':


            getline(archi, linea, '\n');

            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                    archi.read((char*)&r, sizeof(r));
                    pix_aux.setPixelMonocr((int)r);
                    img.setPixel(j, i, pix_aux);
                    contador_pixeles++;
                }
            }
            archi.close();
            break;
        case '5':


            getline(archi, linea, '\n');

            pos_final = archi.tellg();

            archi.close();
            archi.open(ruta, ios::in | ios::binary);

            archi.seekg(pos_final);

            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                    archi.read((char*)&r, sizeof(r));

                    if((int)r>img.getRango())
                        throw ExcepcionArchivoCorrupto();

                    pix_aux.setPixelEscala((int)r);
                    img.setPixel(j, i, pix_aux);
                    contador_pixeles++;
                }
            }
            archi.close();
            break;
        case '6':


            getline(archi, linea, '\n');

            pos_final = archi.tellg();

            archi.close();
            archi.open(ruta, ios::in | ios::binary);

            archi.seekg(pos_final);

            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                    archi.read((char*)&r, sizeof(r));

                    archi.read((char*)&g, sizeof(g));

                    archi.read((char*)&b, sizeof(b));

                    if((int)r>img.getRango() or (int)g>img.getRango() or (int)b>img.getRango())
                        throw ExcepcionArchivoCorrupto();

                    pix_aux.setPixelRGB((int)r, (int)g, (int)b);

                    img.setPixel(j, i, pix_aux);
                    contador_pixeles++;
                    }
                }

            archi.close();

            break;


        }

        if(contador_pixeles != filas_aux*columnas_aux)
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
    }else{

        escribeEncabezado(rutaGuardado, img);

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


void ArchivosPNM::escribeEncabezado(string rutaEscritura, Imagen *img)
{
    string id = img->getIdentificador();

    archi<<id<<"\n";

    char num_id;
    num_id=id[1];

    archi<<img->getInformacion()<<"\n";

    int filas_aux = img->getFilas(), columnas_aux = img->getColumnas();

    archi<<columnas_aux<<" "<<filas_aux<<endl;

    if(num_id!=1 and num_id!=4)
    {
        int rango_aux = img->getRango();
        archi<<rango_aux<<endl;
    }

    archi.close();
}

void ArchivosPNM::escribeP1(string rutaEscritura, Imagen *img)
{
//    archi.open(rutaEscritura, ios::out | ios::app);

//    Pixel pix_aux;

//    unsigned char intEscala;

//    int filas_aux = img->getFilas(), columnas_aux = img->getColumnas();

//    for(int i=0; i<filas_aux; i++)
//    {
//        for(int j=0; j<columnas_aux-1; j++)
//        {
//          pix_aux = img->getPixel(i, j);
//          intEscala = pix_aux.getR();
//          archi<<intEscala<<" ";
//        }
//        pix_aux = img->getPixel(columnas_aux, j);
//        intEscala = pix_aux.getR();
//        archi<<intEscala<<" ";
//        archi<<endl;
//    }
//    archi.close();
}

void ArchivosPNM::escribeP2(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::app);

    Pixel pix_aux;

    unsigned char intEscala;

    int filas_aux = img->getFilas(), columnas_aux = img->getColumnas();

    for(int j=0; j<filas_aux-1; j++)
    {
        for(int i=0; i<columnas_aux-1; i++)
        {
           pix_aux = img->getPixel(i, j);
           intEscala = pix_aux.getR();
           archi<<intEscala;
        }
        archi<<endl;
    }
    archi.close();
}

void ArchivosPNM::escribeP3(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::app);

    Pixel pix_aux;

    unsigned char r, g, b;

    int filas_aux = img->getFilas(), columnas_aux = img->getColumnas();

    for(int j=0; j<filas_aux; j++)
    {
        for(int i=0; i<columnas_aux; i++)
        {
            pix_aux = img->getPixel(i, j);
            r = pix_aux.getR();
            g = pix_aux.getG();
            b = pix_aux.getB();
            archi<<r<<g<<b;
        }
        archi<<endl;
    }
    archi.close();
}

void ArchivosPNM::escribeP4(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::binary |ios::app);

    int filas_aux = img->getFilas(), columnas_aux = img->getColumnas();

    unsigned char escala;

    Pixel pix_aux;

    for(int j=0; j<filas_aux; j++)
    {
        for(int i=0; i<columnas_aux; i++)
        {
            pix_aux = img->getPixel(i, j);
            escala = pix_aux.getR();
            archi.write((char*)&escala, sizeof(escala));
        }
    }
    archi.close();
}

void ArchivosPNM::escribeP5(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::binary |ios::app);

    int filas_aux = img->getFilas(), columnas_aux = img->getColumnas();

    unsigned char escala;

    Pixel pix_aux;

    for(int i=0; i<filas_aux; i++)
    {
        for(int j=0; j<columnas_aux; j++)
        {
            pix_aux = img->getPixel(i, j);

            escala = (unsigned char)pix_aux.getR();

            archi.write((char*)&(escala), sizeof(escala));
        }
    }

    archi.close();
}

void ArchivosPNM::escribeP6(string rutaEscritura, Imagen *img)
{
    archi.open(rutaEscritura, ios::out | ios::binary | ios::app);

    int filas_aux = img->getFilas(), columnas_aux = img->getColumnas();

    unsigned char r, g, b;

    Pixel pix_aux;

    for(int i=0; i<filas_aux; i++)
    {
        for(int j=0; j<columnas_aux; j++)
        {

            pix_aux = img->getPixel(i, j);

            r = (unsigned char)pix_aux.getR();

            g = (unsigned char)pix_aux.getG();

            b = (unsigned char)pix_aux.getB();

            archi.write((char*)&r, sizeof(r));

            archi.write((char*)&g, sizeof(g));

            archi.write((char*)&b, sizeof(b));
        }
    }
    archi.close();
}

string ArchivosPNM::obtieneRutaGuardado(string idImagen)
{
    system("clear");

    string rutaGuardado = "./Imagenes/Imagenes_guardadas/", nombre;
    cout<<"Ingrese nombre con el que desea guardar la imágen. (No utilice '/')\n";
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
