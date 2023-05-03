#include "mockos/TouchCommand.h"
#include "mockos/PasswordProxy.h"
#include <string>
#include <iostream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff)  {
    touchSystem = afs;
    touchFactory = aff;
}

void TouchCommand::displayInfo() {
    cout << "Touch creates a file, touch can be invoked by calling the command: touch <filename>" << endl;

}

int TouchCommand::execute(std::string input) {
    int spaceIndex = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex = i;
            break;
        }
    }
    string fileName = input.substr(spaceIndex+1, input.npos);
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



