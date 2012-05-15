#ifndef EDGELAPLASIANCOMMAND_H
#define EDGELAPLASIANCOMMAND_H

#include "convolutionfreecommand.h"
#include <math.h>

class EdgeLaplasianCommand : public ConvolutionFreeCommand
{
public:
    EdgeLaplasianCommand();

    QString label();
};

#endif // EDGELAPLASIANCOMMAND_H
