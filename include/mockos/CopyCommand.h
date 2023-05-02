#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <string>

enum CopyErrors {
    CopySuccess, InvalidFileExtension, failedToAddCopy
};
class CopyCommand : public AbstractCommand {
public:
    CopyCommand(SimpleFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    SimpleFileSystem* sfs;
};