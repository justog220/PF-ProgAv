/*!
 *  \class      Brillo
 *  \brief      Clase que hereda de la clase Filtros métodos y los redefine para aumentar o reducir el brillo de una Imagen.
 *  \details    Obtiene una Imagen y le aumenta el brillo o lo reduce segun quiera el usuario con una diferencia indicada, por defecto 50.
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 12-12-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef BRILLO_H
#define BRILLO_H

#include "filtros.h"
#include <limits>

class Brillo : public Filtros
{
public:
    /*!
     * \brief Brillo Constructor del objeto Brillo.
     * \param opc Opción que indica si se aumenta o si se reduce el
     * brillo, 1 si aumenta y 2 si se reduce.
     */
    Brillo(int opc);

    /*!
     * \brief aplicarFiltro Método heredado de la case Filtros, redefinido
     * para la modificación del brillo.
     * \param[in] imagen Imagen a la cuál se le desea aplicar el filtro.
     * \return Devuelve la Imagen con el filtro aplicado.
     */
    Imagen aplicarFiltro(Imagen &imagen) override;

    /*!
     * \brief aumentarBrillo Método que permite aumentar el brillo de
     * una Imagen.
     * \param[in] imagen Imagen a la cual se le desea aplicar el filtro.
     * \param[out] imagen Se modifica la Imagen.
     */
    void aumentarBrillo(Imagen &imagen);

    /*!
     * \brief reducirBrillo Método que permite reducir el brillo de una Imagen.
     * \param[in] imagen Imagen a la cual se le desea aplicar el filtro.
     * \param[out] imagen Se modifica la Imagen.
     */
    void reducirBrillo(Imagen &imagen);

    void cambiaOpcion();

private:
    /*!
     * \param diferencia Número en el cual se aumenta o se reduce el brillo.
     */
    int diferencia;

    /*!
     * \brief consultarDiferencia Método privado que permite obtener la diferencia
     * en la que se modifica el brillo.
     * \param[in] imagen Imagen de la cual se modifica el brillo.
     */
    void consultarDiferencia(Imagen &imagen);

    /*!
     * \param seAumenta Booleano que indica si el brillo se aumenta o no.
     */
    bool seAumenta;

    /*!
     * \param seReduce Booleano que indica si el brillo se reduce o no.
     */
    bool seReduce;
};

#endif // BRILLO_H
