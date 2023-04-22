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
    cin >> input;
    return input;
}

int CommandPrompt::execute (string str) {

}

int CommandPrompt::run() {
    while (true) {
        string input = prompt();
        if (input == "q") {
            return userQuit;
        } else if (input == "help") {
            listCommands();
        } else {
            bool oneWordLong = true;
            for (int i = 0; i < input.length(); i++) {
                if (input[i] == ' ') {
                    oneWordLong = false;
                }
            }
            if (oneWordLong) { // 1 word long
                if (commandMap.find(input) != commandMap.end()) {
                    if (commandMap[input]->execute("") != 0) { //returns an error
                        cout << "Command failed" << endl;
                        return commandFailed;
                    }
                    return commandSuccess;

                }
                else {
                    cout << "Command does not exist." << endl;
                    return commandDoesntExist;
                }
            } else { // longer than 1 word

            }
        }
    }
}