#ifndef CONTRASTCOMMAND_H
#define CONTRASTCOMMAND_H

#include "basecommand.h"
#include <math.h>

class ContrastCommand : public BaseCommand
{
public:
    ContrastCommand(double);

    void run(QImage * input, QImage * output);
    QString label();

private:
    double value;
};

#endif // CONTRASTCOMMAND_H
