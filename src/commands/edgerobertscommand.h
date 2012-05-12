#ifndef EDGEROBERTSCOMMAND_H
#define EDGEROBERTSCOMMAND_H

#include "basecommand.h"
#include <math.h>

class EdgeRobertsCommand : public BaseCommand
{
public:
    EdgeRobertsCommand();

    void run(QImage * input, QImage * output);
    QString label();

private:
    int mask[4];
};

#endif // EDGEROBERTSCOMMAND_H
