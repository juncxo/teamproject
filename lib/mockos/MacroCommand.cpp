#include "mockos/MacroCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"
#include <sstream>
using namespace std;

/*
 * MacroCommand constructor to set the file system
 */
MacroCommand::MacroCommand(AbstractFileSystem *parameter) {
    afs = parameter;
    aps = nullptr;

}


void MacroCommand::setParseStrategy(AbstractParsingStrategy* str) {
    aps = str;
}

/*
 * Prints out the info on how macro works
 */
void MacroCommand::displayInfo () {
    cout << "macro commmands executes several commands in order, it is invoked by typing in a sequence of commands." << endl;
}

/*
 * Destructor for macrocommand to delete the commands added to the vector
 */
MacroCommand::~MacroCommand() {
    for (int i = 0; i < commands.size(); i++) {
        delete commands[i];
    }
    delete aps;
}


/*
 * Adding commands to the vector of commands to act as the instraction for which commands it will run
 */
void MacroCommand::addCommand (AbstractCommand* cmd) {
    commands.push_back(cmd);
}


/*
 * Function parses through the input to get the vector of strings to call execute on based on the commands
 */
int MacroCommand::execute(std::string input) {
    /*if (aps != nullptr) {
        return MacroFail;
    }*/

    
    //string inputWithoutTheCommand = input.substr(firstSpace+1, input.npos);
    vector <string> files = aps->parse(input);

    if (files.size() != commands.size()) {
        return sizeNotEqualFailure;
    }
    for (int i = 0; i < commands.size(); ++i) {

       int result = commands[i]->execute(files[i]);
       if(result != MacroSuccess){
           return MacroFail;
       }
    }
    return MacroSuccess;
}
