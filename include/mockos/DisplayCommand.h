#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <string>

enum DisplayErrors {
    DisplaySuccess, DisplayFail
};
class DisplayCommand : public AbstractCommand {
public:
    DisplayCommand(SimpleFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    SimpleFileSystem* sfs;
};