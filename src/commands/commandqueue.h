#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <QImage>
#include "basecommand.h"

class CommandQueue
{
public:
    CommandQueue();
    ~CommandQueue();
    void push(BaseCommand * command);
    void pop();
    void cut(int depth);
    void flush();
    void run(QImage * input, QImage * output, int depth);
    void run(QImage * input, QImage *output);
    BaseCommand * giveHead();

private:
    int depth;
    int size;
    int maxSize;
    BaseCommand * queue;
};

#endif // COMMANDQUEUE_H
