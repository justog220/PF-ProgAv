/*!
 *  \class      ArchivosAIC
 *  \brief      Clase capaz de gestionar los diferentes tipos de archivos AIC.
 *  \details    Hereda de GestorDeArchivos la capacidad de leer un archivo y de guardar otro.
 *              Tiene un archivo y almacena el identificador del tipo de archivo una vez que fue leido.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef ARCHIVOSAIC_H
#define ARCHIVOSAIC_H
#include "gestordearchivos.h"
#include <fstream>

using namespace std;

class ArchivosAIC : public GestorDeArchivos
{
public:
    /*!
     * \brief       ArchivosAIC Constructor del objeto ArchivosAIC.
     */
    ArchivosAIC();

    /*!
     * \brief       leer Se redefine el metodo heredado de GestorDeArchivos y que permite
     * leer imágenes de un archivo AIC.
     * \param[in]   ruta String, es la ruta desde la cuál se desea leer una imágen.
     * \return      Devuelve un objeto de tipo Imágen.
     */
    Imagen leer(string ruta) override;

    /*!
     * \brief       guardar Se redefine el método heredado de GestorDeArchivos y que permite guardar
     * imágenes en formato AIC.
     * \param[in]   img Puntero a un objeto Imágen que es la imágen a guardar.
     * \return      No devuelve nada, solo modifica los parámetros.
     */
    void guardar(Imagen *img) override;

private:
    /*! \param archi Archivo de entrada o salida
     * de tipo AIC.
    */
    fstream archi;

    /*! \param identificador Identificador del archivo, indica
     * como leerlo o guardarlo.
    */
    string identificador;

    /*!
     * \brief obtieneRutaGuardado Método que permite obtener del usuario
     * la ruta donde se guardará la imágen.
     * \return Ruta donde se guardará la Imagen.
     */
    string obtieneRutaGuardado();

    /*!
     * \brief escribirEncabezado Método privado que escribe el encabezado (Identificador + Info)
     * de una Imagen al ser guardada
     * \param[in] img Puntero a la Imagen guardada.
     */
    void escribirEncabezado(Imagen *img);

    /*!
     * \brief escribirPixeles Método privado que escribe los Pixel de la Imagen
     * \param[in] img Puntero a la Imagen guardada.
     * \param[in] ruta Ruta de guardado.
     */
    void escribirPixeles(Imagen *img, string ruta);

};

#endif // ARCHIVOSAIC_H
