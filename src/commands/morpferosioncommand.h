#ifndef MORPFEROSIONCOMMAND_H
#define MORPFEROSIONCOMMAND_H

#include "basecommand.h"
#include <QStringList>

class MorpfErosionCommand : public BaseCommand
{
public:
    MorpfErosionCommand(int, int, int, int, QString);
    ~MorpfErosionCommand();

    void run(QImage * input, QImage * output);
    QString label();

protected:
    int width;
    int height;
    int x;
    int y;
    int * m;
};

#endif // MORPFEROSIONCOMMAND_H
