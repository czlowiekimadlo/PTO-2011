#include "convolutionfreecommand.h"

ConvolutionFreeCommand::ConvolutionFreeCommand(int w, int h, int x, int y, QString m)
{
    this->width = w;
    this->height = h;
    this->anchorX = x;
    this->anchorY = y;
    this->matrix = m;
}

QString ConvolutionFreeCommand::label()
{
    return "Free convolution";
}

void ConvolutionFreeCommand::run(QImage *input, QImage *output)
{
    int points, position;
    double * mask;
    int iW, iH, tempWidth, tempHeight;
    QStringList lines, elements;
    double valueSumR, valueSumG, valueSumB, divSum;
    QRgb colour;

    iW = input->width();
    iH = input->height();

    points = this->width * this->height;

    // prepare mask
    mask = new double[points];
    lines = this->matrix.split("\n");
    for (int i = 0; i < this->height; i++)
    {
        elements = lines.at(i).split(" ");
        for (int j = 0; j < this->width; j++)
        {
            mask[i * this->height + j] = elements.at(j).toDouble();
        }
    }

    for (int i = 0; i < iW; i++)
    {
        for (int j = 0; j < iH; j++)
        {
            valueSumR = valueSumG = valueSumB = 0.0;
            divSum = 0.0;
            tempWidth = i + this->width - this->anchorX;
            tempHeight = j + this->height - this->anchorY;
            for (int k = i - this->anchorX + 1; k <= tempWidth; k++)
            {
                if (k < 0 || k >= iW)
                {
                    continue;
                }
                for (int l = j - this->anchorY + 1; l <= tempHeight; l++)
                {
                    if (l < 0 || l >= iH)
                    {
                        continue;
                    }
                    position = (l - (j - this->anchorY + 1)) * this->height + (k - (i - this->anchorX + 1));
                    colour = input->pixel(k, l);
                    valueSumR += (double)qRed(colour) * mask[position];
                    valueSumG += (double)qGreen(colour) * mask[position];
                    valueSumB += (double)qBlue(colour) * mask[position];
                    divSum += mask[position];
                }
            }

            valueSumR = round(valueSumR / divSum);
            valueSumG = round(valueSumG / divSum);
            valueSumB = round(valueSumB / divSum);

            output->setPixel(i, j, qRgb((int)valueSumR, (int)valueSumG, (int)valueSumB));

        }
    }

    delete mask;
}
