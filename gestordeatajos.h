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
