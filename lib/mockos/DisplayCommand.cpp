#include "mockos/DisplayCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;


DisplayCommand::DisplayCommand(SimpleFileSystem *parameter) {
    sfs = parameter;
}

void DisplayCommand::displayInfo () {
    cout << "ds displays the file's contents, ds can be invoked by calling the command: ds" << endl;
}

int DisplayCommand::execute(std::string input) {
    int spaceIndex = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex = i;
            break;
        }
    }
    string fileName = input.substr(spaceIndex+1, input.npos);
    if (fileName.substr(fileName.size() - 3) == " -d") {
        string fileNameWithoutTheDashP = fileName.substr(0, fileName.size() - 3);
        AbstractFile* file = sfs->openFile(fileNameWithoutTheDashP);
        for (int i = 0; i < file->read().size(); i++) {
            cout << file->read()[i];
        }
        cout << endl;
    }
    else {
        AbstractFile* file = sfs->openFile(fileName);

        cout << endl;
    }
    return DisplaySuccess;
}