#ifndef MORPHDILATIONCOMMAND_H
#define MORPHDILATIONCOMMAND_H

#include "basecommand.h"
#include <QStringList>

class MorphDilationCommand : public BaseCommand
{
public:
    MorphDilationCommand(int, int, int, int, QString);
    ~MorphDilationCommand();

    void run(QImage * input, QImage * output);
    QString label();

protected:
    int width;
    int height;
    int x;
    int y;
    int * m;
};

#endif // MORPHDILATIONCOMMAND_H
