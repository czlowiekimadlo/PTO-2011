#ifndef CONVOLUTIONGAUSSIANCOMMAND_H
#define CONVOLUTIONGAUSSIANCOMMAND_H

#include "basecommand.h"
#include <math.h>

class ConvolutionGaussianCommand : public BaseCommand
{
public:
    ConvolutionGaussianCommand(int);

    void run(QImage * input, QImage * output);
    QString label();

private:
    int radius;
};

#endif // CONVOLUTIONGAUSSIANCOMMAND_H
