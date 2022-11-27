/*!
 *  \class      ArchivosPNM
 *  \brief      Clase capaz de gestionar los diferentes tipos de archivos PNM.
 *  \details    Hereda de GestorDeArchivos la capacidad de leer un archivo y de guardar otro.
 *              Tiene un archivo y almacena el identificador del tipo de archivo una vez que fue leido.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug
 *  \warning    No se ha implementado ni testeado el guardar.
*/
#ifndef ARCHIVOSPNM_H
#define ARCHIVOSPNM_H
#include "gestordearchivos.h"
#include <fstream>

class ArchivosPNM : public GestorDeArchivos
{
public:
    /*!
     * \brief       ArchivosPNM Constructor del objeto ArchivosPNM.
     */
    ArchivosPNM();

    /*!
     * \brief       leer Se redefine el metodo heredado de GestorDeArchivos y que permite
     * leer imágenes de un archivo PNM.
     * \param[in]   ruta String, es la ruta desde la cuál se desea leer una imágen.
     * \return      Devuelve un objeto de tipo Imágen.
     */
    Imagen leer(string ruta) override;

    /*!
     * \brief       guardar Se redefine el método heredado de GestorDeArchivos y que permite guardar
     * imágenes en formato PNM.
     * \param[in]   img Puntero a un objeto Imágen que es la imágen a guardar.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void guardar(Imagen *img) override;

protected:
    /*!
     * \brief       escribeEncabezado Método protegido auxiliar para el guardado
     * de una imágen, permite escribir el encabezado de un archivo PNM.
     * \param[in]   rutaEscritura Ruta en la que se almacena la imágen.
     * \param[in]   img Imagen por referencia, es la que se almacena.
     */
    void escribeEncabezado(string rutaEscritura, Imagen *img);

    /*!
     * \brief       escribeP1 Método protegido auxiliar para el guardado
     * de una imágen, permite escribir una imágen, cuyo identificador es P1.
     * \param[in]   rutaEscritura Ruta en la que se almacena la imágen.
     * \param[in]   img Imagen por referencia, es la que se almacena.
     */
    void escribeP1(string rutaEscritura, Imagen *img);

    /*!
     * \brief       escribeP1 Método protegido auxiliar para el guardado
     * de una imágen, permite escribir una imágen, cuyo identificador es P2.
     * \param[in]   rutaEscritura Ruta en la que se almacena la imágen.
     * \param[in]   img Imagen por referencia, es la que se almacena.
     */
    void escribeP2(string rutaEscritura, Imagen *img);

    /*!
     * \brief       escribeP1 Método protegido auxiliar para el guardado
     * de una imágen, permite escribir una imágen, cuyo identificador es P3.
     * \param[in]   rutaEscritura Ruta en la que se almacena la imágen.
     * \param[in]   img Imagen por referencia, es la que se almacena.
     */
    void escribeP3(string rutaEscritura, Imagen *img);

    /*!
     * \brief       escribeP1 Método protegido auxiliar para el guardado
     * de una imágen, permite escribir una imágen, cuyo identificador es P4.
     * \param[in]   rutaEscritura Ruta en la que se almacena la imágen.
     * \param[in]   img Imagen por referencia, es la que se almacena.
     */
    void escribeP4(string rutaEscritura, Imagen *img);

    /*!
     * \brief       escribeP1 Método protegido auxiliar para el guardado
     * de una imágen, permite escribir una imágen, cuyo identificador es P5.
     * \param[in]   rutaEscritura Ruta en la que se almacena la imágen.
     * \param[in]   img Imagen por referencia, es la que se almacena.
     */
    void escribeP5(string rutaEscritura, Imagen *img);

    /*!
     * \brief       escribeP1 Método protegido auxiliar para el guardado
     * de una imágen, permite escribir una imágen, cuyo identificador es P6.
     * \param[in]   rutaEscritura Ruta en la que se almacena la imágen.
     * \param[in]   img Imagen por referencia, es la que se almacena.
     */
    void escribeP6(string rutaEscritura, Imagen *img);

private:
    /*! \param archi Archivo de entrada o sálida de
     * tipo PNM.
    */
    fstream archi;

    /*! \param identificador Parámetro que almacena el identificador del
     * archivo.
    */
    string identificador;


    /*!
     * \brief       obtieneRutaGuardado Método privado auxiliar para el guardado
     * de una imágen, permite consultarle al usuario el nombre, y por lo tanto la ruta en la que se guarda.
     * \param[in]   idImagen Identificador de la imágen a guardar para determinar su extensión.
     * \return      String que representa la ruta en la que se guardará.
     */
    string obtieneRutaGuardado(string idImagen);
};

#endif // ARCHIVOSPNM_H
