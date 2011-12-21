#ifndef HISTOGRAMSTRETCHCOMMAND_H
#define HISTOGRAMSTRETCHCOMMAND_H

#include "basecommand.h"
#include <math.h>

class HistogramStretchCommand : public BaseCommand
{
public:
    HistogramStretchCommand(bool r, bool g, bool b);

    void run(QImage * input, QImage * output);
    QString label();

private:
    bool r;
    bool g;
    bool b;

};

#endif // HISTOGRAMSTRETCHCOMMAND_H
