#include "mockos/DisplayCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;

/*
 * Constructor to set the file system
 */
DisplayCommand::DisplayCommand(AbstractFileSystem *parameter) {
    sfs = parameter;
}


/*
 * Prints out the information about the ds command
 */
void DisplayCommand::displayInfo () {
    cout << "ds displays the file's contents, ds can be invoked by calling the command: ds" << endl;
}

int DisplayCommand::execute(std::string fileName) {
    if (fileName.substr(fileName.size() - 3) == " -d") {
        string fileNameWithoutTheDashD = fileName.substr(0, fileName.size() - 3);
        AbstractFile* file = sfs->openFile(fileNameWithoutTheDashD);
        for (int i = 0; i < file->read().size(); i++) {
            cout << file->read()[i];
        }
        cout << endl;
        sfs->closeFile(file);

    }
    else {
        AbstractFile* file = sfs->openFile(fileName);
        if(file == nullptr){
            return fileNull;
        }
        /*
        int dotIndex = 0;
        for (int i = 0; i < fileName.length(); i++) {
            if (fileName[i] == '.') {
                dotIndex = i;
                break;
            }
        }
        string extension = fileName.substr (dotIndex+1, fileName.npos);
        */
        AbstractFileVisitor* bdv = new BasicDisplayVisitor();
        file->accept(bdv);

        cout << endl;
        delete bdv;
        sfs->closeFile(file);

    }
    return DisplaySuccess;
}