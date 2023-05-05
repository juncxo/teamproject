#pragma once
#include <string>
#include <map>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

/*
 * Enumeration for the CommandPrompt class
 */
enum command{
    commandSuccess,
    failedToInsert,
    userQuit,
};

class CommandPrompt{
public:
    CommandPrompt();
    virtual ~CommandPrompt() = default;
    virtual void setFileSystem(AbstractFileSystem*);
    virtual void setFileFactory(AbstractFileFactory*);
    virtual int addCommand(std::string, AbstractCommand*);
    virtual int run();

protected:
    virtual void listCommands();
    virtual std::string prompt();
private:
    std::map<std::string, AbstractCommand*> commandMap;
    AbstractFileSystem* commandSystem;
    AbstractFileFactory* commandFactory;
};