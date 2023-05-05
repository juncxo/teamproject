#include "mockos/CommandPrompt.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/*
 * CommandPrompt's constructor sets the private variables to null pointer
 */
CommandPrompt::CommandPrompt() {
    commandFactory = nullptr;
    commandSystem = nullptr;
}

/*
 * Function to set the program's file system
 */
void CommandPrompt::setFileSystem(AbstractFileSystem * afs) {
    commandSystem = afs;
}



/*
 * Function to set the program's file factory
 */
void CommandPrompt::setFileFactory(AbstractFileFactory * aff) {
    commandFactory = aff;
}



/*
 * Function to add a command to the list of commands that are acceptable by the program
 * If the function fails to add the command correctly to the map, returns failure to indicate that
 */
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



/*
 * The function prints out the commands that were added to the map for the program
 */
void CommandPrompt::listCommands() {
    for(auto& c: commandMap){
        cout<< c.first << endl;
    }
}



/*
 * Function that prompts the user to type in their command they want the program to run
 * Returns the user input as a string
 */
std::string CommandPrompt::prompt() {
    cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command: " << endl;
    cout << "$  ";
    string input;
    getline(cin, input);
    return input;
}



/*
 * Function that continuously runs by asking the user for input and processing their commands
 * If the user types 'q', the program terminates. If the user inputs 'help', prints out the list of commands the program can execute.
 * If not the above inputs, we check if the input is one word. If so, we find whether the input is a command, if not we re prompt the user.
 * If the one word input is a command, execute is invoked on it. If the user input is more than a word, we extract the words to check what
 * the user wants. If the user asks help on a specific command, displayInfo() is invoked. Else, if it's a callable command, execute is invoked.
 * The program prints corrosponding messages if the command fails to executes or the called command doesn't exist in the program.
 */
int CommandPrompt::run() {
    while (true) {
        string input = prompt();
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

            //Checks if the input is 1 word long and invokes/prints the corresponding function/message
            if (oneWordLong) {
                if (commandMap.find(input) != commandMap.end()) {
                    if (commandMap[input]->execute("") != commandSuccess) {
                        cout << "Command failed" << endl;
                    }
                }
                else {
                    cout << "Command does not exist." << endl;
                }
            } else {

                //extracting each word when the user input is more than 1 word
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
                //word1 exists in the command map
                else if (commandMap.find(word1) != commandMap.end()) {
                    string param = input.substr(indexSpace+1, input.npos);
                    if (commandMap[word1]->execute(param) != commandSuccess) {
                        cout << "Command failed" << endl;
                    }
                }
                else {
                    //truncates the user input to extract the command word from the input string
                    string truncatedInput = input.substr(indexSpace+1, string::npos);
                    if (commandMap.find(truncatedInput) != commandMap.end()) {
                        if (commandMap[truncatedInput]->execute(input) != commandSuccess) {
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