#include "mockos/MacroCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"
#include <sstream>
using namespace std;


MacroCommand::MacroCommand(SimpleFileSystem *parameter) {
    sfs = parameter;
}

void MacroCommand::displayInfo () {
    cout << "macro commmands executes several commands in order, it is invoked by typing in a sequence of commands." << endl;
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


    /*
    int finalSpaceIndex = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            finalSpaceIndex = i;
        }
    }

    string inputWithoutTheFileName = input.substr(0, finalSpaceIndex-1);
    string fileName = input.substr(finalSpaceIndex+1, input.npos);
    vector <string> commands = parse(inputWithoutTheFileName);
    for (string commandName : commands) {
        if (commandName == "ls") {
            if(execute(commandName) != 0) {
                return MacroFail;
            }
        }
        else if (execute(commandName + " " + fileName) != 0) {
            return MacroFail;
        }
    }
    return MacroSuccess;
     */
}
