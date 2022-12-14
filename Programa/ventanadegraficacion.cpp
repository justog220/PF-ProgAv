#include "ventanadegraficacion.h"

#include "espaciodetrabajo.h"

VentanaDeGraficacion::VentanaDeGraficacion()
{
}



void VentanaDeGraficacion::initializeGL()
{

    initializeOpenGLFunctions();
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void VentanaDeGraficacion::resizeGL(int pAncho, int pAlto)
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

void VentanaDeGraficacion::paintGL()
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

    if (!seGraficaPseudocoloreada)
        graficarImagen();
    else
        graficarImagenPseudocoloreada(tablaDePseudocoloreo);

}

void VentanaDeGraficacion::graficarImagen()
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

               glColor3f((float)pixel_aux.getR()/imagen.getRango(), (float)pixel_aux.getG()/imagen.getRango(), (float)pixel_aux.getB()/imagen.getRango());

               glVertex3i(col, imagen.getFilas()-fil, 0);
               glVertex3i(col, imagen.getFilas()-(fil+1), 0);
               glVertex3i(col+1, imagen.getFilas()-(fil+1), 0);
               glVertex3i(col+1, imagen.getFilas()-fil, 0);

           }
        }
        glEnd();

        glPopMatrix();
}

void VentanaDeGraficacion::graficarImagenPseudocoloreada(int opc)
{
    Pixel pixel_aux;
    TablaLut tabla(opc);

    glPushMatrix();
    glTranslatef(desplx, desply, 0.0f);
    glScalef(escala, escala, 1.0f);

    glBegin(GL_QUADS);
        for(int fil=0; fil<imagen.getFilas(); fil++)
        {
           for(int col=0; col<imagen.getColumnas(); col++)
           {
               pixel_aux = tabla.pseudoColorear(imagen.getPixel(fil, col).getIntensidad());

               glColor3f((float)pixel_aux.getR()/imagen.getRango(), (float)pixel_aux.getG()/imagen.getRango(), (float)pixel_aux.getB()/imagen.getRango());

               glVertex3i(col, imagen.getFilas()-fil, 0);
               glVertex3i(col, imagen.getFilas()-(fil+1), 0);
               glVertex3i(col+1, imagen.getFilas()-(fil+1), 0);
               glVertex3i(col+1, imagen.getFilas()-fil, 0);

           }
        }
        glEnd();

        glPopMatrix();
}

void VentanaDeGraficacion::cargarImagen()
{
    string ruta = espacio->getRuta(opcDir, opcArch);

    GestorDeArchivos* archi;

    string extension = espacio->getPNMoAIC(ruta);

    imagen.borrarImagen();

    if(extension == "pnm")
        archi = new ArchivosPNM;
    else
        archi = new ArchivosAIC;

    imagen = archi->leer(ruta);


    espacio->llevarRegistro(opcDir, opcArch);
}

void VentanaDeGraficacion::recuperarImagen(string ruta)
{
    GestorDeArchivos* archi;

    string extension = espacio->getPNMoAIC(ruta);

    if(extension == "pnm")
        archi = new ArchivosPNM;
    else
        archi = new ArchivosAIC;

    imagen = archi->leer(ruta);
}

void VentanaDeGraficacion::setOpciones(int dir, int arch)
{
    opcDir = dir;

    opcArch = arch;
}

void VentanaDeGraficacion::graficarHistograma()
{
    ProcesadorEstadistico proce;

    proce.informarDatosEstadisticos(imagen);

    GraficadorHistograma* grafHistograma;

    grafHistograma = new GraficadorHistograma(imagen);

    grafHistograma->graficarHistograma();

    grafHistograma->show();

//    appl->exec();


}

void VentanaDeGraficacion::setApp(QApplication *app)
{
    appl = app;
}

void VentanaDeGraficacion::setEspacio(EspacioDeTrabajo &esp)
{
    espacio = &esp;
}

//NO es necesario que se llame keyPress, lo importante que
void VentanaDeGraficacion::keyPressEvent(QKeyEvent *event)
{
    Filtros* filtros;
    bool flecha_derecha = event->key() == Qt::Key_Right;
    bool ctrl = event->modifiers() & Qt::ControlModifier;
    bool flecha_izquierda = event->key() == Qt::Key_Left;;
    bool h = event->key() == Qt::Key_H;
    bool g = event->key() == Qt::Key_G;
    bool s = event->key() == Qt::Key_S;
    bool m = event->key() == Qt::Key_M;
    bool c = event->key() == Qt::Key_C;
    bool b = event->key() == Qt::Key_B;
    bool n = event->key() == Qt::Key_N;
    bool a = event->key() == Qt::Key_A;
    bool mas = event->key() == Qt::Key_Plus;
    bool menos = event->key() == Qt::Key_Minus;
    bool uno = event->key() == Qt::Key_1;
    bool dos = event->key() == Qt::Key_2;

    if(ctrl and flecha_derecha)
    {
        opcArch++;
        if(opcArch > espacio->getNroArchivos())
            opcArch = 1;
        cout<<"Ctrl + ->: Mostrar imagen siguiente.\n";
        cout.flush();
        cargarImagen();
        repaint();
    }

    if(ctrl and flecha_izquierda)
    {
        opcArch--;
        if(opcArch == 0)
            opcArch = espacio->getNroArchivos();
        cout<<"Ctrl + <-: Mostrar imagen anterior.\n";
        cout.flush();
        cargarImagen();
        repaint();
    }

    if(ctrl and mas)
    {
        filtros = new Brillo(1);
        cout<<"Ctrl + '+': Aumentar brillo.\n";
        cout.flush();
        appl->closeAllWindows();
        imagen = filtros->aplicarFiltro(imagen);
        show();
        repaint();
    }

    if(ctrl and menos)
    {
        filtros = new Brillo(2);
        cout<<"Ctrl + '-': Reducir brillo.\n";
        cout.flush();
//        appl->closeAllWindows();
        this->close();
        imagen = filtros->aplicarFiltro(imagen);
        show();
        repaint();
    }

    if(ctrl and c)
    {
        filtros = new Contraste;
        cout<<"Ctrl + c: Ajuste de contraste.\n";
        cout.flush();
        imagen = filtros->aplicarFiltro(imagen);
        repaint();
    }

    if(ctrl and s)
    {
        filtros = new FiltroPasaBajos;
        cout<<"Ctrl + s: Aplica filtro pasa bajos.\n";
        cout.flush();
        imagen = filtros->aplicarFiltro(imagen);
        repaint();

    }

    if(ctrl and a)
    {
        filtros = new FiltroPasaAltos;
        cout<<"Ctrl + a: Aplicar filtro pasa altos.\n";
        cout.flush();
        imagen = filtros->aplicarFiltro(imagen);
        repaint();
    }

    if(ctrl and n)
    {
        filtros = new Negativo;
        cout<<"Ctrl + n: Aplica negativo.\n";
        cout.flush();
        imagen = filtros->aplicarFiltro(imagen);
        repaint();
    }

    if(ctrl and g)
    {
        cout<<"Ctrl + g: Guardar imagen.\n";
        cout.flush();
        string ruta = espacio->getRuta(opcDir, opcArch);

        espacio->guardarImagen(&imagen);

        appl->closeAllWindows();
    }

    if(ctrl and h)
    {
        cout<<"Ctrl + h: Graficar histograma.\n";
        cout.flush();
        graficarHistograma();

    }

    if(ctrl and m)
    {
        filtros = new FiltroMediana;
        cout<<"Ctrl + m: Aplica filtro de mediana.\n";
        cout.flush();
        imagen = filtros->aplicarFiltro(imagen);
        repaint();
    }

    if (ctrl and uno)
    {
        cout<<"Ctrl + 1: Se pseudocolorea con glow.lut\n";
        cout.flush();
        seGraficaPseudocoloreada = true;
        tablaDePseudocoloreo = 1;
        repaint();
        seGraficaPseudocoloreada = false;
        tablaDePseudocoloreo = 0;
    }

    if (ctrl and dos)
    {
        cout<<"Ctrl + 2: Se pseudocolorea con Turbo.lut\n";
        seGraficaPseudocoloreada = true;
        tablaDePseudocoloreo = 2;
        repaint();
        seGraficaPseudocoloreada = false;
        tablaDePseudocoloreo = 0;
    }

    if (ctrl and b)
    {
        filtros = new Binarizado;
        cout<<"Ctrl + b: Se binariza la Imagen\n";
        appl->closeAllWindows();
        imagen = filtros->aplicarFiltro(imagen);
        show();
        repaint();
    }
}

void VentanaDeGraficacion::mousePressEvent(QMouseEvent *event)
{
    bool click_izq = event->button() == Qt::LeftButton;
    bool ctrl = event->modifiers() == Qt::ControlModifier;

    if(ctrl and click_izq)
    {

        cout<<"ctrl + Clic Izquierdo: Se aplica algoritmo del pintor.\n";
        cout.flush();

        int f = altoV - ( QCursor::pos().y() - this->pos().y()) + 35;
        int c = QCursor::pos().x() - this->pos().x();

        c = c/escala;
        f = f - desply;
        f = f/escala;

        f = imagen.getFilas()-1-f;

        AlgoritmoDelPintor algoritmo_del_pintor(imagen);
        appl->closeAllWindows();
        imagen = algoritmo_del_pintor.aplicarAlgoritmo(f, c);
        show();
        repaint();

    }


}
