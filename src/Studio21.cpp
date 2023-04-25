#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include <vector>
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    AbstractFileSystem* sfs = new SimpleFileSystem();
    AbstractFileFactory* sff = new SimpleFileFactory();
    TouchCommand* tc = new TouchCommand (sfs, sff);
    CommandPrompt* cmd = new CommandPrompt();
    cmd->setFileSystem(sfs);
    cmd->setFileFactory(sff);
    cmd->addCommand("touch", tc);
    cmd->addCommand("visitor", tc);
    cmd->run();
    return 0;
}