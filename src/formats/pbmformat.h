#ifndef PBMFORMAT_H
#define PBMFORMAT_H

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
#include "imageFormat.h"

class PBMFormat : public ImageFormat
{
public:
    PBMFormat();
    QImage * loadFile(QString fileName);
    void saveFile(QString fileName, const QImage *image);
};

#endif // PBMFORMAT_H
