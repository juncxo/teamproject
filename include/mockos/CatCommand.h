#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <string>

enum CatErrors {
    Catsuccess,
    Catfail,
    cannotAppend,
    fileNoExist
};
class CatCommand : public AbstractCommand {
public:
    CatCommand(AbstractFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    AbstractFileSystem* sfs;
};