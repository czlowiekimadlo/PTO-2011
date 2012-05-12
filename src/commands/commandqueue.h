#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <QImage>
#include <iostream>
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
    int getSize();

private:
    int depth;
    int size;
    int maxSize;
    BaseCommand * queue;

    void copyImage(QImage *, QImage *);
};

#endif // COMMANDQUEUE_H
