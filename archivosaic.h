/*!
 *  \class      ArchivosAIC
 *  \brief      Clase capaz de gestionar los diferentes tipos de archivos AIC.
 *  \details    Hereda de GestorDeArchivos la capacidad de leer un archivo y de guardar otro.
 *              Tiene un archivo y almacena el identificador del tipo de archivo una vez que fue leido.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug        No deberia conocerse de ante mano el tipo de archivo para asi implementar el polimorfismo?
 *  \warning    No se ha implementado ni testeado el guardar.
*/
#ifndef ARCHIVOSAIC_H
#define ARCHIVOSAIC_H
#include "gestordearchivos.h"
#include <fstream>


class ArchivosAIC : public GestorDeArchivos
{
public:
    ArchivosAIC();

    Imagen leer(string ruta) override;

    void guardar(string ruta, Imagen *img) override;

private:
    fstream archi;
};

#endif // ARCHIVOSAIC_H
