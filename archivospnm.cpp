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
        char num_id;
        num_id=identificador[1];

        string comentario;
        int filas_aux, columnas_aux;

        getline(archi, comentario);

        archi>>columnas_aux>>filas_aux;

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
                  pix_aux.setPixelMonocr((float)intEscala);
                  img.setPixel(j, i, pix_aux);
                }
            }
            break;
        case '2':
            getline(archi, linea,'\n');
            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                   archi>>intEscala;
                   pix_aux.setPixelEscala((float)intEscala);
                   img.setPixel(j, i, pix_aux);

                }
            }
            break;
        case '3':
            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                    archi>>r>>g>>b;
                    pix_aux.setPixelRGB((float)r, (float)g, (float)b);
                    img.setPixel(j, i, pix_aux);
                }
            }
            break;
        case '4':


            getline(archi, linea, '\n');

            for(int j=0; j<filas_aux; j++)
            {
                for(int i=0; i<columnas_aux; i++)
                {
                    archi.read((char*)&r, sizeof(r));
                    pix_aux.setPixelMonocr((float)r);
                    img.setPixel(j, i, pix_aux);
                }
            }
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
                    pix_aux.setPixelEscala((float)r);
                    img.setPixel(j, i, pix_aux);
                }
            }
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

                    pix_aux.setPixelRGB((float)r, (float)g, (float)b);

                    img.setPixel(j, i, pix_aux);
                    }
                }

            archi.close();

            break;


    }

    }
    return img;
}

void ArchivosPNM::guardar(string ruta, Imagen *img)
{

}
