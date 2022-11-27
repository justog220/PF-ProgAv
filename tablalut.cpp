#include "tablalut.h"

TablaLut::TablaLut(int opcion)
{
    cargarLUT(opcion);
}

Pixel TablaLut::pseudoColorear(int intensidad)
{
    return Pixel(tabla_conversion[intensidad][1], tabla_conversion[intensidad][2], tabla_conversion[intensidad][3]);
}

void TablaLut::cargarLUT(int opc)
{
    tabla_conversion.resize(256);
    for (int i = 0; i < tabla_conversion.size(); i++)
         tabla_conversion[i].resize(4);

    ifstream lut;
    lut.open(luts[opc-1]);

    string linea;

    getline(lut, linea);

    for (int i = 0; i < tabla_conversion.size(); i++){
        lut>>tabla_conversion[i][0]>>tabla_conversion[i][1]>>tabla_conversion[i][2]>>tabla_conversion[i][3];
    }

}
