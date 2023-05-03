#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/AbstractFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/AbstractFileSystem.h"

#include "mockos/SimpleFileFactory.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/TouchCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/EditDisplay.h"


#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/MacroCommand.h"

#include "mockos/CopyCommand.h"



#include <vector>
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    AbstractFileSystem* afs = new SimpleFileSystem();
    AbstractFileFactory* aff = new SimpleFileFactory();

    AbstractCommand* ls = new LSCommand (afs);
    AbstractCommand* rm = new RemoveCommand (afs);
    AbstractCommand* tc = new TouchCommand (afs, aff);
    AbstractCommand* cat = new CatCommand (afs);
    AbstractCommand* ds = new DisplayCommand (afs);
    AbstractCommand* cp = new CopyCommand (afs);
    MacroCommand* macro = new MacroCommand(afs);
    MacroCommand* macro2 = new MacroCommand(afs);


    macro->addCommand(cp);
    macro->addCommand(rm);

    macro2->addCommand(cat);
    macro2->addCommand(ds);

    AbstractParsingStrategy* rn = new RenameParsingStrategy ();
    macro->setParseStrategy(rn);

    AbstractParsingStrategy* cd = new EditDisplay ();
    macro2->setParseStrategy (cd);


    CommandPrompt* cmd = new CommandPrompt();
    TextFile* tf = new TextFile ("hello.txt");
    ImageFile* image = new ImageFile ("image1.img");
    ImageFile* image2 = new ImageFile ("image2.img");
    TextFile* tf2 = new TextFile ("hi.txt");


    afs->addFile("hello.txt", tf);
    afs->addFile("image1.img", image);
    afs->addFile("image2.img", image2);
    afs->addFile ("hi.txt", tf2);
    vector <char> vc = {'a', 'b', 'c', 'd', 'e'};
    vector <char> imageContents = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};

    tf2->write(vc);
    image->write(imageContents);
  //  sfs->openFile("hello.txt");
    // sfs->openFile ("image1.img");
  //  sfs->openFile ("image2.img");
   // sfs->openFile ("hi.txt");
    cmd->setFileSystem(afs);
    cmd->addCommand("ls", ls);
    cmd->addCommand("-m", ls);
    cmd->addCommand("rm", rm);
    cmd->addCommand("cat", cat);
    cmd->addCommand("ds", ds);
    cmd->addCommand("cp", cp);
    cmd->addCommand("touch", tc);
    cmd->addCommand("rn", macro);
    cmd->addCommand("cd", macro2);

    cmd->run();
    return 0;
}