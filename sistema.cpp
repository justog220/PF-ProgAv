#include "sistema.h"

Sistema::Sistema()
{
    graf.setEspacio(espDeTrabajo);
}

void Sistema::ejecutar(QApplication *a)
{
    ArchivosPNM archi;

    Imagen img;

    bool seGraficoUnaImagen = false;
    while(true)
    {
        int opcDir = obtenerOpcDir();

        if(opcDir == espDeTrabajo.getCarpetas().size()+1)
        {
            vector<int> opciones = recuperarOpciones();

            if(opciones[0] != -10 and opciones[1] != -10)
            {
                mostrarAtajos();

                iniciarGraficacion(a, opciones[0], opciones[1]);
            }else{
                noSoportoAnterior = true;
                system("clear");
                cout<<"No se pudo recuperar la ejecución previa dado que no se graficó ninguna imágen.\n";
            }



        }else if(opcDir == espDeTrabajo.getCarpetas().size()+2)
        {
            break;
        }else{
            string ruta = espDeTrabajo.getRuta(opcDir);

            int opcArch = obtenerOpcArch(ruta);

            if (opcArch != -1)
            {
                mostrarAtajos();

                iniciarGraficacion(a, opcDir, opcArch);

                seGraficoUnaImagen = true;
            }
        }
    }

    if (!seGraficoUnaImagen)
        espDeTrabajo.llevarRegistro(-10, -10);


}

int Sistema::obtenerOpcDir()
{

    if(noSoportoAnterior == false)
        system("clear");

    unsigned int opcDir;

    vector<string> opcCarpetas = espDeTrabajo.getCarpetas();

    for(int i = 0; i < opcCarpetas.size(); i++)
        cout<<i+1<<") "<<opcCarpetas[i]<<"\n";

    cout<<opcCarpetas.size()+1<<") Recuperar ultima ejecucion\n";
    cout<<opcCarpetas.size()+2<<") Cerrar el programa\n";

    cout<<"Seleccione la opcion: ";

    cin>>opcDir;

    while(opcDir < 1 or opcDir > opcCarpetas.size()+2)
    {
        cout<<"\nIngrese una opcion valida: ";

        cin>>opcDir;
    }

    return opcDir;
}



int Sistema::obtenerOpcArch(string ruta)
{
    system("clear");

    unsigned int opcArch;

    vector<string> listaDeArchivos = espDeTrabajo.getListaDeArchivos(ruta);

    for(unsigned int i=0; i<listaDeArchivos.size(); i++)
        cout<<i+1<<") "<<listaDeArchivos[i]<<"\n";
    cout<<listaDeArchivos.size()+1<<") Volver a la seleccion de carpetas\n";

    cout<<"Seleccione una opcion: ";

    cin>>opcArch;

    while(opcArch < 1 or opcArch > listaDeArchivos.size()+2)
    {
        if(typeid (opcArch).name() == "unsigned int")
        {
        cout<<"\nIngrese una opcion valida: ";

        cin>>opcArch;
        }else{
            while(typeid (opcArch).name() != "unsigned int")
            {
                opcArch = 0;
                cout<<"\nIngrese un numero válido: ";

                cin>>opcArch;
            }

        }
    }

    if (opcArch == listaDeArchivos.size()+1)
    {
        noSoportoAnterior = false;
        return -1;
    }


    return opcArch;
}

void Sistema::iniciarGraficacion(QApplication *a, int opcDir, int opcArch)
{
    graf.setOpciones(opcDir, opcArch);

    try {
        graf.cargarImagen();

        graf.setApp(a);

        graf.show();

        noSoportoAnterior = false;


        a->exec();


    }  catch (ExcepcionArchivoNoSoportado &excepcion) {
        system("clear");
        a->closeAllWindows();
        noSoportoAnterior = true;
        cout<<excepcion.what()<<endl;
    } catch (ExcepcionArchivoCorrupto &excepcion) {
        system("clear");
        a->closeAllWindows();
        noSoportoAnterior = true;
        cout<<excepcion.what()<<endl;
    }

}

vector<int> Sistema::recuperarOpciones()
{
    vector<int> dir_arch(2);
    ifstream archi;
    archi.open("registro.txt");

    string ruta;

    archi>>dir_arch[0] >> dir_arch[1];

    archi.close();

    return dir_arch;
}

void Sistema::mostrarAtajos()
{
    system("clear");

    ifstream archi;
    archi.open("lista_de_atajos.txt");

    string linea;

    if(!archi.is_open())
    {

        cout<<"No se pudo abrir la lista de atajos";
    }
    else
    {
        while(!archi.eof()){
            getline(archi, linea);
            cout<<linea<<endl;
        }
    }
}

void Sistema::apagar()
{
    corriendo = false;
}



