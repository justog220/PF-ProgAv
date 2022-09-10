#include "graficador.h"

#include "espaciodetrabajo.h"

Graficador::Graficador()
{
}



void Graficador::initializeGL()
{

    initializeOpenGLFunctions();
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void Graficador::resizeGL(int pAncho, int pAlto)
{
    altoV = pAlto;

    anchoV = pAncho;

    glViewport(0, 0, anchoV, altoV);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(0, width(), 0, height(), -1, 1);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
}

void Graficador::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float relAncho = ((float)width())  / ((float)imagen.getColumnas());
    float relAlto  = ((float)height()) / ((float)imagen.getFilas());

    escala = 1.0f;
    desplx = 0.0f;
    desply = 0.0f;

    if(relAncho < relAlto)
    {
        escala = relAncho;
        desply = (height() - imagen.getFilas()*escala)*0.5f;
    }
    else
    {
        escala = relAlto;
        desplx = (width() - imagen.getColumnas()*escala)*0.5f;
    }

    graficarImagen();


}

void Graficador::graficarImagen()
{
    Pixel pixel_aux;

    //resizeGL(imagen.getColumnas(), imagen.getFilas());
    glPushMatrix();
    glTranslatef(desplx, desply, 0.0f);
    glScalef(escala, escala, 1.0f);

    glBegin(GL_QUADS);
        for(int fil=0; fil<imagen.getFilas(); fil++)
        {
           for(int col=0; col<imagen.getColumnas(); col++)
           {
               pixel_aux = imagen.getPixel(fil, col);

               glColor3f(pixel_aux.getR()/imagen.getRango(), pixel_aux.getG()/imagen.getRango(),pixel_aux.getB()/imagen.getRango());

               glVertex3i(col, imagen.getFilas()-fil, 0);
               glVertex3i(col, imagen.getFilas()-(fil+1), 0);
               glVertex3i(col+1, imagen.getFilas()-(fil+1), 0);
               glVertex3i(col+1, imagen.getFilas()-fil, 0);

           }
        }
        glEnd();

        glPopMatrix();
}

void Graficador::cargarImagen()
{
    string ruta = espacio->getRuta(opcDir, opcArch);

    ArchivosPNM archi;

    imagen = archi.leer(ruta);
}

void Graficador::setOpciones(int dir, int arch)
{
    opcDir = dir;

    opcArch = arch;
}

void Graficador::setEspacio(EspacioDeTrabajo &esp)
{
    espacio = &esp;
}

void Graficador::keyPressEvent(QKeyEvent *event)
{
    bool flecha_derecha = event->key() == Qt::Key_Right;
    bool ctrl = event->modifiers() & Qt::ControlModifier;
    bool flecha_izquierda= event->key() == Qt::Key_Left;;

    if(ctrl and flecha_derecha)
    {
        opcArch++;
        if(opcArch > espacio->getNroArchivos())
            opcArch = 1;
        cargarImagen();
        repaint();
    }

    if(ctrl and flecha_izquierda)
    {
        opcArch--;
        if(opcArch == 0)
            opcArch = espacio->getNroArchivos();
        cargarImagen();
        repaint();
    }


}
