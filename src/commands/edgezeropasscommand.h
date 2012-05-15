#ifndef EDGEZEROPASSCOMMAND_H
#define EDGEZEROPASSCOMMAND_H

#include "basecommand.h"
#include <math.h>

class EdgeZeroPassCommand : public BaseCommand
{
public:
    EdgeZeroPassCommand();

    void run(QImage * input, QImage * output);
    QString label();

protected:
    int m[81];
};

#endif // EDGEZEROPASSCOMMAND_H
