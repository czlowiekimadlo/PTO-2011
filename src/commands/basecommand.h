#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include <QImage>
#include <QString>

class BaseCommand
{
public:
    BaseCommand();

    BaseCommand * next;

    virtual void run(QImage * input, QImage * output) = 0;
    virtual QString label() = 0;
};

#endif // BASECOMMAND_H
