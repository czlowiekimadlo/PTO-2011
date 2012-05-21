#include "noisemediancommand.h"

NoiseMedianCommand::NoiseMedianCommand()
{
}

void NoiseMedianCommand::run(QImage *input, QImage *output) {
    int w, h, ti, tj;
    int r[9], g[9], b[9];
    QRgb colour;

    w = input->width();
    h = input->height();

    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    ti = x + i - 1;
                    tj = y + j - 1;
                    if (ti < 0) ti = w - 1;
                    if (ti == w) ti = 0;
                    if (tj < 0) tj = h - 1;
                    if (tj == h) tj = 0;
                    colour = input->pixel(ti,tj);
                    r[j*3 + i] = qRed(colour);
                    g[j*3 + i] = qGreen(colour);
                    b[j*3 + i] = qBlue(colour);
                }
            }
            std::sort(r, r+9);
            std::sort(g, g+9);
            std::sort(b, b+9);
            output->setPixel(x, y, qRgb(r[5], g[5], b[5]));
        }
    }
}

QString NoiseMedianCommand::label()
{
    return "Remove noise - median";
}
