#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <string>

enum LSErrors {
    LSsuccess, LSfail, unknownFileType
};
class LSCommand : public AbstractCommand{
public:
    LSCommand(AbstractFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    int longestFileName;
    int longestFileType;
    AbstractFileSystem* sfs;
};