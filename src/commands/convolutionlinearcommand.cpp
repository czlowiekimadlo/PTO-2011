#include "convolutionlinearcommand.h"

ConvolutionLinearCommand::ConvolutionLinearCommand(int rad)
{
    this->radius = rad;
}

QString ConvolutionLinearCommand::label()
{
    return "Linear convolution";
}

void ConvolutionLinearCommand::run(QImage *input, QImage *output)
{
    int width, height;
    int maskSize = 0;
    int valueSumR, valueSumG, valueSumB;
    int tempWidth;
    int tempHeight;
    QRgb colour;

    width = input->width();
    height = input->height();

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            valueSumR = valueSumG = valueSumB = 0;
            maskSize = 0;
            tempWidth = i + this->radius;
            tempHeight = j + this->radius;
            for (int k = i - this->radius; k <= tempWidth; k++)
            {
                if (k < 0 || k >= width)
                {
                    continue;
                }
                for (int l = j - this->radius; l <= tempHeight; l++)
                {
                    if (l < 0 || l >= height)
                    {
                        continue;
                    }
                    colour = input->pixel(k, l);
                    valueSumR += qRed(colour);
                    valueSumG += qGreen(colour);
                    valueSumB += qBlue(colour);
                    maskSize++;
                }
            }

            valueSumR = valueSumR / maskSize;
            valueSumG = valueSumG / maskSize;
            valueSumB = valueSumB / maskSize;

            output->setPixel(i, j, qRgb(valueSumR, valueSumG, valueSumB));

        }
    }

}
