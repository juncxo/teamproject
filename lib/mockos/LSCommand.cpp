#include "mockos/LSCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;

/*
 * Constructor to set the file system and variable that is later used in execute fir alignment
 */
LSCommand::LSCommand(AbstractFileSystem* parameter) {
    longestFileName = 0;
    sfs = parameter;
}


/*
 * Prints out the information about the ls and command
 */
void LSCommand::displayInfo () {
    cout << "ls displays the list of current files and ls -m displays the meta data of all the files in the system, ls can be invoked by calling the command: 'ls' or 'ls -m'" << endl;
}


/*
 * Function checks whether the input asks to only display file names or the meta data.
 * To display the file names, we use a for each loop to loop through the names in the file system.
 * To display metadata, we create a MetaDisplayVisitor object then iterate through the file names in the system,
 * then we check if the file exists, we invoke accept() function to visit the corresponding file type to print its metadata
 */
int LSCommand::execute(std::string input) {
    if (input == ""){
        //get the max length for alignment
        int index1 = 0;
        for (string str : sfs->getFileNames()) {
            if (str.length() > longestFileName) {
                longestFileName = str.length();
            }
            index1++;
        }

        int index2 = 0;
        //print out the file names by aligning based on how much the string length differs from the longest file name
        for (string str : sfs->getFileNames()) {
            cout << str;
            for (int i = 0; i < longestFileName + 1 - str.length(); i++) {
                cout << " ";
            }
            //start a new line every two files
            if (index2 % 2 == 1) {
                cout << endl;
            }
            index2++;
        }
        cout << endl;
    }

    else if (input == "-m") {
        MetadataDisplayVisitor* mdv = new MetadataDisplayVisitor();
        set<string> variable = sfs->getFileNames();

        auto iterator = variable.begin();
        while (iterator != variable.end()) {
            AbstractFile* abstract = sfs->openFile(*iterator);
            if (abstract != nullptr) {
                abstract -> accept(mdv);
                sfs->closeFile (abstract);
            }
            iterator++;
        }

    }
    return LSsuccess;
}