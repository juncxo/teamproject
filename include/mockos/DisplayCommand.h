#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include "BasicDisplayVisitor.h"
#include <string>

enum DisplayErrors {
    DisplaySuccess, InvalidFileType
};
class DisplayCommand : public AbstractCommand {
public:
    DisplayCommand(SimpleFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    SimpleFileSystem* sfs;
};