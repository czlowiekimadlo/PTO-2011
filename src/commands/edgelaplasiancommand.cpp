#include "edgelaplasiancommand.h"

EdgeLaplasianCommand::EdgeLaplasianCommand() : ConvolutionFreeCommand(3, 3, 1, 1, "0 1 0\n1 -4 1\n0 1 0")
{
}

QString EdgeLaplasianCommand::label()
{
    return "Laplasian edge detect";
}
