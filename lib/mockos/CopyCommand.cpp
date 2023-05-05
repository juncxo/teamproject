#include "mockos/CopyCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;

/*
 * CopyCommand constructor to set the file system
 */
CopyCommand::CopyCommand(AbstractFileSystem* parameter) {
    afs = parameter;
}


/*
 * Prints out the info on copy command 'cp' command
 */
void CopyCommand::displayInfo () {
    cout << "cp copies a file to a new file, cp can be invoked by calling the command: cp <source file> <destination file without the extension>" << endl;
}



/*
 * First find the space between the two file name in the input.
 * Extract the two file names. Then open the existing file and call clone on the new file. If source file is null, returns
 * error indicating file doesn't exist. We close the file before returning success if nothing failed.
 */
int CopyCommand::execute(std::string input) {
    int spaceIndex1 = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex1 = i;
            break;
        }
    }

    string sourceFileName = input.substr(0,  spaceIndex1);
    string destFileName = input.substr(spaceIndex1 + 1, input.npos);

    AbstractFile* sourceFile = afs->openFile(sourceFileName);
    if(sourceFile == nullptr){
        return fileNonExist;
    }
    AbstractFile* destFile = sourceFile->clone(destFileName);

    //if failure to add the new file, we close the original, delete the file cloned and return error to indicate failure to copy
    if (afs->addFile(destFile->getName(), destFile) != CopySuccess) {
        afs->closeFile(sourceFile);
        delete destFile;
        return failedToAddCopy;
    }
    afs->closeFile(sourceFile);
    return CopySuccess;

}
