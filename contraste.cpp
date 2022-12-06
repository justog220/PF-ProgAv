#include "contraste.h"

Contraste::Contraste()
{

}

Imagen Contraste::aplicarFiltro(Imagen &imag)
{
    ProcesadorEstadistico proce;
    Pixel pix_aux;

    vector<int> maximo_minimo_R = proce.hallarMaximoMinimoR(imag);
    vector<int> maximo_minimo_G = proce.hallarMaximoMinimoG(imag);
    vector<int> maximo_minimo_B = proce.hallarMaximoMinimoB(imag);

    for(int i=0; i<imag.getFilas(); i++)
        for(int j=0; j<imag.getColumnas(); j++)
        {
            pix_aux = imag.getPixel(i,j);
            pix_aux.ajusteContraste(maximo_minimo_R, maximo_minimo_G, maximo_minimo_B, imag.getRango());
            imag.setPixel(i, j, pix_aux);

        }

    return imag;
}
