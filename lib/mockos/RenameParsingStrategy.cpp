
#include <string>
#include "mockos/AbstractParsingStrategy.h"
#include <iostream>
#include <sstream>
using namespace std;

/*
std::vector<std::string> AbstractParsingStrategy::parse (std::string str) {

    vector <string> returnedVector;
    int numberOfWords = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            numberOfWords++;
        }
    }
    int spaceIndex1 = 0;
    int spaceIndex2 = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            spaceIndex1 = i;
            break;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            spaceIndex2 = i;
        }
    }

    string sourceFileName = str.substr(spaceIndex1 + 1, spaceIndex2 - 3);
    string destFileName = str.substr(spaceIndex2 + 1, str.npos);

    istringstream iss (str);
    for (int i = 0; i < numberOfWords; i++) {
        string vectorValue;
        iss >> vectorValue;
        returnedVector.push_back (vectorValue);
    }
    return returnedVector;


}
*/
