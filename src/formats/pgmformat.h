#ifndef PGMFORMAT_H
#define PGMFORMAT_H

#include <QString>
#include <QImage>
#include "imageFormat.h"

class PGMFormat : public ImageFormat
{
public:
    PGMFormat();
    QImage * loadFile(QString fileName);
    void saveFile(QString fileName, const QImage *image);
};

#endif // PGMFORMAT_H
