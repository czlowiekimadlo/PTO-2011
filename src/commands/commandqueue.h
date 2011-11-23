#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <QImage>
#include "basecommand.h"

class CommandQueue
{
public:
    CommandQueue();
    void push(BaseCommand * command);
    void cut(int depth);
    void run(QImage * input, QImage * output);

private:
    int depth;
    int size;
    int maxSize;
    BaseCommand * queue;
};

#endif // COMMANDQUEUE_H
