#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <string>

enum LSErrors {
    LSsuccess, LSfail, unknownFileType
};
class LSCommand : public AbstractCommand{
public:
    LSCommand(SimpleFileSystem*);
    virtual int run();
    virtual int execute(std::string) override;
    std::string getInput();
    virtual void displayInfo() override;
private:
    int longestFileName;
    int longestFileType;
    SimpleFileSystem* sfs;
};