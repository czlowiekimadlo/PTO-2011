#include "morpferosioncommand.h"

MorpfErosionCommand::MorpfErosionCommand(int w, int h, int x, int y, QString ma)
{
    QStringList lines;

    this->width = w;
    this->height = h;
    this->x = x;
    this->y = y;
    this->m = new int[w*h];

    lines = ma.split("\n");
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            if (lines.at(i).at(j) == '1') {
                this->m[i * w + j] = 1;
            }
            else {
                this->m[i * w + j] = 0;
            }
        }
    }
}

MorpfErosionCommand::~MorpfErosionCommand() {
    delete this->m;
}

void MorpfErosionCommand::run(QImage *input, QImage *output) {
    int w, h, ti, tj;
    bool accept;
    QRgb colour;

    w = input->width();
    h = input->height();

    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            accept = true;
            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < this->height; j++) {
                    if (this->m[j * this->height + i] == 0) continue;
                    ti = x + i - this->x + 1;
                    tj = y + j - this->y + 1;
                    if (ti < 0 || ti >= w || tj < 0 || tj >=h) continue;

                    colour = input->pixel(ti,tj);
                    if (qRed(colour) > 0 && this->m[j * this->width + i] == 1) {
                        accept = false;
                        break;
                    }
                }
                if (!accept) break;
            }
            if (!accept) {
                output->setPixel(x, y, qRgb(255, 255, 255));
            }
            else {
                output->setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    }
}

QString MorpfErosionCommand::label()
{
    return "Erosion";
}
