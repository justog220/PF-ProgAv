#include "tablalut.h"

TablaLut::TablaLut(int opcion)
{
    cargarLUT(opcion);
}

Pixel TablaLut::pseudoColorear(int intensidad)
{
    return Pixel(tablaConversion[intensidad][1], tablaConversion[intensidad][2], tablaConversion[intensidad][3]);
}

void TablaLut::cargarLUT(int opc)
{
    tablaConversion.resize(256);
    for (int i = 0; i < tablaConversion.size(); i++)
         tablaConversion[i].resize(4);

    ifstream lut;
    lut.open(luts[opc-1]);

    string linea;

    getline(lut, linea);

    for (int i = 0; i < tablaConversion.size(); i++)
    {
        lut>>tablaConversion[i][0]>>tablaConversion[i][1]>>tablaConversion[i][2]>>tablaConversion[i][3];
    }

}
