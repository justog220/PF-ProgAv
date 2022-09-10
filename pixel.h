/*!
 *  \class      Pixel
 *  \brief      Modela un pixel de una imagen..
 *  \details    Representa un pixel de los distintos tipos de imagen, indistintamente
 *              si es de intensidades, RGB o monocromatico. Tiene valores enteros para
 *              rojo, verde y azul. Puede cambiar estos valores y devolverlos en caso de
 *              ser necesario.
 *  \author     Justo Garcia
 *  \date       Fechca de última modificación: 10-09-2022
 *  \pre        Idealmente deben inicializarse solo para formar parte de la representacion
 *              de una imagen.
 *  \bug        Cualquier error encontrado se anota aquí, por ejemplo, un fallo
 *              de acceso a disco, fallas en liberación de memoria,
 *              malfuncionamientos de rutinas que se hayan encontrado, etc.
 *  \warning
*/
#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:
    Pixel();

    void setPixelRGB(int valor_r, int valor_g, int valor_b);

    void setPixelMonocr(int valor);

    void setPixelEscala(int valor);

    float getR();

    float getG();

    float getB();

private:
    float r, g, b;

};

#endif // PIXEL_H
