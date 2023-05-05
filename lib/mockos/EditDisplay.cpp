
#include <string>
#include "mockos/EditDisplay.h"

#include <iostream>
#include <sstream>
using namespace std;


std::vector<std::string> EditDisplay::parse (std::string input) {
    vector <std::string> returnedVector;
    string append = input.substr(input.size() - 3, input.npos);
    string fileName;
    if (append == " -a") {
        fileName = input.substr(0, input.size() - 3);
    }
    else {
        fileName = input.substr(0, input.npos);
    }

    returnedVector.push_back (input);
    returnedVector.push_back (fileName);

    return returnedVector;
}

