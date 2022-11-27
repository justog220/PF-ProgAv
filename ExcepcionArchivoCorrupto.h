#ifndef EXCEPCIONARCHIVOCORRUPTO_H
#define EXCEPCIONARCHIVOCORRUPTO_H

#include <stdexcept>

using namespace std;

class ExcepcionArchivoCorrupto : public runtime_error
{
public:
    ExcepcionArchivoCorrupto()
     : runtime_error( "Archivo corrupto, no se pudo leer la imagen. Seleccione otro\n" ) {}
};

#endif // EXCEPCIONARCHIVOCORRUPTO_H
