#include "edgegradientcommand.h"

EdgeGradientCommand::EdgeGradientCommand()
{
    this->mWidth = 3;
    this->mHeight = 3;

    this->mask[0] = 1; this->mask[1] = 2; this->mask[2] = 1;
    this->mask[3] = 0; this->mask[4] = 0; this->mask[5] = 0;
    this->mask[6] = -1; this->mask[7] = -2; this->mask[8] = -1;
}

void EdgeGradientCommand::run(QImage *input, QImage *output)
{
    int w, h;
    int r, g, b;
    int RGx, RGy, GGx, GGy, BGx, BGy;
    int tk, tl;

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
                if (k < 0)
                {
                    tk = w - 1;
                }
                else if (k == w)
                {
                    tk = 0;
                }
                else
                {
                    tk = k;
                }
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (l < 0)
                    {
                        tl = h - 1;
                    }
                    else if (l == h)
                    {
                        tl = 0;
                    }
                    else
                    {
                        tl = l;
                    }
                    colour = input->pixel(tk,tl);
                    r = qRed(colour);
                    g = qGreen(colour);
                    b = qBlue(colour);

                    RGx += r * this->mask[(l - j + 1) * 3 + (k - i + 1)];
                    RGy += r * this->mask[(k - i + 1) * 3 + (l - j + 1)];
                    GGx += g * this->mask[(l - j + 1) * 3 + (k - i + 1)];
                    GGy += g * this->mask[(k - i + 1) * 3 + (l - j + 1)];
                    BGx += b * this->mask[(l - j + 1) * 3 + (k - i + 1)];
                    BGy += b * this->mask[(k - i + 1) * 3 + (l - j + 1)];
                }
            }

            RGx = (int)round(((double)(RGx + 1020) / 2040.0) * 255.0);
            RGy = (int)round(((double)(RGy + 1020) / 2040.0) * 255.0);
            GGx = (int)round(((double)(GGx + 1020) / 2040.0) * 255.0);
            GGy = (int)round(((double)(GGy + 1020) / 2040.0) * 255.0);
            BGx = (int)round(((double)(BGx + 1020) / 2040.0) * 255.0);
            BGy = (int)round(((double)(BGy + 1020) / 2040.0) * 255.0);


            output->setPixel(i, j, qRgb(r, g, b));
        }
    }
}

QString EdgeGradientCommand::label()
{
    return "Gradient edge detect";
}
