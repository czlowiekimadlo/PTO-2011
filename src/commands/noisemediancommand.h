#ifndef NOISEMEDIANCOMMAND_H
#define NOISEMEDIANCOMMAND_H

#include "basecommand.h"
#include <math.h>
#include <algorithm>

class NoiseMedianCommand : public BaseCommand
{
public:
    NoiseMedianCommand();

    void run(QImage * input, QImage * output);
    QString label();
};

#endif // NOISEMEDIANCOMMAND_H
