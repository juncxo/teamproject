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


    string sourceFileName = input.substr(spaceIndex1 + 1, spaceIndex2 - 3);
    string destFileName = input.substr(spaceIndex2 + 1, input.npos);

    AbstractFile* sourceFile = sfs->openFile(sourceFileName);
    int dotIndex = 0;
    for (int i = 0; i < sourceFileName.length(); i++) {
        if (sourceFileName[i] == '.') {
            dotIndex = i;
        }
    }
    string extension = sourceFileName.substr(dotIndex+1, sourceFileName.npos);
    AbstractFile* destFile;
    string finalDestFileName;
    if (extension == "txt") {
        finalDestFileName = destFileName + ".txt";
        destFile = new TextFile(finalDestFileName);
    }
    else if (extension == "img") {
        finalDestFileName = destFileName + ".img";
        destFile = new ImageFile(finalDestFileName);
    }
    else {
        return InvalidFileExtension;
    }
    destFile->write(sourceFile->read());
    sfs->addFile(finalDestFileName, destFile);
    sfs->closeFile(sourceFile);
    sfs->closeFile(destFile);

    return CopySuccess;
}
