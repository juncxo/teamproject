#include "mockos/CopyCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;


CopyCommand::CopyCommand(AbstractFileSystem* parameter) {
    afs = parameter;
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
    /*
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex2 = i;
        }
    }
     */

    if(spaceIndex1 == 0){
        return 5;
    }
    string sourceFileName = input.substr(0,  spaceIndex1);
    string destFileName = input.substr(spaceIndex1 + 1, input.npos);


    AbstractFile* sourceFile = afs->openFile(sourceFileName);
    AbstractFile* destFile = sourceFile->clone(destFileName);

    //destFile->write(sourceFile->read());
    if (afs->addFile(destFile->getName(), destFile) != 0) { //adding failed
        afs->closeFile(sourceFile);
        delete destFile;
        return failedToAddCopy;
    }
    afs->closeFile(sourceFile);
    return CopySuccess;

}
