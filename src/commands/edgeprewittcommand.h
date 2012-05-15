#ifndef EDGEPREWITTCOMMAND_H
#define EDGEPREWITTCOMMAND_H

#include "edgesobelcommand.h"
#include <math.h>

class EdgePrewittCommand : public EdgeSobelCommand
{
public:
    EdgePrewittCommand();

    QString label();
};

#endif // EDGEPREWITTCOMMAND_H
