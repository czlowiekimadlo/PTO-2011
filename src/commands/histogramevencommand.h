#ifndef HISTOGRAMEVENCOMMAND_H
#define HISTOGRAMEVENCOMMAND_H

#include "basecommand.h"
#include <math.h>

class HistogramEvenCommand : public BaseCommand
{
public:
    HistogramEvenCommand(bool r, bool g, bool b);

    void run(QImage * input, QImage * output);
    QString label();

private:
    bool r;
    bool g;
    bool b;
};

#endif // HISTOGRAMEVENCOMMAND_H
