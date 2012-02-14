#ifndef BRIGHTNESSCOMMAND_H
#define BRIGHTNESSCOMMAND_H

#include "basecommand.h"

class BrightnessCommand : public BaseCommand
{
public:
    BrightnessCommand(int);

    void run(QImage * input, QImage * output);
    QString label();

private:
    int value;
};

#endif // BRIGHTNESSCOMMAND_H
