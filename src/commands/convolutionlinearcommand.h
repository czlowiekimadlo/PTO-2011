#ifndef CONVOLUTIONLINEARCOMMAND_H
#define CONVOLUTIONLINEARCOMMAND_H

#include "basecommand.h"
#include <math.h>

class ConvolutionLinearCommand : public BaseCommand
{
public:
    ConvolutionLinearCommand(int);

    void run(QImage * input, QImage * output);
    QString label();

private:
    int radius;
};

#endif // CONVOLUTIONLINEARCOMMAND_H
