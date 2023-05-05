#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

/*
 * Enumeration for the TouchCommand class
 */
enum touch {
    touchCommandSuccess,fileNotCreatedSuccessfully,couldNotAddFile
};


class TouchCommand : public AbstractCommand{
public:
    TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
    virtual ~TouchCommand() = default;
    virtual int execute(std::string);
    virtual void displayInfo();
private:
    AbstractFileSystem* touchSystem;
    AbstractFileFactory* touchFactory;
};