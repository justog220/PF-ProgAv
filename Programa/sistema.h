/*!
 *  \class      Sistema
 *  \brief      Clase capaz de ejecutar el sistema de procesamiento de imagenes.
 *  \details    Es cappaz de ejecutar las diferentes acciones que son necesarias para
 *              el funcionamiento del software. Tiene un espacio de Trabajo y un Graficador
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 24-11-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef SISTEMA_H
#define SISTEMA_H

#include <QtGui/QKeyEvent>

#include "espaciodetrabajo.h"
#include "ventanadegraficacion.h"
#include "ExcepcionArchivoCorrupto.h"

class Sistema
{
public:
    /*!
     * \brief Sistema Constructor de la clase Sistema.
     */
    Sistema();

    /*!
     * \brief ejecutar Método que permite ejecutar el Sistema.
     * \param[in] a QApplication que se ejecuta.
     * \param[out] a QApplication que muestra informacion como salida.
     */
    void ejecutar(QApplication *a);

    /*!
     * \brief obtenerOpcDir Método que permite consultarle al usuario el directorio en el cual se
     * encuentra la Imagen que desea procesar.
     * \return Directorio o no que eligio el usuario.
     */
    int obtenerOpcDir();

    /*!
     * \brief obtenerOpcArch Método que permite conultarle al usuario el archivo que desea procesar.
     * \param[in] ruta String con la ruta de la carpeta en la cuál se buscan los archivos.
     * \return Archivo seleccionado por el usuario.
     */
    int obtenerOpcArch(string ruta);

    /*!
     * \brief iniciarGraficacion Método que permite comenzar la graficacion de una Imagen.
     * \param[in] a Puntero a la QApplication que se ejecuta.
     * \param[out] a Se muestra información con la ejecución de la QApplication.
     * \param[in] opcDir Directorio seleccionado por el usuario.
     * \param[in] opcArch Archivo seleccionaod por el usuario.
     */
    void iniciarGraficacion(QApplication *a, int opcDir, int opcArch);

    /*!
     * \brief recuperarOpciones Método que permite recuperar las opciones de la última Imagen graficada.
     * \return Vector de enteros que almacena la opcion del directorio y del archivo.
     */
    vector<int> recuperarOpciones();

    /*!
     * \brief mostrarAtajos Método que permite mostrar los atajos de teclado y mouse.
     */
    void mostrarAtajos();



private:
    /*!
     * \brief espDeTrabajo EspacioDeTrabajo con el cual trabaja el Sistema.
     */
    EspacioDeTrabajo espDeTrabajo;

    /*!
     * \brief graf Graficador que utiliza para graficar una Imagen.
     */
    VentanaDeGraficacion graf;

    /*!
     * \brief noSoportoAnterior Booleano que indica si el último archivo fue soportado o no.
     */
    bool noSoportoAnterior;
};

#endif // SISTEMA_H
