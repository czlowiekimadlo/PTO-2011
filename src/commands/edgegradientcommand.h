#ifndef EDGEGRADIENTCOMMAND_H
#define EDGEGRADIENTCOMMAND_H

#include "basecommand.h"
#include <math.h>

class EdgeGradientCommand : public BaseCommand
{
public:
    EdgeGradientCommand();

    void run(QImage * input, QImage * output);
    QString label();

private:
    int mWidth;
    int mHeight;
    int mask[9];
};

#endif // EDGEGRADIENTCOMMAND_H
