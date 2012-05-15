#include "edgelogcommand.h"

EdgeLoGCommand::EdgeLoGCommand() : ConvolutionFreeCommand(9, 9, 5, 5,
"0 1 1 2 2 2 1 1 0\n\
1 2 4 5 5 5 4 2 1\n\
1 4 5 3 0 3 5 4 1\n\
2 5 3 -12 -24 -12 3 5 2\n\
2 5 0 -24 -50 -24 0 5 2\n\
2 5 3 -12 -24 -12 3 5 2\n\
1 4 5 3 0 3 5 4 1\n\
1 2 4 5 5 5 4 2 1\n\
0 1 1 2 2 2 1 1 0")
{
}

QString EdgeLoGCommand::label()
{
    return "LoG edge detect";
}
