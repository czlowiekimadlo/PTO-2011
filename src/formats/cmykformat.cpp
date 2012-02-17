#include "cmykformat.h"

CMYKFormat::CMYKFormat()
{
}

QImage * CMYKFormat::loadFile(QString fileName) {
    std::ifstream file;
    QByteArray ba = fileName.toLocal8Bit();

    char *buffer = new char[2];
    int letter;
    unsigned char c, m, y, k, r, g, b;
    int width = 0, height = 0;
    int rowSize;
    QImage * image;
    QSize imageSize;
    QColor colour;

    //open file
    file.open(ba.data(), std::fstream::binary);
    if (file.fail()) {
        delete buffer;
        throw 0;
    }

    //read width
    while(true) {
        letter = file.peek();

        if (isspace(letter)) break;

        if (letter > 47 && letter < 58) {
            width = width * 10 + (letter - 48);
        }
        else {
            file.close();
            delete buffer;
            throw 2;
        }
        file.get();
    }

    //read dimensions separator whitespace
    while(true) {
        letter = file.peek();
        if (isspace(letter)) {
            file.get();
        }
        else break;
    }

    //read height
    while(true) {
        letter = file.peek();

        if (isspace(letter)) break;

        if (letter > 47 && letter < 58) {
            height = height * 10 + (letter - 48);
        }
        else {
            file.close();
            delete buffer;
            throw 3;
        }
        file.get();
    }

    //read header delimeter whitespace
    letter = file.get();
    if (!isspace(letter)) {
        file.close();
        delete buffer;
        throw 5;
    }

    //prepare image for data
    imageSize.setWidth(width);
    imageSize.setHeight(height);
    image = new QImage((const QSize &)imageSize, QImage::Format_RGB32);
    image->fill(0);
    delete buffer;

    //read raster
    rowSize = width * 4;
    buffer = new char[rowSize];
    for (int i = 0; i < height; i++) {
        file.read(buffer, rowSize * sizeof(char));
        for (int j = 0; j < width; j++) {
            c = buffer[j * 4];
            m = buffer[j * 4 + 1];
            y = buffer[j * 4 + 2];
            k = buffer[j * 4 + 3];

            if (k < 255) {
                r = (int)round((double)((255 - c) * (255 - k)) / 255.0);
                g = (int)round((double)((255 - m) * (255 - k)) / 255.0);
                b = (int)round((double)((255 - y) * (255 - k)) / 255.0);
            } else {
                r = 255 - c;
                g = 255 - m;
                b = 255 - y;
            }

            colour.setRgb(r, g, b);
            image->setPixel(j, i, colour.rgb());
        }
    }

    //cleanup
    file.close();
    delete buffer;

    return image;
}

void CMYKFormat::saveFile(QString fileName, const QImage *image) {
    if (image == NULL) {
        throw 0;
    }

    char endline = '\n';
    char *buffer;
    int rowSize;
    char c, m, y, k, r, g, b;
    int width = image->width();
    int height = image->height();
    std::ostringstream lineBuffer;
    std::ofstream file;
    QByteArray ba = fileName.toLocal8Bit();

    //open file
    file.open(ba.data(), std::ofstream::binary | std::ofstream::trunc);
    if (file.fail()) {
        throw 1;
    }

    //write width, height and max value
    lineBuffer.flush();
    lineBuffer << width << " " << height << endline;
    file.write(lineBuffer.str().c_str(), lineBuffer.str().length() * sizeof(char));
    if (file.fail()) {
        throw 4;
    }


    //write data
    rowSize = image->width() * 4;
    buffer = new char[rowSize];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            r = qRed(image->pixel(j, i));
            g = qGreen(image->pixel(j, i));
            b = qBlue(image->pixel(j, i));

            if (r >= g && r >= b)
            {
                k = 255 - r;
            }
            else if (g >= r && g >= b)
            {
                k = 255 - g;
            }
            else
            {
                k = 255 - b;
            }

            if (k < 255) {
               c = (char)round((double)(255 - r - k)/(double)(255 - k));
               m = (char)round((double)(255 - g - k)/(double)(255 - k));
               y = (char)round((double)(255 - b - k)/(double)(255 - k));
            } else {
               c = 255 - r;
               m = 255 - g;
               y = 255 - b;
            }

            buffer[j * 4] = c;
            buffer[j * 4 + 1] = m;
            buffer[j * 4 + 2] = y;
            buffer[j * 4 + 3] = k;
        }
        file.write(buffer, rowSize * sizeof(char));
    }

    //finished
    file.close();
    delete buffer;
}
