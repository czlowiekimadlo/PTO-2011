#ifndef EDGELOGCOMMAND_H
#define EDGELOGCOMMAND_H

#include "convolutionfreecommand.h"
#include <math.h>

class EdgeLoGCommand : public ConvolutionFreeCommand
{
public:
    EdgeLoGCommand();

    QString label();
};

#endif // EDGELOGCOMMAND_H
