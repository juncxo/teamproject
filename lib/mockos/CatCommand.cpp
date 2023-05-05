#include "mockos/CatCommand.h"
#include <string>
#include <iostream>
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;

/*
 * Constructor to set the file cat command is called on to the class's private variable
 */
CatCommand::CatCommand(AbstractFileSystem *parameter) {
    sfs = parameter;
}


/*
 * Prints out the information about the cat command
 */
void CatCommand::displayInfo () {
    cout << "cat concatenates two files, cat can be invoked by calling the command: cat" << endl;
}


/*
 * cat command runs when invoked by the command prompt by...
 * 1. checking if the command has -a to indicate append,
 * then we get the filename, open it to print the content already in the file before prompting the user for new info to
 * append to the file. After the user indicated whether to save their input or quit without saving, we do as indicated.
 * If, however, the file is an image file, we do not append to it because image appending info is not supported and
 * return an error indicating that we cannot append.
 * 2. Otherwise, the command takes the filename inputed, overwrites the content of the file using the write() command.
 * In both cases, the file is then closed. Returns catsuccess to indicate the file performed correctly.
 */
int CatCommand::execute(std::string input) {
    /*
    int spaceIndex = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            spaceIndex = i;
            break;
        }
    }
     */
    //string fileName = input.substr(spaceIndex+1, input.npos);
    if (input.substr(input.size() - 3) == " -a") {
        string fileName = input.substr(0, input.size() - 3);
        AbstractFile* file = sfs->openFile(fileName);
        for (int i = 0; i < file->read().size(); i++) {
            cout << file->read()[i];
        }
        //file->read();
        cout << endl;
        cout << "Enter new data into the file (enter :wq or :q to quit with or without saving, respectively). " <<endl;
        vector<string> savedInput;
        vector<char> savedCharInput;
        string userInput;
        if(file->append(savedCharInput) != 0){
            return cannotAppend;
        }
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

                savedCharInput.pop_back();
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
        AbstractFile* file = sfs->openFile(input);
        if(file == nullptr){
            sfs->closeFile(file);
            return fileNoExist;
        }
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
                savedCharInput.pop_back();
                file->write(savedCharInput );
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