#include "edgerobertscommand.h"

EdgeRobertsCommand::EdgeRobertsCommand()
{
    this->mask[0] =  0; this->mask[1] = 1;
    this->mask[2] = -1; this->mask[3] = 0;
}

void EdgeRobertsCommand::run(QImage *input, QImage *output) {
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
            for (int k = i; k <= i + 1; k++)
            {
                if (k == w)
                {
                    continue;
                }

                tk = k;

                for (int l = j; l <= j + 1; l++)
                {
                    if (l == h)
                    {
                        continue;
                    }

                    tl = l;

                    colour = input->pixel(tk,tl);
                    r = qRed(colour);
                    g = qGreen(colour);
                    b = qBlue(colour);

                    if (i < w-1) {
                        RGx += r * this->mask[(k - i) * 2 + (l - j)];
                        GGx += g * this->mask[(k - i) * 2 + (l - j)];
                        BGx += b * this->mask[(k - i) * 2 + (l - j)];
                    }
                    if (j < h-1) {
                        RGy += r * this->mask[(l - j) * 2 + (k - i)];
                        GGy += g * this->mask[(l - j) * 2 + (k - i)];
                        BGy += b * this->mask[(l - j) * 2 + (k - i)];
                    }
                }
            }

            if (RGx < 0) RGx = -RGx;
            if (RGy < 0) RGy = -RGy;
            if (GGx < 0) GGx = -GGx;
            if (GGy < 0) GGy = -GGy;
            if (BGx < 0) BGx = -BGx;
            if (BGy < 0) BGy = -BGy;

            r = (int)(RGx + RGy);
            if (r > 255) r = 255;
            g = (int)(GGx + GGy);
            if (g > 255) g = 255;
            b = (int)(BGx + BGy);
            if (b > 255) b = 255;

            output->setPixel(i, j, qRgb(r, g, b));
        }
    }
}

QString EdgeRobertsCommand::label()
{
    return "Roberts edge detect";
}
