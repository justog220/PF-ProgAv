/*!
 *  \class      TablaLut
 *  \brief      Clase que permite representar una Imagen pseudocolreada con una tabla LUT.
 *  \details    Obtiene un nivel de intensidad, y en base a esto, devuelve el Pixel con el cual
 * debe ser representado.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 24-11-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef TABLALUT_H
#define TABLALUT_H

#include <vector>
#include <string>
#include <fstream>
#include "imagen.h"

using namespace std;

class TablaLut
{
public:
    /*!
     * \brief TablaLut Constructor de TablaLut
     * \param[in] opcion LUT q desea utilizarse.
     */
    TablaLut(int opcion);

    /*!
     * \brief pseudoColorear Método que permite a partir de la intensidad de un Pixel devolver el Pixel con el
     * cuál debe representarse
     * \param[in] intensidad Intensidad de un Pixel que se desea pseudocolorear.
     * \return Pixel pseudocoloreado a través de una intensidad.
     */
    Pixel pseudoColorear(int intensidad);

private:
    /*!
     * \param Vector de strings que almacena las rutas de las tablas LUT manejadas por el software. La posicion de las
     * rutas esta dada por la opcion del constructor - 1.
     */
    vector<string> luts = {"./grupo_luts/glow.lut", "./grupo_luts/Turbo.lut"};

    /*!
     * \param tabla_conversion Vector de enteros que representa la tabla de conversion[i][j] donde i representa la intensidad
     * que se desea pseudocolorear y j toma distintos valores, 1 si es R, 2 si es G y 3 si es B.
     */
    vector<vector<int>> tabla_conversion;

    /*!
     * \brief cargarLUT Método que permite cargar la tabla LUT desde un archivo.
     * \param[in] opc LUT que se desea utilizar.
     */
    void cargarLUT(int opc);
};

#endif // TABLALUT_H
