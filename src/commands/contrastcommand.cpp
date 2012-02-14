#include "contrastcommand.h"

ContrastCommand::ContrastCommand(double value)
{
    this->value = value;
}

void ContrastCommand::run(QImage *input, QImage *output)
{
    int w, h;
    int lut[256];
    QRgb colour;

    w = input->width();
    h = input->height();

    for (int i = 0; i < 256; i++)
    {
        lut[i] = (int)round(this->value * (i - 128) + 128);
        if (lut[i] < 0) lut[i] = 0;
        if (lut[i] > 255) lut[i] = 255;
    }

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            colour = input->pixel(i,j);
            output->setPixel(i, j, qRgb(lut[qRed(colour)], lut[qGreen(colour)], lut[qBlue(colour)]));
        }
    }
}

QString ContrastCommand::label()
{
    return "Contrast";
}
