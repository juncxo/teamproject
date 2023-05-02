#pragma once
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include <string>
#include <vector>

enum MacroErrors {
    MacroSuccess, MacroFail
};
class MacroCommand : public AbstractCommand, AbstractParsingStrategy {
public:
    MacroCommand(SimpleFileSystem*);
    virtual int execute(std::string) override;
    virtual void displayInfo() override;
private:
    SimpleFileSystem* sfs;
    std::vector<AbstractCommand> commands;
    AbstractParsingStrategy* aps;
};