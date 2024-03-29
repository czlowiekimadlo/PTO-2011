#include "edgegradientcommand.h"
#include <iostream>

EdgeGradientCommand::EdgeGradientCommand()
{
    this->mWidth = 3;
    this->mHeight = 3;

    this->mask[0] = 1; this->mask[1] = 1; this->mask[2] = 1;
    this->mask[3] = 0; this->mask[4] = 0; this->mask[5] = 0;
    this->mask[6] = -1; this->mask[7] = -1; this->mask[8] = -1;
}

void EdgeGradientCommand::run(QImage *input, QImage *output)
{
    int w, h;
    int r, g, b;
    int RGx, RGy, GGx, GGy, BGx, BGy;
    int tk, tl;
    QRgb colour;

    w = input->width();
    h = input->height();

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            RGx = RGy = GGx = GGy = BGx = BGy = 0;

            // calculate convolutions
            for (int k = i - 1; k <= i + 1; k++)
            {
                if (k < 0 || k == w)
                {
                    continue;
                }

                tk = k;

                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (l < 0 || l == h)
                    {
                        continue;
                    }

                    tl = l;

                    colour = input->pixel(tk,tl);
                    r = qRed(colour);
                    g = qGreen(colour);
                    b = qBlue(colour);

                    if (i > 0 && i < w-1) {
                        RGx += r * this->mask[(k - i + 1) * 3 + (l - j + 1)];
                        GGx += g * this->mask[(k - i + 1) * 3 + (l - j + 1)];
                        BGx += b * this->mask[(k - i + 1) * 3 + (l - j + 1)];
                    }
                    if (j > 0 && j < h-1) {
                        RGy += r * this->mask[(l - j + 1) * 3 + (k - i + 1)];
                        GGy += g * this->mask[(l - j + 1) * 3 + (k - i + 1)];
                        BGy += b * this->mask[(l - j + 1) * 3 + (k - i + 1)];
                    }
                }
            }

            r = (int)sqrt(RGx*RGx + RGy*RGy);
            if (r > 255) r = 255;
            g = (int)sqrt(GGx*GGx + GGy*GGy);
            if (g > 255) g = 255;
            b = (int)sqrt(BGx*BGx + BGy*BGy);
            if (b > 255) b = 255;

            output->setPixel(i, j, qRgb(r, g, b));
        }
    }
}

QString EdgeGradientCommand::label()
{
    return "Gradient edge detect";
}
