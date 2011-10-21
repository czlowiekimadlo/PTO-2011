#ifndef IMAGEFORMAT_H
#define IMAGEFORMAT_H

#include <QString>
#include <QImage>

class ImageFormat {

public:
    ImageFormat();
    virtual QImage * loadFile(QString fileName) = 0;
    virtual void saveFile(QString fileName, const QImage *image) = 0;

};

#endif // IMAGEFORMAT_H
