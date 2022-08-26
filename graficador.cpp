#include "graficador.h"

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
    string ruta = getRuta(opcDir, opcArch);

    cout<<ruta;

    ArchivosPNM archi;

    imagen = archi.leer(ruta);
}

void Graficador::cargarCarpetas()
{
    carpetas.push_back("grupo_imagenes_1/");
    carpetas.push_back("grupo_imagenes_2/");
    carpetas.push_back("grupo_imagenes_3_corruptas/");



    carpeta_1.push_back("20210407111719.pgm");
    carpeta_1.push_back("entre_rios_03.ppm");
    carpeta_1.push_back("hospital-robot_01.pgm");
    carpeta_1.push_back("test_01.pgm");
    carpeta_1.push_back("test_02.ppm");
    carpeta_1.push_back("tigre_01.pgm");

    carpeta_2.push_back("entre_rios_01.pgm");
    carpeta_2.push_back("entre_rios_02.ppm");
    carpeta_2.push_back("predio_fi_uner_01.ppm");
    carpeta_2.push_back("predio_fi_uner_01_0.961mXpixel_con_mucho_ruido.ppm");
    carpeta_2.push_back("predio_fi_uner_01_0.961mXpixel_con_ruido.ppm");

    carpeta_3.push_back("imagen_corrupta_01.pgm");
    carpeta_3.push_back("imagen_corrupta_02.pgm");


}

string Graficador::getRuta(int opcDir, int opcArch)
{
    cargarCarpetas();

    string ruta;

    ruta = raiz;

    switch(opcDir)
    {
    case 1:
        ruta = ruta.append(carpetas[opcDir-1]);
        ruta = ruta.append(carpeta_1[opcArch-1]);
        break;
    case 2:
        ruta = ruta.append(carpetas[opcDir-1]);
        ruta = ruta.append(carpeta_2[opcArch-1]);
        break;
    case 3:
        ruta = ruta.append(carpetas[opcDir-1]);
        ruta = ruta.append(carpeta_3[opcArch-1]);
        break;
}
    return ruta;
}

void Graficador::setOpciones(int dir, int arch)
{
    opcDir = dir;

    opcArch = arch;
}

void Graficador::keyPressEvent(QKeyEvent *event)
{
//    bool ctrl = event->key() == Qt::Key_Control;
//    bool flecha_derecha=false;
//    if(event->key() == Qt::Key_Right)
//    {
//        flecha_derecha = true;
//    }

    bool flecha_derecha = event->key() == Qt::Key_Right;
    bool ctrl = event->modifiers() & Qt::ControlModifier;
    bool flecha_izquierda=false;

    if(event->key() == Qt::Key_Left)
    {
        flecha_izquierda = true;
    }

    if(ctrl and flecha_derecha)
    {
        opcArch++;
        if(opcArch > carpetas[opcDir-1].size())
            opcArch = 0;
        cargarImagen();
        repaint();
//        cout<<"Funciona ";
//        update();
    }


    if(ctrl and flecha_izquierda)
    {
        opcArch--;
        if(opcArch == 0)
            opcArch = carpetas[opcDir-1].size();
        cargarImagen();
        repaint();
    }


}
