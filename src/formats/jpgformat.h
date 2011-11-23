#ifndef JPGFORMAT_H
#define JPGFORMAT_H

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

class JPGFormat : public ImageFormat
{
public:
    JPGFormat();
    QImage * loadFile(QString fileName);
    void saveFile(QString fileName, const QImage *image);
};

#endif // JPGFORMAT_H
