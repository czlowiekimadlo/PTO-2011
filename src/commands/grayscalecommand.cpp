#include "grayscalecommand.h"

GrayscaleCommand::GrayscaleCommand(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void GrayscaleCommand::run(QImage *input, QImage *output)
{
    int w, h;
    int value, sum;
    QRgb colour;

    w = input->width();
    h = input->height();

    sum = this->r + this->g + this->b;

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            colour = input->pixel(i,j);

            value = (int)round((double)(this->r * qRed(colour) + this->g * qGreen(colour) + this->b * qBlue(colour)) / (double)sum);
            if (value < 0) value = 0;
            if (value > 255) value = 255;
            output->setPixel(i, j, qRgb(value, value, value));
        }
    }
}

QString GrayscaleCommand::label()
{
    return "Grayscale";
}
