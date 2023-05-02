#include "mockos/CopyCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;


CopyCommand::CopyCommand(SimpleFileSystem *parameter) {
    sfs = parameter;
}

void CopyCommand::displayInfo () {
    cout << "cp copies a file to a new file, cp can be invoked by calling the command: cp <source file> <destination file without the extension>" << endl;
}

int CopyCommand::execute(std::string input) {
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


    string sourceFileName = input.substr(spaceIndex1 + 1, spaceIndex2 -3);
    string destFileName = input.substr(spaceIndex2 + 1, input.npos);


    AbstractFile* sourceFile = sfs->openFile(sourceFileName);

    AbstractFile* destFile = sourceFile->clone(destFileName);


    //destFile->write(sourceFile->read());
    sfs->addFile(destFile->getName(), destFile);
    sfs->closeFile(sourceFile);
    sfs->closeFile(destFile);
    return CopySuccess;

}
