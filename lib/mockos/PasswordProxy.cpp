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
    string input;
    cout << "Enter a password" << endl;
    cin >> input;
    return input;
}

bool PasswordProxy::passwordCheck(string str){
    if(str == password){
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