#ifndef EXCEPCIONARCHIVONOSOPORTADO_H
#define EXCEPCIONARCHIVONOSOPORTADO_H
#include <stdexcept>

using namespace std;

class ExcepcionArchivoNoSoportado : public runtime_error
{
public:
    ExcepcionArchivoNoSoportado()
     : runtime_error( "Archivo no soportado por el software. Seleccione otro\n" ) {}
};

#endif // EXCEPCIONARCHIVONOSOPORTADO_H
