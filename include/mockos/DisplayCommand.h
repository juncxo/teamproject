#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include "BasicDisplayVisitor.h"
#include <string>

/*
 * Enumeration for DisplayCommand class
 */
enum DisplayErrors {
    DisplaySuccess,
    InvalidFileType,
    fileNull,
    invalidFileName
};
class DisplayCommand : public AbstractCommand {
public:
    DisplayCommand(AbstractFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    AbstractFileSystem* sfs;
};