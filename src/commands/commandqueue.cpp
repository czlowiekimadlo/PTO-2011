#include "commandqueue.h"

CommandQueue::CommandQueue()
{
    this->depth = -1;
    this->size = 0;
    this->maxSize = -1;
    this->queue = NULL;
}
