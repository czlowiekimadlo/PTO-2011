#ifndef BINARYCOMMAND_H
#define BINARYCOMMAND_H

#include "basecommand.h"
#include <math.h>

class BinaryCommand : public BaseCommand
{
public:
    BinaryCommand();

    void run(QImage * input, QImage * output);
    QString label();
};

#endif // BINARYCOMMAND_H
