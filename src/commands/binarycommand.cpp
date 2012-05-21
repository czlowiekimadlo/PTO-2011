#include "binarycommand.h"

BinaryCommand::BinaryCommand()
{
}

void BinaryCommand::run(QImage *input, QImage *output) {
    int w, h;
    int value;
    QRgb colour;

    w = input->width();
    h = input->height();

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            colour = input->pixel(i,j);

            value = (int)round((double)(qRed(colour) + qGreen(colour) + qBlue(colour)) / 3.0);
            if (value < 128) value = 0;
            else value = 255;
            output->setPixel(i, j, qRgb(value, value, value));
        }
    }
}

QString BinaryCommand::label()
{
    return "Binary threshold";
}
