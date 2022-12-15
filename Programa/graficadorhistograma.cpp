
#include "graficadorhistograma.h"

GraficadorHistograma::GraficadorHistograma(Imagen &img)
{

    imagenAnalisis = img;


    frecuenciaR = procesadorEstad.devuelveFrecuenciaR(imagenAnalisis);
    frecuenciaG = procesadorEstad.devuelveFrecuenciaG(imagenAnalisis);
    frecuenciaB = procesadorEstad.devuelveFrecuenciaB(imagenAnalisis);
    frecuenciaPromedio = procesadorEstad.devolverFrecuenciaPromedio(imagenAnalisis);

    vector<int> maximasFrecuencias;
    maximasFrecuencias.push_back(*max_element(frecuenciaR.begin(), frecuenciaR.end()));
    maximasFrecuencias.push_back(*max_element(frecuenciaG.begin(), frecuenciaG.end()));
    maximasFrecuencias.push_back(*max_element(frecuenciaB.begin(), frecuenciaB.end()));

    maximaFrecuencia = *max_element(maximasFrecuencias.begin(), maximasFrecuencias.end());
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


    graficarHistograma();
}


void GraficadorHistograma::graficarHistograma()
{
    char bandera = 'r';
    glPushMatrix();

    glScalef(width()*1.0f/256.0f, height()*1.0f/maximaFrecuencia*1.0f, 0.0f);


    glBegin(GL_LINE_STRIP);
        for(int nivel = 0; nivel < frecuenciaR.size(); nivel++)
        {
            glColor4f(1.0f, 0.0f, 0.0f, 0.8f);
            glVertex3i(nivel, frecuenciaR[nivel], 1);

        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        for(int nivel = 0; nivel < frecuenciaR.size(); nivel++)
        {
            glColor4f(0.0f, 1.0f, 0.0f, 0.8f);
            glVertex3i(nivel, frecuenciaG[nivel], 0);
        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        for(int nivel = 0; nivel < frecuenciaR.size(); nivel++)
        {
            glColor4f(0.0f, 0.0f, 1.0f, 0.8f);
            glVertex3i(nivel, frecuenciaB[nivel], -1);
        }
    glEnd();


    glBegin(GL_LINE_STRIP);
        for(int nivel = 0; nivel < frecuenciaR.size(); nivel++)
        {
            if(bandera == 'r')
            {
                glColor4f(1.0f, 0.0f, 0.0f, 0.8f);
                bandera = 'g';
            }else if(bandera == 'g'){
                glColor4f(0.0f, 1.0f, 0.0f, 0.8f);
                bandera = 'b';
            }else if(bandera == 'b'){
                glColor4f(0.0f, 0.0f, 1.0f, 0.8f);
                bandera = 'r';
            }

            glVertex3i(nivel, frecuenciaPromedio[nivel], 1);

        }
    glEnd();

       glPopMatrix();


}


