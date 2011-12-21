#include "histogramstretchcommand.h"

HistogramStretchCommand::HistogramStretchCommand(bool r, bool g, bool b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void HistogramStretchCommand::run(QImage *input, QImage *output)
{
    int rhist[256];
    int ghist[256];
    int bhist[256];

    int p, x, y, minR, maxR, minG, maxG, minB, maxB;
    int tmpR, tmpG, tmpB;
    QRgb colour;

    for (int i = 0; i < 256; i++)
    {
        rhist[i] = ghist[i] = bhist[i] = 0;
    }

    x = input->width();
    y = input->height();
    p = x * y;

    // compute histograms for channels
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            colour = input->pixel(i,j);

            if (this->r) rhist[qRed(colour)]++;
            if (this->g) ghist[qGreen(colour)]++;
            if (this->b) bhist[qBlue(colour)]++;
        }
    }

    // find mins and maxes
    minR = minG = minB = 0;
    maxR = maxG = maxB = 255;

    for (int i = 0; i < 255; i++)
    {
        if (rhist[minR] > 0)
        {
            break;
        }
        else
        {
            minR++;
        }
    }
    for (int i = 0; i < 255; i++)
    {
        if (ghist[minG] > 0)
        {
            break;
        }
        else
        {
            minG++;
        }
    }
    for (int i = 0; i < 255; i++)
    {
        if (bhist[minB] > 0)
        {
            break;
        }
        else
        {
            minB++;
        }
    }
    for (int i = 0; i < 255; i++)
    {
        if (rhist[maxR] > 0)
        {
            break;
        }
        else
        {
            maxR--;
        }
    }
    for (int i = 0; i < 255; i++)
    {
        if (ghist[maxG] > 0)
        {
            break;
        }
        else
        {
            maxG--;
        }
    }
    for (int i = 0; i < 255; i++)
    {
        if (bhist[maxB] > 0)
        {
            break;
        }
        else
        {
            maxB--;
        }
    }


    // transform image
    this->r = (this->r && maxR > minR);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            colour = input->pixel(i,j);
            tmpR = qRed(colour);
            tmpG = qGreen(colour);
            tmpB = qBlue(colour);

            if (this->r)
            {
                tmpR = (int)floor(((double)(tmpR - minR) / (double)(maxR - minR)) * 255 + 0.5);
            }
            if (this->g && maxG > minG)
            {
                tmpG = (int)floor(((double)(tmpG - minG) / (double)(maxG - minG)) * 255 + 0.5);
            }
            if (this->b && maxB > minB)
            {
                tmpB = (int)floor(((double)(tmpB - minB) / (double)(maxB - minB)) * 255 + 0.5);
            }

            output->setPixel(i, j, qRgb(tmpR, tmpG, tmpB));
        }
    }
}

QString HistogramStretchCommand::label()
{
    return "Histogram stretch";
}
