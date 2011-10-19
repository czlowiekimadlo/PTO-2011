#ifndef IMAGEFORMAT_H
#define IMAGEFORMAT_H

#include <QString>

class ImageFormat {

public:
    ImageFormat(QString *fileName = NULL);
    virtual void loadFile(QString *fileName) = 0;
    virtual void saveFile(QString *fileName) = 0;

};

#endif // IMAGEFORMAT_H
