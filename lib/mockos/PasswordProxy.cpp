#include "mockos/PasswordProxy.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* af, std::string str) {
    password = str;
    protectedFile = af;
}

PasswordProxy::~PasswordProxy() {
    delete protectedFile;
}

string PasswordProxy::passwordPrompt() {
    cout << "Enter a password" << endl;
    string input;
    cin >> input;
    istringstream iss(input);

}

vector<char> PasswordProxy::read() {
    string inputPass = passwordPrompt();

}