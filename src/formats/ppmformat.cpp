#include "ppmformat.h"

PPMFormat::PPMFormat()
{
}

QImage * PPMFormat::loadFile(QString fileName) {
    std::ifstream file;
    QByteArray ba = fileName.toLocal8Bit();

    char *buffer = new char[2];
    int letter;
    unsigned char r, g, b;
    int width = 0, height = 0, maxValue = 0;
    int rowSize;
    QImage * image;
    QSize imageSize;
    QColor colour;
    short int bits;

    //open file
    file.open(ba.data(), std::fstream::binary);
    if (file.fail()) {
        delete buffer;
        throw 0;
    }

    //read file format
    file.read(buffer, 2 * sizeof(char));
    if (buffer[0] != 'P' || buffer[1] != '6' || file.fail()) {
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

    //read max value separator whitespace
    while(true) {
        letter = file.peek();
        if (isspace(letter)) {
            file.get();
        }
        else break;
    }

    //read max value
    while(true) {
        letter = file.peek();

        if (isspace(letter)) break;

        if (letter > 47 && letter < 58) {
            maxValue = maxValue * 10 + (letter - 48);
        }
        else {
            file.close();
            delete buffer;
            throw 3;
        }
        file.get();
    }
    if (maxValue > 65536) {
        file.close();
        delete buffer;
        throw 4;
    }
    if (maxValue > 255) {
        bits = 2;
    }
    else {
        bits = 1;
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

    //read raster
    rowSize = width * bits * 3;
    buffer = new char[rowSize];
    for (int i = 0; i < height; i++) {
        file.read(buffer, rowSize * sizeof(char));
        for (int j = 0; j < width; j++) {
            r = buffer[j * 3 * bits];
            g = buffer[j * 3 * bits + 1];
            b = buffer[j * 3 * bits + 2];
            colour.setRgb(r, g, b);
            image->setPixel(j, i, colour.rgb());
        }
    }

    //cleanup
    file.close();
    delete buffer;

    return image;
}

void PPMFormat::saveFile(QString fileName, const QImage *image) {
    if (image == NULL) {
        throw 0;
    }

    char endline = '\n';
    char *buffer;
    int rowSize;
    char r, g, b;
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
    file.write("P6", 2*sizeof(char));
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


    //write width, height and max value
    lineBuffer.flush();
    lineBuffer << width << " " << height << endline << 255;
    file.write(lineBuffer.str().c_str(), lineBuffer.str().length() * sizeof(char));
    file.write(&endline, sizeof(char));
    if (file.fail()) {
        throw 4;
    }


    //write data
    rowSize = image->width() * 3;
    buffer = new char[rowSize];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            r = qRed(image->pixel(j, i));
            g = qGreen(image->pixel(j, i));
            b = qBlue(image->pixel(j, i));
            buffer[j * 3] = r;
            buffer[j * 3 + 1] = g;
            buffer[j * 3 + 2] = b;
        }
        file.write(buffer, rowSize * sizeof(char));
    }

    //finished
    file.close();
    delete buffer;
}
