#ifndef HISTOGRAMSTRETCHCOMMAND_H
#define HISTOGRAMSTRETCHCOMMAND_H

#include "basecommand.h"

class HistogramStretchCommand : public BaseCommand
{
public:
    HistogramStretchCommand();

    void run(QImage * input, QImage * output);
    QString label();
};

#endif // HISTOGRAMSTRETCHCOMMAND_H
