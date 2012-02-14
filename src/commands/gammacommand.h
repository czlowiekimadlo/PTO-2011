#ifndef GAMMACOMMAND_H
#define GAMMACOMMAND_H

#include "basecommand.h"
#include <math.h>

class GammaCommand : public BaseCommand
{
public:
    GammaCommand(double);

    void run(QImage * input, QImage * output);
    QString label();

private:
    double value;
};

#endif // GAMMACOMMAND_H
