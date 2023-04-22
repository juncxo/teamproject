#include "mockos/TouchCommand.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff)  {
    touchSystem = afs;
    touchFactory = aff;
}

void TouchCommand::displayInfo() {
    cout << "Touch creates a file, touch can be invoked by calling the command: touch <filename>" << endl;

}

int TouchCommand::execute(std::string fileName) {
    AbstractFile* createdFile = touchFactory->createFile(fileName);
    if (createdFile != nullptr) {
        if (touchSystem->addFile(fileName, createdFile) != 0) {
            return couldNotAddFile;
        }
        return touchCommandSuccess;
    }
    else {
        return fileNotCreatedSuccessfully;
    }

}