#include "mockos/LSCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;


LSCommand::LSCommand(SimpleFileSystem* parameter) {
    longestFileName = 0;
    longestFileType = 0;
    sfs = parameter;
}

void LSCommand::displayInfo () {
    cout << "LS displays the list of current files, LS can be invoked by calling the command: LS" << endl;
}

int LSCommand::execute(std::string input) {
    if (input == "ls"){
        //get the max length
        int index1 = 0;
        for (string str : sfs->getFileNames()) {

            //maintain the max length for alignment
            if (str.length() > longestFileName) {
                longestFileName = str.length();
            }

            index1++;

        }

        int index2 = 0;
        //print out the file names
        for (string str : sfs->getFileNames()) {
            cout << str;

            //align based on how much the string length differs from the longest file name


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
    else if (input == "ls -m") {

//awagw
        //print file info
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