#include "mockos/LSCommand.h"
#include <string>
#include <iostream>

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
            if ((str.length() > longestFileName) && (index1 % 2 == 0)) {
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
    }
    else if (input == "ls -m") {
        int dotIndex = 0;
        //get the max file length
        for (string str : sfs->getFileNames()) {
            if (str.length() > longestFileName) {
                longestFileName = str.length();
            }

        }

        //get the max file type length
        for (string str : sfs->getFileNames()) {
            //find the period in the file name
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == '.') {
                    dotIndex = i;
                }
            }
            //get the extension to find the file type
            string extension = str.substr(dotIndex + 1, str.npos);

            string fileType;
            if (extension == "txt") {
                fileType = "text";
                if (str.length() > longestFileType) {
                    longestFileType = fileType.length();
                }
            }
            else if (extension == "img"){
                fileType = "image";
                if (str.length() > longestFileType) {
                    longestFileType = fileType.length();
                }
            }
            else {
                return unknownFileType;
            }
        }

        //print file info
        for (string str : sfs->getFileNames()) {

            //print the file name
            cout << str;
            for (int i = 0; i < longestFileName + 1 - str.length(); i++) {
                cout << " ";
            }

            //print the file type
            string extension = str.substr(dotIndex + 1, str.npos);
            string fileType;
            if (extension == "txt") {
                fileType = "text";
            }
            else if (extension == "img"){
                fileType = "image";
            }
            else {
                return unknownFileType;
            }
            cout << fileType;
            for (int i = 0; i < longestFileType + 1 - str.length(); i++) {
                cout << " ";
            }

            //print the file size
            cout << 5; //PLACEHOLDER
            //TODO: ADD FILE SIZE
            cout << endl;

        }

    }
    return LSsuccess;
}
