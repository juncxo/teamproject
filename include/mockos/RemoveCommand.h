#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <string>

enum RemoveErrors {
    removeSuccess, unableToRemove
};
class RemoveCommand : public AbstractCommand{
public:
    RemoveCommand(SimpleFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    SimpleFileSystem* sfs;
};