/*!
 *  \class      Sistema
 *  \brief      Clase capaz de ejecutar el sistema de procesamiento de imagenes.
 *  \details    Es cappaz de ejecutar las diferentes acciones que son necesarias para
 *              el funcionamiento del software. Tiene un espacio de Trabajo y un Graficador
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef SISTEMA_H
#define SISTEMA_H

#include "espaciodetrabajo.h"
#include "graficador.h"

class Sistema
{
public:
    Sistema();

    void ejecutar(QApplication *a);

    void mostrarAtajos();

private:
    EspacioDeTrabajo espDeTrabajo;
    Graficador graf;
};

#endif // SISTEMA_H
