/*!
 *  \class      Gestor de archivos
 *  \brief
 *  \details
 *  \author     Justo Garcia
 *  \date       Fecha de última modificación: 10-09-2022
 *  \pre
 *  \bug        No se utiliza en ningún momento
 *  \warning
*/
#ifndef GESTORDEATAJOS_H
#define GESTORDEATAJOS_H


#include <QApplication>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QWheelEvent>

class GestorDeAtajos: public QOpenGLWidget
{
public:
    GestorDeAtajos();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

};

#endif // GESTORDEATAJOS_H
