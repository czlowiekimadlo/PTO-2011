#include "commandqueue.h"

CommandQueue::CommandQueue()
{
    this->queue = NULL;
    this->maxSize = -1;
    this->flush();
}

CommandQueue::~CommandQueue()
{
    this->flush();
}

void CommandQueue::push(BaseCommand *command)
{
    if (this->queue == NULL)
    {
        this->queue = command;
        this->size = 1;
        this->depth = 1;
    }
    else
    {
        if (this->depth < this->size)
        {
            this->cut(this->depth);
        }
        this->size++;

        BaseCommand * element;
        element = this->queue;
        while(true)
        {
            if (element->next != NULL) {
                element = element->next;
            }
            else break;
        }

    }
}

void CommandQueue::pop()
{
    if (this->queue == NULL)
    {
        return;
    }

    if (this->queue->next == NULL)
    {
        delete this->queue;
        this->queue = NULL;
        this->size = 0;
        this->depth = -1;
    }

    BaseCommand * element;
    element = this->queue;
    while(true)
    {
        if (element->next->next != NULL) {
            element = element->next;
        }
        else break;
    }
    delete element->next;
    this->size--;
}

void CommandQueue::cut(int depth)
{
    if (depth < 1)
    {
        return;
    }

    BaseCommand * element;
    element = this->queue;
    for (int i = 1; i < depth; i++)
    {
        element = element->next;
    }
    if (element->next != NULL)
    {
        delete element->next;
        element->next = NULL;
    }

    this->size = depth;
    this->depth = -1;
}

void CommandQueue::flush()
{
    if (this->queue != NULL)
    {
        delete this->queue;
    }
    this->depth = -1;
    this->size = 0;
    this->queue = NULL;
}

void CommandQueue::run(QImage *input, QImage *output, int depth)
{

}

void CommandQueue::run(QImage *input, QImage *output)
{
    this->run(input, output, this->size);
}

BaseCommand * CommandQueue::giveHead()
{
    return this->queue;
}


