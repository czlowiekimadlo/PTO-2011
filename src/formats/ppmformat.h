#ifndef PPMFORMAT_H
#define PPMFORMAT_H

#include <QString>
#include <QImage>
#include "imageFormat.h"

class PPMFormat : public ImageFormat
{
public:
    PPMFormat();
    QImage * loadFile(QString fileName);
    void saveFile(QString fileName, const QImage *image);
};

#endif // PPMFORMAT_H
