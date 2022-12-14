/*!
 *  \class      EspacioDeTrabajo
 *  \brief      Clase capaz de gestionar donde se encuentran guardados los archivos.
 *  \details    Conoce la raiz de la ruta, las carpetas y es capaz de leer los
 *              archivos de una carpeta y almacenar el nombre de ellos en memoria.
 *              Es capaz de concatenar cadenas para devolver la ruta de un archivo en
 *              específico y de devolver el número de archivos.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H

#include <string>


#include "archivosaic.h"
#include "archivospnm.h"
#include "ExcepcionArchivoNoSoportado.h"
#include <dirent.h>


class EspacioDeTrabajo
{
public:
    /*!
     * \brief EspacioDeTrabajo Constructor del objeto EspacioDeTrabajo.
     */
    EspacioDeTrabajo();

    /*!
     * \brief cargarCarpetas Permite cargar las carpetas conocidas por el espacio de trabajo.
     */
    void cargarCarpetas();

    /*!
     * \brief getCarpetas Permite obtener la lista de las carpetas conocidas por el espacio de trabajo.
     * \return Lista con las carpetas conocidas por el espacio de trabajo.
     */
    vector<string> getCarpetas();

    /*!
     * \brief getListaDeArchivos Permite obtener la lista de los archivos presentes en cierta ruta.
     * \param[in] ruta Ruta de la cual se desean conocer los archivos.
     * \return Lista de los archivos presentes en una ruta.
     */
    vector<string> getListaDeArchivos(string ruta);

    /*!
     * \brief getRuta Permite devolver la ruta a partir de una ocpion de directorio y una de archivo.
     * \param[in] opcDir Directorio seleccionado.
     * \param[in] opcArch Archivo seleccionado. Por defecto es -8 y si no se especifica se devuelve
     * la ruta hasta un directorio
     * \return Ruta correspondiente a un archivo o directorio.
     */
    string getRuta(int opcDir, int opcArch=-8);

    /*!
     * \brief getPNMoAIC Devuelve si un archivo es PNM o AIC.
     * \param[in] ruta Ruta correspondiente al archivo cuya extension se desea verificar.
     * \return "pnm" si es pnm o "aic" si es aic.
     */
    string getPNMoAIC(string ruta);

    /*!
     * \brief esPNM Devuelve si un archivo es PNM o no.
     * \param[in] archivo Ruta a un archivo.
     * \return Booleano que indica si es PNM o no.
     */
    bool esPNM(string archivo);

    /*!
     * \brief esAIC Devuelve si un archivo es AIC o no.
     * \param[in] archivo Ruta a un archivo.
     * \return Booleano que indica si es AIC o no.
     */
    bool esAIC(string archivo);

    /*!
     * \brief getNroArchivos Devuelve el numero de archivo en el directorio seleccionados.
     * \return int que representa el número de archivos en el directorio que selecciono el usuario.
     */
    int getNroArchivos();

    /*!
     * \brief llevarRegistro Permite llevar un registro de las imágenes graficadas.
     * \param[in] opcDir Directorio en el que se encuentra la imagen graficada.
     * \param[in] opcArch Archvo del directorio que es la imagen graficada.
     */
    void llevarRegistro(int opcDir, int opcArch);

    /*!
     * \brief guardarImagen Método auxiliar en el guardado de una imagen.
     * \param[in] img Imagen guardada.
     */
    void guardarImagen(Imagen *img);

    /*!
     * \brief getNombreArchivo Devuelve el nombre de un archivo a partir de su ruta.
     * \param[in] ruta Ruta correspondiente al archivo.
     * \return Nombre del archivo.
     */
    string getNombreArchivo(string ruta);

private:
    /*!
     * \param raiz Raiz del espacio de trabajo.
     */
    string raiz="./Imagenes/";

    /*!
     * \param carpetas Lista de carpetas conocidas por el espacio de trabajo.
     */
    vector<string> carpetas;

    /*!
     * \param listaDeArchivos Lista de archivos presentes en un directorio.
     */
    vector<string> listaDeArchivos;

};

#endif // ESPACIODETRABAJO_H
