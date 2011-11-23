#include "pbmformat.h"

PBMFormat::PBMFormat()
{

}

QImage * PBMFormat::loadFile(QString fileName) {
    std::ifstream file;
    QByteArray ba = fileName.toLocal8Bit();

    char *buffer = new char[2];
    int letter, k;
    int width = 0, height = 0;
    int tailingBits, rowSize;
    QImage * image;
    QSize imageSize;
    QColor white;
    QColor black;

    //setup colors
    white.setNamedColor("#FFF");
    black.setNamedColor("#000");

    //open file
    file.open(ba.data(), std::fstream::binary);
    if (file.fail()) {
        delete buffer;
        throw 0;
    }

    //read file format
    file.read(buffer, 2 * sizeof(char));
    if (buffer[0] != 'P' || buffer[1] != '4' || file.fail()) {
        file.close();
        delete buffer;
        throw 1;
    }

    //read comments and whitespace
    while(true) {
        letter = file.peek();
        if (isspace(letter)) {
            file.get();
        }
        else if (letter == 35) {
            do {
                letter = file.get();
            }
            while (letter != 10);
        }
        else break;
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
        throw 4;
    }

    //prepare image for data
    imageSize.setWidth(width);
    imageSize.setHeight(height);
    image = new QImage((const QSize &)imageSize, QImage::Format_RGB32);
    image->fill(0);

    //read raster
    rowSize = width / 8;
    tailingBits = width % 8;
    if (tailingBits > 0) rowSize++;
    buffer = new char[rowSize];
    for (int i = 0; i < height; i++) {
        file.read(buffer, rowSize * sizeof(char));
        k = 0;
        for (int j = 0; j < width; j++) {
            if (j > 0 && (j % 8) == 0) k++;
            if (buffer[k] & (128 >> (j % 8))) {
                image->setPixel(j, i, black.rgb());
            }
            else {
                image->setPixel(j, i, white.rgb());
            }
        }
    }

    //cleanup
    file.close();
    delete buffer;

    return image;
}

void PBMFormat::saveFile(QString fileName, const QImage *image) {
    if (image == NULL) {
        throw 0;
    }

    char endline = '\n';
    char *buffer;
    int tailingBits, rowSize, k;
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

    //write file format info
    file.write("P4", 2*sizeof(char));
    //write whitespace
    file.write(&endline, sizeof(char));
    if (file.fail()) {
        throw 2;
    }

    //write comment
    file.write("#created with Base", 18 * sizeof(char));
    file.write(&endline, sizeof(char));
    if (file.fail()) {
        throw 3;
    }


    //write width and height
    lineBuffer.flush();
    lineBuffer << width << " " << height;
    file.write(lineBuffer.str().c_str(), lineBuffer.str().length() * sizeof(char));
    file.write(&endline, sizeof(char));
    if (file.fail()) {
        throw 4;
    }


    //write data
    rowSize = image->width() / 8;
    tailingBits = image->width() % 8;
    if (tailingBits > 0) rowSize++;
    buffer = new char[rowSize];

    for (int i = 0; i < height; i++) {
        k = 0;
        buffer[k] = 0;
        for (int j = 0; j < width; j++) {
            if (j > 0 && (j % 8) == 0) {
                k++;
                buffer[k] = 0;
            }
            if (image->pixel(j, i) % 0x01000000 == 0) {
                buffer[k] = buffer[k] | (128 >> j % 8);
            }
            else {
                buffer[k] = buffer[k] & ~(128 >> j % 8);
            }
        }
        file.write(buffer, rowSize * sizeof(char));
    }

    //finished
    file.close();
    delete buffer;
}
