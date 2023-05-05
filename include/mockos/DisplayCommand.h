#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include "BasicDisplayVisitor.h"
#include <string>

enum DisplayErrors {
    DisplaySuccess,
    InvalidFileType,
    fileNull
};
class DisplayCommand : public AbstractCommand {
public:
    DisplayCommand(AbstractFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    AbstractFileSystem* sfs;
};