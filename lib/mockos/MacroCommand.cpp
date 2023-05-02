#include "mockos/MacroCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"
#include <sstream>
using namespace std;


MacroCommand::MacroCommand(AbstractFileSystem *parameter) {
    afs = parameter;
    aps = nullptr;

}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* str) {
    aps = str;
}

void MacroCommand::displayInfo () {
    cout << "macro commmands executes several commands in order, it is invoked by typing in a sequence of commands." << endl;
}

MacroCommand::~MacroCommand() {
    for (int i = 0; i < commands.size(); i++) {
        delete commands[i];
    }
    delete aps;
}

void MacroCommand::addCommand (AbstractCommand* cmd) {
    commands.push_back(cmd);
}

/*

std::vector<std::string> AbstractParsingStrategy::parse (std::string str) {
    vector <string> returnedVector;
    int numberOfWords = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            numberOfWords++;
        }
    }
    istringstream iss (str);
    for (int i = 0; i < numberOfWords; i++) {
        string vectorValue;
        iss >> vectorValue;
        returnedVector.push_back (vectorValue);
    }
    return returnedVector;
}

*/

int MacroCommand::execute(std::string input) {
    if (aps != nullptr) {
        return MacroFail;
    }


/*
    int finalSpaceIndex = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            finalSpaceIndex = i;
        }
    }

    string inputWithoutTheFileName = input.substr(0, finalSpaceIndex-1);
    string fileName = input.substr(finalSpaceIndex+1, input.npos);
*/

    vector <string> listOfCommands = aps->parse(input);
    if (listOfCommands.size() != commands.size()) {
        return sizeNotEqualFailure;
    }
    for (int i = 0; i < commands.size(); ++i) {
      //  commands(execute->aps[i]);
    }


}
