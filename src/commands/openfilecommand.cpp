#include "openfilecommand.h"

OpenFileCommand::OpenFileCommand(QString filename) : BaseCommand()
{
    this->filename = filename;
}

void OpenFileCommand::run(QImage *input, QImage *output)
{
    // do nothing
}

QString OpenFileCommand::label()
{
    return "Open " + this->filename;
}
