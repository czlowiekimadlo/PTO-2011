#include "brightnesscommand.h"

BrightnessCommand::BrightnessCommand(int value)
{
    this->value = value;
}

void BrightnessCommand::run(QImage *input, QImage *output)
{
    int w, h;
    int r, g, b;
    QRgb colour;

    w = input->width();
    h = input->height();

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            colour = input->pixel(i,j);
            r = qRed(colour) + this->value;
            g = qGreen(colour) + this->value;
            b = qBlue(colour) + this->value;

            if (r < 0) r = 0;
            if (r > 255) r = 255;
            if (g < 0) g = 0;
            if (g > 255) g = 255;
            if (b < 0) b = 0;
            if (b > 255) b = 255;
            output->setPixel(i, j, qRgb(r, g, b));
        }
    }
}

QString BrightnessCommand::label()
{
    return "Brightness";
}
