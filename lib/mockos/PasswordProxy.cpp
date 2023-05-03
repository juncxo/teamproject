#include "mockos/PasswordProxy.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* af, std::string str) {
    password = str;
    vector<char> encryptedCharacters;
    string encryptedPassword;
    for (int i = 0; i < password.length(); i++) {
        int ASCIIValue = (int) password[i];
        int store = encryptMod131 (ASCIIValue);
        encryptedCharacters.push_back(store);
    }
    //convert vector<char> to string
    for (int i = 0; i < encryptedCharacters.size(); i++) {
        encryptedPassword += encryptedCharacters[i];
    }

    password = encryptedPassword;
    cout << "Encrypted password: " << password << endl;
    protectedFile = af;
}

PasswordProxy::~PasswordProxy() {
    delete protectedFile;
}

string PasswordProxy::passwordPrompt() {
    string input;
    cout << "Enter a password" << endl;
    cin >> input;
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

    vector<char> decodedCharacters;
    string decodedPassword;
    for (int i = 0; i < password.length(); i++) {
        int ASCIIValue = (int) password[i];
        int store = decryptMod131 (ASCIIValue);
        decodedCharacters.push_back(store);
    }
    //convert vector<char> to string
    for (int i = 0; i < decodedCharacters.size(); i++) {
        decodedPassword += decodedCharacters[i];
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