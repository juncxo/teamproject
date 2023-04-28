#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/AbstractFile.h"
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
    TextFile* tf = new TextFile ("hello.txt");
    ImageFile* image = new ImageFile ("image1.img");
    ImageFile* image2 = new ImageFile ("image2.img");
    TextFile* tf2 = new TextFile ("hi.txt");


    sfs->addFile("hello.txt", tf);
    sfs->addFile("image1.img", image);
    sfs->addFile("image2.img", image2);
    sfs->addFile ("hi.txt", tf2);
    sfs->openFile("hello.txt");
    sfs->openFile ("image1.img");
    sfs->openFile ("image2.img");
    sfs->openFile ("hi.txt");
    cmd->setFileSystem(sfs);
    cmd->addCommand("ls", ls);
    cmd->addCommand("ls -m", ls);
    cmd->run();
    return 0;
}