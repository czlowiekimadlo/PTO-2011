#include "histogramevencommand.h"

HistogramEvenCommand::HistogramEvenCommand(bool r, bool g, bool b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void HistogramEvenCommand::run(QImage *input, QImage *output)
{
    int rhist[256];
    int ghist[256];
    int bhist[256];
    double rdist[256];
    double gdist[256];
    double bdist[256];
    int rlookup[256];
    int glookup[256];
    int blookup[256];
    int p, x, y, tmpR, tmpG, tmpB;
    double dR, dG, dB;
    QRgb colour;

    for (int i = 0; i < 256; i++)
    {
        rhist[i] = ghist[i] = bhist[i] = 0;
        rdist[i] = gdist[i] = bdist[i] = 0.0;
        rlookup[i] = glookup[i] = blookup[i] = i;
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

    // compute distribuants for channels
    tmpR = tmpG = tmpB = 0;
    for (int i = 0; i < 256; i++)
    {
        if (this->r)
        {
            tmpR += rhist[i];
            rdist[i] = (double)tmpR / (double)p;
        }
        if (this->g)
        {
            tmpG += ghist[i];
            gdist[i] = (double)tmpG / (double)p;
        }
        if (this->b)
        {
            tmpB += bhist[i];
            bdist[i] = (double)tmpB / (double)p;
        }
    }

    //find first distribuant values for channels
    dR = dG = dB = 0.0;
    for (int i = 0; i < 256; i++)
    {
        if (rdist[i] > 0.0)
        {
            dR = rdist[i];
            break;
        }
    }
    for (int i = 0; i < 256; i++)
    {
        if (gdist[i] > 0.0)
        {
            dG = gdist[i];
            break;
        }
    }
    for (int i = 0; i < 256; i++)
    {
        if (bdist[i] > 0.0)
        {
            dB = bdist[i];
            break;
        }
    }

    // compute lookup tables for channels
    for (int i = 0; i < 256; i++)
    {
        if (this->r && dR > 0.0)
        {
            //rlookup[i] = (int)floor((rdist[i] - dR)/(1-dR)*255 + 0.5) % 256;
            rlookup[i] = (int)floor(rdist[i]*255 + 0.5) % 256;
        }
        if (this->g && dG > 0.0)
        {
            //glookup[i] = (int)floor((gdist[i] - dG)/(1-dG)*255 + 0.5) % 256;
            glookup[i] = (int)floor(gdist[i]*255 + 0.5) % 256;
        }
        if (this->b && dB > 0.0)
        {
            //blookup[i] = (int)floor((bdist[i] - dB)/(1-dB)*255 + 0.5) % 256;
            blookup[i] = (int)floor(bdist[i]*255 + 0.5) % 256;
        }
    }

    // transform image
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            colour = input->pixel(i,j);

            if (this->r)
            {
                tmpR = rlookup[qRed(colour)];
            }
            else
            {
                tmpR = qRed(colour);
            }
            if (this->g)
            {
                tmpG = glookup[qGreen(colour)];
            }
            else
            {
                tmpG = qGreen(colour);
            }
            if (this->b)
            {
                tmpB = blookup[qBlue(colour)];
            }
            else
            {
                tmpB = qBlue(colour);
            }

            output->setPixel(i, j, qRgb(tmpR, tmpG, tmpB));
        }
    }
}

QString HistogramEvenCommand::label()
{
    return "Histogram even";
}
