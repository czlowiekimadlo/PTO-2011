#include "edgedogcommand.h"

EdgeDoGCommand::EdgeDoGCommand(double d, double K)
{
    double base1 = 6.2831853 * d * d;
    double expBase1 = 2 * d * d;
    double base2 = base1 * K * K;
    double expBase2 = expBase1 * K * K;
    int index;
    int position;

    this->mask1[49] = this->mask2[49] = 0.0;

    // calculate gaussian matrices
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            index = i * 7 + j;
            position = (i-3) * (i-3) + (j-3) * (j-3);
            this->mask1[index] = (1.0/base1) * exp(-position/expBase1);
            this->mask1[49] += this->mask1[index];
            this->mask2[index] = (1.0/base2) * exp(-position/expBase2);
            this->mask2[49] += this->mask2[index];
        }
    }

}

void EdgeDoGCommand::run(QImage *input, QImage *output) {
    int w, h;
    int r, g, b;
    double G1r, G1g, G1b, G2r, G2g, G2b;
    int tx, ty;
    int index;
    QRgb colour;

    w = input->width();
    h = input->height();

    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            G1r = G1g = G1b = G2r = G2g = G2b = 0.0;

            // calculate convolutions
            for (int i = 0; i < 7; i++)
            {
                tx = x - 3 + i;
                if (tx < 0 || tx >= w) continue;

                for (int j = 0; j < 7; j++)
                {
                    ty = y -3 + j;
                    if (ty < 0 || ty >= h) continue;

                    index = j * 7 + i;

                    colour = input->pixel(tx,ty);
                    r = qRed(colour);
                    g = qGreen(colour);
                    b = qBlue(colour);

                    G1r += this->mask1[index] * (double)r;
                    G2r += this->mask2[index] * (double)r;
                    G1g += this->mask1[index] * (double)g;
                    G2g += this->mask2[index] * (double)g;
                    G1b += this->mask1[index] * (double)b;
                    G2b += this->mask2[index] * (double)b;
                }
            }
            G1r = G1r / this->mask1[49];
            G2r = G2r / this->mask1[49];
            G1g = G1g / this->mask1[49];
            G2g = G2g / this->mask1[49];
            G1b = G1b / this->mask1[49];
            G2b = G2b / this->mask1[49];

            r = (int)round(G1r - G2r) + 128;
            if (r < 0) r = -r;
            if (r > 255) r = 255;
            g = (int)round(G1g - G2g) + 128;
            if (g < 0) g = -g;
            if (g > 255) g = 255;
            b = (int)round(G1b - G2b) + 128;
            if (b < 0) b = -b;
            if (b > 255) b = 255;

            output->setPixel(x, y, qRgb(r, g, b));
        }
    }
}

QString EdgeDoGCommand::label() {
    return "DoG edge detect";
}
