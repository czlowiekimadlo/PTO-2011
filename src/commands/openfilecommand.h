#ifndef OPENFILECOMMAND_H
#define OPENFILECOMMAND_H

#include <QString>
#include "basecommand.h"

class OpenFileCommand : public BaseCommand
{
public:
    OpenFileCommand(QString filename);

    void run(QImage * input, QImage * output);
    QString label();

private:
    QString filename;
};

#endif // OPENFILECOMMAND_H
