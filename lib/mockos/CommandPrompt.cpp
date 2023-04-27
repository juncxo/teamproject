#include "mockos/CommandPrompt.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

CommandPrompt::CommandPrompt() {
    commandFactory = nullptr;
    commandSystem = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem * afs) {
    commandSystem = afs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * aff) {
    commandFactory = aff;
}

int CommandPrompt::addCommand(string str, AbstractCommand* ad) {
    pair <string, AbstractCommand*> commandPair;
    commandPair.first = str;
    commandPair.second = ad;
    commandMap.insert(commandPair);
    if (commandMap.count (str) == 0) {
        return failedToInsert;
    }
    return commandSuccess;
    //need to check if insert was correct, else return fails
}

void CommandPrompt::listCommands() {
    for(auto& c: commandMap){
        cout<< c.first << endl;
    }
}

std::string CommandPrompt::prompt() {
    cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command: " << endl;
    cout << "$  ";
    string input;
    getline(cin, input);
    return input;
}

int CommandPrompt::run() {
    while (true) {
        string input = prompt();
        /*string *input2 = new string[input.size()];
        for (int i = 0; i < input.size(); i++ ) {
            input2[i] = input[i];
        }
        string inputCopy = input2->c_str();*/

        if (input == "q") {
            return userQuit;
        } else if (input == "help") {
            listCommands();
        } else {
            bool oneWordLong = true;
            int indexSpace = 0;
            for (int index = 0; index < input.length(); index++) {
                if (input[index] == ' ') {
                    oneWordLong = false;
                    indexSpace = index;
                    break;
                }
            }

            if (oneWordLong) { // 1 word long
                if (commandMap.find(input) != commandMap.end()) {
                    if (commandMap[input]->execute("") != 0) { //returns an error
                        cout << "Command failed" << endl;
                        //return commandFailed;
                    }

                }
                else {
                    cout << "Command does not exist." << endl;
                    //return commandDoesntExist;
                }
            } else { // longer than 1 word

                istringstream iss (input);
                string word1;
                iss >> word1;


                if (word1 == "help") {
                    string word2;
                    iss >> word2;
                    if (commandMap.find(word2) != commandMap.end()) {

                        commandMap[word2]->displayInfo();

                    }
                    else {
                        cout << "Command does not exist." << endl;
                    }
                }
                else {

                    string truncatedInput = input.substr(indexSpace+1, string::npos);

                    if (commandMap.find(truncatedInput) != commandMap.end()) {
                        if (commandMap[truncatedInput]->execute(" ") != 0) {
                            cout << "Command failed" << endl;
                           // return commandFailed;
                        }
                    }
                    else {
                        cout << "Command does not exist. " << endl;
                        //return commandDoesntExist;
                    }
                }
            }
        }
    }
    return commandSuccess;
}