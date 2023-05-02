#include "mockos/MacroCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;


MacroCommand::MacroCommand(SimpleFileSystem *parameter) {
    sfs = parameter;
}

void MacroCommand::displayInfo () {
    cout << "macro commmands executes several commands in order, it is invoked by typing in a sequence of commands." << endl;
}

int MacroCommand::execute(std::string input) {
    int spaceIndex1 = 0;
    int spaceIndex2 = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex1 = i;
            break;
        }
    }
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex2 = i;
        }
    }
}
