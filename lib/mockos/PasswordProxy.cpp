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
        //
    }
    return pv;
}

int PasswordProxy::write(vector<char> pv){
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        //
        return passwordSuccess;
    }
    return incorrectPassword;
}

int PasswordProxy::append(vector<char> pv){
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        //
        return passwordSuccess;
    }
    return passwordUnableToAppend;
}

unsigned int PasswordProxy::getSize(){
    return password.size();
}

string PasswordProxy::getName(){
    return protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* pafv){
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        protectedFile->accept(pafv);
    }
}