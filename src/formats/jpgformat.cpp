#include "jpgformat.h"

JPGFormat::JPGFormat()
{

}

QImage * JPGFormat::loadFile(QString fileName)
{
    QImage * image = new QImage(fileName);

    return image;
}

void JPGFormat::saveFile(QString fileName, const QImage *image)
{
    image->save(fileName, "JPG");
}
