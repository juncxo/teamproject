
#include <string>
#include "mockos/EditDisplay.h"

#include <iostream>
#include <sstream>
using namespace std;


std::vector<std::string> EditDisplay::parse (std::string fileName) {
    vector <std::string> returnedVector;
    returnedVector.push_back (fileName);
    return returnedVector;
}

