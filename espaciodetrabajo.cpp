#include "espaciodetrabajo.h"

EspacioDeTrabajo::EspacioDeTrabajo()
{

}

void EspacioDeTrabajo::ejecutar(QApplication *a)
{
    cargarCarpetas();

    Graficador graf;
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

    switch(opcDir)
    {
    case 1:
        cout<<"\n\n\n";
        for(unsigned int i=0; i<carpeta_1.size(); i++)
            cout<<i+1<<")"<<carpeta_1[i]<<endl;
        cout<<"\n\n\nSeleccione el archivo: ";
        cin>>opcArch;
        break;
    case 2:
        cout<<"\n\n\n";
        for(unsigned int i=0; i<carpeta_2.size(); i++)
            cout<<i+1<<")"<<carpeta_2[i]<<endl;
        cout<<"\n\n\nSeleccione el archivo: ";
        cin>>opcArch;
        break;
    case 3:
        cout<<"\n\n\n";
        for(unsigned int i=0; i<carpeta_3.size(); i++)
            cout<<i+1<<")"<<carpeta_3[i]<<endl;
        cout<<"\n\n\nSeleccione el archivo: ";
        cin>>opcArch;
        break;
    case 4:
        cout<<"\n\n\n";
        for(unsigned int i=0; i<carpeta_4.size(); i++)
            cout<<i+1<<")"<<carpeta_4[i]<<endl;
        cout<<"\n\n\nSeleccione el archivo: ";
        cin>>opcArch;
        break;
    case 5:
        cout<<"\n\n\n";
        for(unsigned int i=0; i<carpeta_5.size(); i++)
            cout<<i+1<<")"<<carpeta_5[i]<<endl;
        cout<<"\n\n\nSeleccione el archivo: ";
        cin>>opcArch;
        break;
    }

    graf.setOpciones(opcDir, opcArch);

    graf.cargarImagen();

    graf.show();

    a->exec();
}

void EspacioDeTrabajo::cargarCarpetas()
{
    carpetas.push_back("grupo_imagenes_1/");
    carpetas.push_back("grupo_imagenes_2/");
    carpetas.push_back("grupo_imagenes_3_corruptas/");
    carpetas.push_back("grupo_imagenes_4_nuevas/");
    carpetas.push_back("grupo_imagenes_5/");


    carpeta_1.push_back("entre_rios_03.ppm");
    carpeta_1.push_back("entre_rios_04.pgm");
    carpeta_1.push_back("hospital-robot_01.pgm");
    carpeta_1.push_back("test_01.pgm");
    carpeta_1.push_back("test_02.ppm");
    carpeta_1.push_back("tigre_01.pgm");

    carpeta_2.push_back("entre_rios_01.pgm");
    carpeta_2.push_back("entre_rios_02.ppm");
    carpeta_2.push_back("predio_fi_uner_01.ppm");
    carpeta_2.push_back("predio_fi_uner_01_0.961mXpixel_con_mucho_ruido.ppm");
    carpeta_2.push_back("predio_fi_uner_01_0.961mXpixel_con_ruido.ppm");

    carpeta_3.push_back("imagen_corrupta_01.pgm");
    carpeta_3.push_back("imagen_corrupta_02.pgm");

    carpeta_4.push_back("fif.aic");
    carpeta_4.push_back("gigjij.aic");
    carpeta_4.push_back("PICHITI.aic");
    carpeta_4.push_back("pipicucu.aic");
    carpeta_4.push_back("pruebafinal.aic");
    carpeta_4.push_back("testP1.pbm");
    carpeta_4.push_back("testP2.pgm");
    carpeta_4.push_back("testP3.pgm");
    carpeta_4.push_back("testP4.pbm");
    carpeta_4.push_back("testP5.pgm");
    carpeta_4.push_back("testP6.ppm");



}





