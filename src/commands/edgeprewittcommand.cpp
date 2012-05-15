#include "edgeprewittcommand.h"

EdgePrewittCommand::EdgePrewittCommand()
{
    this->mask[0] =  1; this->mask[1] =  1; this->mask[2] =  1;
    this->mask[3] =  0; this->mask[4] =  0; this->mask[5] =  0;
    this->mask[6] = -1; this->mask[7] = -1; this->mask[8] = -1;
}

QString EdgePrewittCommand::label()
{
    return "Perwitt edge detect";
}
