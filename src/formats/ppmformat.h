#ifndef PPMFORMAT_H
#define PPMFORMAT_H

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

class PPMFormat : public ImageFormat
{
public:
    PPMFormat();
    QImage * loadFile(QString fileName);
    void saveFile(QString fileName, const QImage *image);
};

#endif // PPMFORMAT_H
