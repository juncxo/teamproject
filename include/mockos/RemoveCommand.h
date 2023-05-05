#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <string>

/*
 * Enumeration for RemoveCommand class
 */
enum RemoveErrors {
    removeSuccess, unableToRemove
};


class RemoveCommand : public AbstractCommand{
public:
    RemoveCommand(AbstractFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    AbstractFileSystem* sfs;
};