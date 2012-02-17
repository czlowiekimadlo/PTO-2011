#ifndef CMYKFORMAT_H
#define CMYKFORMAT_H

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

class CMYKFormat : public ImageFormat
{
public:
    CMYKFormat();

    QImage * loadFile(QString fileName);
    void saveFile(QString fileName, const QImage *image);
};

#endif // CMYKFORMAT_H
