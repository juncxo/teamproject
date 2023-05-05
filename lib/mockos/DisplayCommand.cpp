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


/*
 * The function accounts for whether to display formatted text or not. If for formatted, then the function prints the content
 * formatted by creating a BasicDisplayVisitor() object to call accept on which calls the corresponding method content displayer.
 * Otherwise, simply prints out how the content is in the file using the read() function.
 */
int DisplayCommand::execute(std::string fileName) {
    if (fileName.length() >= 3) {
        if (fileName.substr(fileName.size() - 3) == " -d") {
            string fileNameWithoutTheDashD = fileName.substr(0, fileName.size() - 3);
            AbstractFile *file = sfs->openFile(fileNameWithoutTheDashD);
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
            AbstractFileVisitor* bdv = new BasicDisplayVisitor();
            file->accept(bdv);

            cout << endl;
            delete bdv;
            sfs->closeFile(file);
        }
    }
    else {
        return invalidFileName;
    }
    return DisplaySuccess;
}