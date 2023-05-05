#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include <string>
#include <vector>

/*
 * Enumeration for Macrocommand class
 */
enum MacroErrors {
    MacroSuccess, MacroFail, sizeNotEqualFailure
};


class MacroCommand : public AbstractCommand {
public:
    MacroCommand(AbstractFileSystem*);
    ~MacroCommand();
    virtual int execute(std::string) override;
    void addCommand (AbstractCommand*);
    virtual void displayInfo() override;
    void setParseStrategy(AbstractParsingStrategy*);
private:
    AbstractFileSystem* afs;
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* aps;
};