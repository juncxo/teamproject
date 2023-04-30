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
        /*string * what = new string[input.size()];
        for (int i=0; i < input.size(); i++) {
            what[i] = input[i];
        }*/

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
                    if (commandMap[input]->execute(input) != 0) { //returns an error
                        cout << "Command failed" << endl;
                    }

                }
                else {
                    cout << "HERE" << endl;
                    cout << "Command does not exist." << endl;
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
                else if (commandMap.find(word1) != commandMap.end()) { //word1 is in the command map
                    if (commandMap[word1]->execute(input) != 0) {
                        cout << "Command failed" << endl;
                    }
                }
                else {

                    string truncatedInput = input.substr(indexSpace+1, string::npos);

                    if (commandMap.find(truncatedInput) != commandMap.end()) {
                        if (commandMap[truncatedInput]->execute(input) != 0) {
                            cout << "Command failed" << endl;
                        }
                    }
                    else {
                        cout << "Command does not exist. " << endl;
                    }
                }
            }
        }
    }
}