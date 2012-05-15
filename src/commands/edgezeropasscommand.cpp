#include "edgezeropasscommand.h"
#include <iostream>

EdgeZeroPassCommand::EdgeZeroPassCommand()
{
    /*************************
     * This is madness!
     * Madnes? THIS IS PTO!!!
     *************************/
    this->m[0]=0; this->m[1]=1; this->m[2]=1; this->m[3]=2; this->m[4]=2; this->m[5]=2;
    this->m[6]=1; this->m[7]=1; this->m[8]=0;
    this->m[9]=1; this->m[10]=2; this->m[11]=4; this->m[12]=5; this->m[13]=5;
    this->m[14]=5; this->m[15]=4; this->m[16]=2; this->m[17]=1;
    this->m[18]=1; this->m[19]=4; this->m[20]=5; this->m[21]=3; this->m[22]=0;
    this->m[23]=3; this->m[24]=5; this->m[25]=4; this->m[26]=1;
    this->m[27]=2; this->m[28]=5; this->m[29]=3; this->m[30]=-12; this->m[31]=-24;
    this->m[32]=-12; this->m[33]=3; this->m[34]=5; this->m[35]=2;
    this->m[36]=2; this->m[37]=5; this->m[38]=0; this->m[39]=-24; this->m[40]=-50;
    this->m[41]=-24; this->m[42]=0; this->m[43]=5; this->m[44]=2;
    this->m[45]=2; this->m[46]=5; this->m[47]=3; this->m[48]=-12; this->m[49]=-24;
    this->m[50]=-12; this->m[51]=3; this->m[52]=5; this->m[53]=2;
    this->m[54]=1; this->m[55]=4; this->m[56]=5; this->m[57]=3; this->m[58]=0;
    this->m[59]=3; this->m[60]=5; this->m[61]=4; this->m[62]=1;
    this->m[63]=1; this->m[64]=2; this->m[65]=4; this->m[66]=5; this->m[67]=5;
    this->m[68]=5; this->m[69]=4; this->m[70]=2; this->m[71]=1;
    this->m[72]=0; this->m[73]=1; this->m[74]=1; this->m[75]=2; this->m[76]=2;
    this->m[77]=2; this->m[78]=1; this->m[79]=1; this->m[80]=0;


}

void EdgeZeroPassCommand::run(QImage *input, QImage *output) {
    int *temporary;
    int w, h;
    int r, r2, g, g2, b, b2, sr, sg, sb;
    int r3, g3, b3;
    QRgb colour;
    int index;

    w = input->width();
    h = input->height();

    temporary = new int[w*h*3];

    // first pass, calculate LoG
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            sr = sg = sb = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (x+i-4 < 0 || x+i-4 >= w || y+j-4 < 0 || y+j-4 >=h) continue;

                    colour = input->pixel(x+i-4,y+j-4);
                    sr += qRed(colour) * this->m[j*9+i];
                    sg += qGreen(colour) * this->m[j*9+i];
                    sb += qBlue(colour) * this->m[j*9+i];
                }
            }
            index = (y * w + x) * 3;
            temporary[index]     = sr;
            temporary[index + 1] = sg;
            temporary[index + 2] = sb;
        }
    }

    std::cout << "first pass ok" << std::endl;

    // second pass, find zero pass points
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {

            index = (y * w + x) * 3;
            r = temporary[index];
            g = temporary[index + 1];
            b = temporary[index + 2];
            sr = sg = sb = 0;

            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (x+i < 0 || x+i >= w || y+j < 0 || y+j >=h || (x == 0 && y == 0)) continue;

                    index = ((y + j) * w + x + i) * 3;
                    r2 = temporary[index];
                    g2 = temporary[index + 1];
                    b2 = temporary[index + 2];

                    if (r * r2 < 0) {
                        if (r < 0)  r3 = -r; else r3 = r;
                        if (r2 < 0) r2 = -r2;
                        if (r3 <= r2) {
                            sr = sg = sb = 255;
                            break;
                        }
                    }
                    if (g * g2 < 0) {
                        if (g < 0)  g3 = -g; else g3 = g;
                        if (g2 < 0) g2 = -g2;
                        if (g3 <= r2) {
                            sr = sg = sb = 255;
                            break;
                        }
                    }
                    if (b * b2 < 0) {
                        if (b < 0)  b3 = -b; else b3 = b;
                        if (b2 < 0) b2 = -b2;
                        if (b3 <= b2) {
                            sr = sg = sb = 255;
                            break;
                        }
                    }
                }
                if (sr > 0) break;
            }

            output->setPixel(x, y, qRgb(sr, sg, sb));
        }
    }

    delete temporary;
}

QString EdgeZeroPassCommand::label()
{
    return "Zero-pass edge detect";
}
