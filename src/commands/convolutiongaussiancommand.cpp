#include "convolutiongaussiancommand.h"
#include <iostream>

ConvolutionGaussianCommand::ConvolutionGaussianCommand(int rad)
{
    this->radius = rad;
}

QString ConvolutionGaussianCommand::label()
{
    return "Gaussian convolution";
}

void ConvolutionGaussianCommand::run(QImage *input, QImage *output)
{
    int * matrix;
    int divSum = 0;
    int matrixSize = this->radius * 2 + 1;
    int power = 0;
    int width, height, position;
    int valueSumR, valueSumG, valueSumB;
    int tempWidth;
    int tempHeight;
    QRgb colour;

    width = input->width();
    height = input->height();


    //calculate matrix
    matrix = new int[matrixSize * matrixSize];
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[i * matrixSize + j] = 1;
            for (int p = 0; p < power; p++) {
                matrix[i * matrixSize + j] = matrix[i * matrixSize + j] * 2;
            }
            if (j < this->radius) power++;
            else if (j < matrixSize - 1) power--;
        }
        if (i < this->radius) power++;
        else if (i < matrixSize - 1) power--;
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            valueSumR = valueSumG = valueSumB = 0;
            divSum = 0;
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
                    position = (l - (j - this->radius)) * matrixSize + (k - (i - this->radius));
                    colour = input->pixel(k, l);
                    valueSumR += qRed(colour) * matrix[position];
                    valueSumG += qGreen(colour) * matrix[position];
                    valueSumB += qBlue(colour) * matrix[position];
                    divSum += matrix[position];
                }
            }

            valueSumR = (valueSumR / divSum) % 256;
            valueSumG = (valueSumG / divSum) % 256;
            valueSumB = (valueSumB / divSum) % 256;

            output->setPixel(i, j, qRgb(valueSumR, valueSumG, valueSumB));

        }
    }


    delete matrix;
}
