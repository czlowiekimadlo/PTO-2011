#include "basecommand.h"

BaseCommand::BaseCommand()
{
    this->next = NULL;
}

BaseCommand::~BaseCommand()
{
    if (this->next != NULL)
    {
        delete this->next;
        this->next = NULL;
    }
}
