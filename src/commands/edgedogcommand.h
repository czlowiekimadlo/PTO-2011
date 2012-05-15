#ifndef EDGEDOGCOMMAND_H
#define EDGEDOGCOMMAND_H

#include "basecommand.h"
#include <math.h>

class EdgeDoGCommand : public BaseCommand
{
public:
    EdgeDoGCommand(double, double);

    void run(QImage * input, QImage * output);
    QString label();

protected:
    double mask1[50];
    double mask2[50];
};

#endif // EDGEDOGCOMMAND_H
