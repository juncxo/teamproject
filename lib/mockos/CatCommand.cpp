#include "mockos/CatCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;


CatCommand::CatCommand(SimpleFileSystem *parameter) {

    sfs = parameter;
}

void CatCommand::displayInfo () {
    cout << "cat concatenates two files, cat can be invoked by calling the command: cat" << endl;
}

int CatCommand::execute(std::string input) {
    int spaceIndex = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex = i;
            break;
        }
    }
    string fileName = input.substr(spaceIndex+1, input.npos);
    if (fileName.substr(fileName.size() - 3) == " -a") {
        string fileNameWithoutTheDashP = fileName.substr(0, fileName.size() - 3);
        AbstractFile* file = sfs->openFile(fileNameWithoutTheDashP);
        file->read();
        cout << endl;
        cout << "Enter new data into the file (enter :wq or :q to quit with or without saving, respectively). " <<endl;
        vector<string> savedInput;
        vector<char> savedCharInput;
        string userInput;
        while (getline(cin, userInput)) {
            if (userInput == ":q") {
                break;
            }
            else if (userInput == ":wq") {
                for (int i = 0; i < savedInput.size(); i++) {
                    for (int j = 0; j < savedInput[i].length(); j++) {
                        savedCharInput.push_back (savedInput[i][j]);
                    }
                }
                file->append(savedCharInput);
                break;
            }
            else {
                savedInput.push_back (userInput + "\n");
            }
        }
        sfs->closeFile(file);

    }
    else {
        AbstractFile* file = sfs->openFile(fileName);
        cout << "Replace the file with new data (enter :wq or :q to quit with or without saving, respectively). " << endl;
        vector<string> savedInput;
        vector<char> savedCharInput;
        string userInput;
        while (getline(cin, userInput)) {
            if (userInput == ":q") {
                break;
            }
            else if (userInput == ":wq") {
                for (int i = 0; i < savedInput.size(); i++) {
                    for (int j = 0; j < savedInput[i].length(); j++) {
                        savedCharInput.push_back (savedInput[i][j]);
                    }
                }
                file->write(savedCharInput);
                break;
            }
            else {
                savedInput.push_back (userInput + "\n");
            }
        }
        sfs->closeFile(file);
    }

    return Catsuccess;
}