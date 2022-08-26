#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H

#include <string>


#include "graficador.h"
#include "archivosaic.h"
#include "archivospnm.h"



class EspacioDeTrabajo
{
public:
    EspacioDeTrabajo();

    void ejecutar(QApplication *a);

    void cargarCarpetas();

    vector<int> devuelveOpciones();


private:
    string raiz="./Imagenes/";

    vector<string> carpetas;

    vector<string> carpeta_1;
    vector<string> carpeta_2;
    vector<string> carpeta_3;
    vector<string> carpeta_4;
    vector<string> carpeta_5;
protected:

};

#endif // ESPACIODETRABAJO_H
