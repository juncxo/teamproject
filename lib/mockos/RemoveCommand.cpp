#include "mockos/RemoveCommand.h"
#include <string>
#include <iostream>

using namespace std;

/*
 * Constructor to set the file system
 */
RemoveCommand::RemoveCommand(AbstractFileSystem* parameter) {
    sfs = parameter;
}

/*
 * Prints out the information about the rm command
 */
void RemoveCommand::displayInfo () {
    cout << "rm removes a file from the list of current files, rm can be invoked by calling the command: rm" << endl;
}


/*
 * The function deletes the file that's name is passed in the parameter
 * Returns corresponding enum to indicate failure or success of the function
 */
int RemoveCommand::execute(std::string fileName) {
    if (sfs->deleteFile(fileName) != removeSuccess) {
        return unableToRemove;
    }
    return removeSuccess;
}