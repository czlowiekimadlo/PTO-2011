#ifndef PGMFORMAT_H
#define PGMFORMAT_H

#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>
#include <string>
#include <QString>
#include <QImage>
#include <QSize>
#include <QColor>
#include <QMessageBox>
#include <math.h>
#include "imageFormat.h"

class PGMFormat : public ImageFormat
{
public:
    PGMFormat();
    QImage * loadFile(QString fileName);
    void saveFile(QString fileName, const QImage *image);
};

#endif // PGMFORMAT_H
