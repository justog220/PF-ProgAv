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
