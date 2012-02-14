#ifndef GRAYSCALECOMMAND_H
#define GRAYSCALECOMMAND_H

#include "basecommand.h"
#include <math.h>


class GrayscaleCommand : public BaseCommand
{
public:
    GrayscaleCommand(int r, int g, int b);

    void run(QImage * input, QImage * output);
    QString label();

private:
    int r;
    int g;
    int b;

};

#endif // GRAYSCALECOMMAND_H
