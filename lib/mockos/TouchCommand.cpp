#include "mockos/TouchCommand.h"
#include "mockos/PasswordProxy.h"
#include <string>
#include <iostream>

using namespace std;

/*
 * Constructor to set the file system and file factory to the private variable for this commmand
 */
TouchCommand::TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff)  {
    touchSystem = afs;
    touchFactory = aff;
}


/*
 * Prints out the info on touch command
 */
void TouchCommand::displayInfo() {
    cout << "Touch creates a file, touch can be invoked by calling the command: touch <filename>" << endl;

}


/*
 * The function creates a file using the user input. The file can either be created using password which invoked the
 * passwordproxy which asks the user for further input and creating a passwordproxy object
 * or simply create the file using createfile() function.
 */
int TouchCommand::execute(std::string fileName) {
    if (fileName.substr(fileName.size() - 3) == " -p") {

        string fileNameWithoutTheDashP = fileName.substr(0, fileName.size() - 3);
        AbstractFile *createdFile = touchFactory->createFile(fileNameWithoutTheDashP);
        string password;
        cout << "Enter a password to protect the file: " << endl;
        getline(cin, password);


        if (createdFile != nullptr) {
            PasswordProxy* proxy = new PasswordProxy(createdFile, password);
            touchSystem->addFile(fileNameWithoutTheDashP, proxy);
            return touchCommandSuccess;
        } else {
            return fileNotCreatedSuccessfully;
        }
    }
    else {
        AbstractFile *createdFile = touchFactory->createFile(fileName);
        if (createdFile != nullptr) {
            touchSystem->addFile(fileName, createdFile);
            return touchCommandSuccess;
        } else {
            return fileNotCreatedSuccessfully;
        }
    }
}



