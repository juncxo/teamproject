#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"
#include <vector>
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    SimpleFileSystem* sfs = new SimpleFileSystem();
    AbstractCommand* ls = new LSCommand (sfs);

    CommandPrompt* cmd = new CommandPrompt();

    cmd->setFileSystem(sfs);
    cmd->addCommand("ls", ls);
    cmd->run();
    return 0;
}