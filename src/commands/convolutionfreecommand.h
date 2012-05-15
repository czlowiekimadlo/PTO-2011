#ifndef CONVOLUTIONFREECOMMAND_H
#define CONVOLUTIONFREECOMMAND_H

#include "basecommand.h"
#include <math.h>
#include <QStringList>

class ConvolutionFreeCommand : public BaseCommand
{
public:
    ConvolutionFreeCommand(int, int, int, int, QString);

    void run(QImage * input, QImage * output);
    QString label();

protected:
    int width;
    int height;
    int anchorX;
    int anchorY;
    QString matrix;
};

#endif // CONVOLUTIONFREECOMMAND_H
