#include "mockos/RemoveCommand.h"
#include <string>
#include <iostream>

using namespace std;


RemoveCommand::RemoveCommand(AbstractFileSystem* parameter) {
    sfs = parameter;
}

void RemoveCommand::displayInfo () {
    cout << "rm removes a file from the list of current files, rm can be invoked by calling the command: rm" << endl;
}

int RemoveCommand::execute(std::string input) {
    //find space
    int spaceIndex = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex = i;
        }
    }
    string fileName = input.substr(spaceIndex+1, string::npos);
    if (sfs->deleteFile(fileName) != 0) {
        return unableToRemove;
    }
    return removeSuccess;
}