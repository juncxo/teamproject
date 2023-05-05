#include "mockos/PasswordProxy.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* af, std::string str) {
    password = str;

    vector <int> encryptedPassword;
    for (int i = 0; i < password.length(); i++) {
        int ASCIIValue = (int) password[i];
        int store = encryptMod131 (ASCIIValue);
        encryptedPassword.push_back(store);
    }
    password = "";
    for (int i = 0; i < encryptedPassword.size(); i++) {
        password += (std::to_string(encryptedPassword[i]) + " ");

    }
    //cout << "Encrypted password: " << password << endl;

    cout << endl;


    protectedFile = af;
}

PasswordProxy::~PasswordProxy() {
    delete protectedFile;
}

string PasswordProxy::passwordPrompt() {
    string input;
    cout << "Enter a password" << endl;
    getline(cin, input);
    return input;

}

int PasswordProxy::encryptMod131 (int decryptedNumber) {
    return twoToThe(decryptedNumber);
}

int PasswordProxy::decryptMod131 (int encryptedNumber) {
    for (int i = 0; i < 131; i++) {
        if (twoToThe(i) == encryptedNumber) {
            return i;
        }
    }
}

int PasswordProxy::twoToThe (int exponent) {
    int mod131 = 1;
    for (int i = 0; i < exponent; i++) {
        mod131 *= 2;
        mod131 %= 131;
    }
    return mod131;
}

bool PasswordProxy::passwordCheck(string str){
    vector<int> decodedCharacters;
    string decodedPassword;
    int numberOfSpaces = 0;
    int index = 0;
    for (int i = 0; i < password.length(); i++) {
        if (password[i] == ' ') {
            numberOfSpaces++;
        }
    }
    istringstream iss (password);
    while (index < numberOfSpaces){
        int ASCIIValue;
        iss >> ASCIIValue;
        int store = decryptMod131 (ASCIIValue);
        decodedCharacters.push_back(store);
        index++;
    }

    //convert vector<int> to string
    for (int i = 0; i < decodedCharacters.size(); i++) {
        decodedPassword += (char) (decodedCharacters[i]);
    }
    if(str == decodedPassword){
        return true;
    }
    return false;
}



vector<char> PasswordProxy::read() {
    vector<char> pv;
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        return protectedFile->read();
    }
    return pv;
}

int PasswordProxy::write(vector<char> pv){
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        return protectedFile->write(pv);
    }
    return incorrectPassword;
}

int PasswordProxy::append(vector<char> pv){
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        return protectedFile->append(pv);
    }
    return passwordUnableToAppend;
}

unsigned int PasswordProxy::getSize(){
    return protectedFile->getSize();
}

string PasswordProxy::getName(){
    return protectedFile->getName();
}


/*
 * When implementing either copy or rename (which calls on copy, so essentially the copy command), we need
 * to create a deep copy of the original file to create the new file. In order to do this, we implement
 * the clone function. This part is to dynamically allocate a new Password proxy and calling clone
 * so that we create a deep copy of the password of the original file and allocate it to the new file.
 */
AbstractFile* PasswordProxy::clone (string fileName) {
    PasswordProxy* newProxy =  new PasswordProxy(*this);
    newProxy->protectedFile = protectedFile->clone(fileName);
    newProxy->password = this->password;
    return newProxy;
}

void PasswordProxy::accept(AbstractFileVisitor* pafv){
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        protectedFile->accept(pafv);
    }
}