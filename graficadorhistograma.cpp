#include "graficadorhistograma.h"

GraficadorHistograma::GraficadorHistograma(Imagen &img)
{

    imagenAnalisis = img;
    ProcesadorEstadistico procesadorEstad;

    frecuenciaR = procesadorEstad.devuelveFrecuenciaR(imagenAnalisis);
    frecuenciaG = procesadorEstad.devuelveFrecuenciaG(imagenAnalisis);
    frecuenciaB = procesadorEstad.devuelveFrecuenciaB(imagenAnalisis);

//    for (uint i = 0; i < frecuenciaR.size(); i++)
//    {
//        frecuenciaR[i] = frecuenciaR[i]*100/imagenAnalisis.getNroPixeles();
//        frecuenciaG[i] = frecuenciaG[i]*100/imagenAnalisis.getNroPixeles();
//        frecuenciaB[i] = frecuenciaB[i]*100/imagenAnalisis.getNroPixeles();

//    }

    vector<int> maximasFrecuencias;
    maximasFrecuencias.push_back(*max_element(frecuenciaR.begin(), frecuenciaR.end()));
    maximasFrecuencias.push_back(*max_element(frecuenciaG.begin(), frecuenciaG.end()));
    maximasFrecuencias.push_back(*max_element(frecuenciaB.begin(), frecuenciaB.end()));

    maximaFrecuencia = *max_element(maximasFrecuencias.begin(), maximasFrecuencias.end());

//    construirHistograma();
}

void GraficadorHistograma::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void GraficadorHistograma::resizeGL(int pAncho, int pAlto)
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

void GraficadorHistograma::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float relAncho = ((float)width())  / ((float)frecuenciaB.size());
    float relAlto  = ((float)height()) / (float)maximaFrecuencia;

    escala = 1.0f;
    desplx = 0.0f;
    desply = 0.0f;

    if(relAncho < relAlto)
    {
        escala = relAncho;
        desply = (height() - maximaFrecuencia*escala)*0.5f;
    }
    else
    {
        escala = relAlto;
        desplx = (width() - frecuenciaB.size()*escala)*0.5f;
    }

//    if(relAncho < relAlto)
//    {
//        escala = relAncho;
//        desply = (height() - histograma.getFilas()*escala)*0.5f;
//    }
//    else
//    {
//        escala = relAlto;
//        desplx = (width() - histograma.getColumnas()*escala)*0.5f;
//    }

    graficarHistograma();
}

//void GraficadorHistograma::graficarHistograma()
//{
//    Pixel pixel_aux;

//    glPushMatrix();
//    glTranslatef(desplx, desply, 0.0f);
//    glScalef(escala, escala, 1.0f);

//    glBegin(GL_QUADS);
//        for(int fil=0; fil<histograma.getFilas(); fil++)
//        {
//           for(int col=0; col<histograma.getColumnas(); col++)
//           {
//               pixel_aux = histograma.getPixel(fil, col);

//               glColor3f((float)pixel_aux.getR()/histograma.getRango(), (float)pixel_aux.getG()/histograma.getRango(), (float)pixel_aux.getB()/histograma.getRango());

//               glVertex3i(col, histograma.getFilas()-fil, 0);
//               glVertex3i(col, histograma.getFilas()-(fil+1), 0);
//               glVertex3i(col+1, histograma.getFilas()-(fil+1), 0);
//               glVertex3i(col+1, histograma.getFilas()-fil, 0);

//           }
//        }
//        glEnd();

//        glPopMatrix();
//}

//void GraficadorHistograma::construirHistograma()
//{
//    histograma.setFilas(maximaFrecuencia+1);
//    histograma.setColumnas(frecuenciaR.size());
//    histograma.setTamanio();
//    histograma.setRango(frecuenciaR.size()-1);
//    for (int i=0; i< histograma.getFilas()-1; i++)
//        for (int j=0; j<histograma.getColumnas()-1; j++)
//            histograma.setPixel(i , j, Pixel(0, 0, 0));
////            histograma.setPixel(i, j, Pixel(histograma.getRango(), histograma.getRango(), histograma.getRango()));

//    for(int valor=0; valor < frecuenciaR.size(); valor++)
//    {
//        histograma.setPixel(frecuenciaR[valor], valor, Pixel(histograma.getRango(), 0, 0));
//    }

//    for(int valor=0; valor < frecuenciaG.size(); valor++)
//    {
//        histograma.setPixel(frecuenciaG[valor], valor, Pixel(0, histograma.getRango(), 0));
//    }

//    for(int valor=0; valor < frecuenciaB.size(); valor++)
//    {
//        histograma.setPixel(frecuenciaB[valor], valor, Pixel(0, 0, histograma.getRango()));
//    }
//}

void GraficadorHistograma::graficarHistograma()
{
    glPushMatrix();

    glTranslatef(desplx, desply, 0.0f);
    glScalef(escala, escala, 1.0f);

//    glBegin(GL_LINE_STRIP);
//        glColor3f(1.0f, 0.0f, 0.0f);
//        for(int valor=0; valor < frecuenciaR.size(); valor++)
//        {
//            glVertex3f(valor, frecuenciaR[valor], 0);
//        }
////    glEnd();

////    glBegin(GL_LINE_STRIP);
//        glColor3f(0.0f, 1.0f, 0.0f);
//        for(int valor=0; valor < frecuenciaG.size(); valor++)
//        {
//            glVertex3f(valor, frecuenciaG[valor], 0);
//        }
////    glEnd();

////    glBegin(GL_LINE_STRIP);
//        glColor3f(0.0f, 0.0f, 1.0f);
//        for(int valor=0; valor < frecuenciaB.size(); valor++)
//        {
//            glVertex3f(valor, frecuenciaB[valor], 0);
//        }

//    glEnd();
    glBegin(GL_LINE_STRIP);
        for(int nivel = 0; nivel < frecuenciaR.size(); nivel++)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(nivel, frecuenciaR[nivel], 0);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(nivel, frecuenciaG[nivel], 0);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(nivel, frecuenciaB[nivel], 0);
        }
    glEnd();


       glPopMatrix();
}


