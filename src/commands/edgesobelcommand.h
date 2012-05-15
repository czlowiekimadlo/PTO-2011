#ifndef EDGESOBELCOMMAND_H
#define EDGESOBELCOMMAND_H

#include "basecommand.h"
#include <math.h>

class EdgeSobelCommand : public BaseCommand
{
public:
    EdgeSobelCommand();

    void run(QImage * input, QImage * output);
    QString label();

protected:
    int mask[9];
};

#endif // EDGESOBELCOMMAND_H
