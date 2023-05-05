#include "mockos/PasswordProxy.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* af, std::string str) {

    password = str;
    vector <int> encryptedPassword;

    //encrypt each character's ASCII value
    for (int i = 0; i < password.length(); i++) {
        int ASCIIValue = (int) password[i];
        int store = encryptMod131 (ASCIIValue);
        encryptedPassword.push_back(store);
    }
    password = "";

    //the password is now encrypted to be the concatenation of the encrypted
    //versions of its ASCII values. For instance, the password "hello15b"
    //gets encrypted to "89 93 114 114 126 40 116 28"

    for (int i = 0; i < encryptedPassword.size(); i++) {
        password += (std::to_string(encryptedPassword[i]) + " ");

    }

    cout << endl;


    protectedFile = af;
}

PasswordProxy::~PasswordProxy() {
    delete protectedFile;
}

//prompt for a password using getline. This function is called whenever a user tries
//to edit or display a password-protected file.
string PasswordProxy::passwordPrompt() {
    string input;
    cout << "Enter the correct password" << endl;
    getline(cin, input);
    return input;

}

//helper function to encrypt each character (based on ASCII value)
int PasswordProxy::encryptMod131 (int decryptedNumber) {
    return twoToThe(decryptedNumber);
}

//helper function to decrypt each character (based on ASCII value)
int PasswordProxy::decryptMod131 (int encryptedNumber) {
    //to decrypt each character, we calculate the discrete logarithm for each encrypted ASCII value
    for (int i = 0; i < 131; i++) {
        if (twoToThe(i) == encryptedNumber) {
            return i;
        }
    }
}

//helper function to compute the value of 2^exponent mod 131 (used for encryption and descryption)
int PasswordProxy::twoToThe (int exponent) {
    int mod131 = 1;
    for (int i = 0; i < exponent; i++) {
        mod131 *= 2;
        mod131 %= 131;
    }
    return mod131;
}

//function to check if an entered password is correct (called when the user
//tries to display or edit a password-protected file)
bool PasswordProxy::passwordCheck(string str){
    //we decode the password here.
    vector<int> decodedCharacters;
    string decodedPassword;
    int numberOfSpaces = 0;
    int index = 0;

    //count the number of ASCII values in the encrypted password
    for (int i = 0; i < password.length(); i++) {
        if (password[i] == ' ') {
            numberOfSpaces++;
        }
    }
    istringstream iss (password);

    //extract each ASCII value from the password and decrypt it
    while (index < numberOfSpaces){
        int ASCIIValue;
        iss >> ASCIIValue;
        int store = decryptMod131 (ASCIIValue);
        decodedCharacters.push_back(store);
        index++;
    }

    //convert the vector<int> of decoded ASCII values to a decoded password (string)
    for (int i = 0; i < decodedCharacters.size(); i++) {
        decodedPassword += (char) (decodedCharacters[i]);
    }

    //check if the entered password equals the original (decoded) password
    if(str == decodedPassword){
        return true;
    }
    cout << "Wrong password" << endl;
    return false;
}


//returns the contents of the file upon entering correct password
vector<char> PasswordProxy::read() {
    vector<char> pv;
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        return protectedFile->read();
    }
    return pv;
}

//writes to the file upon entering correct password
int PasswordProxy::write(vector<char> pv){
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        return protectedFile->write(pv);
    }
    return incorrectPassword;
}

//appends to the file upon entering correct password

int PasswordProxy::append(vector<char> pv){
    string inputPass = passwordPrompt();
    if(passwordCheck(inputPass)){
        return protectedFile->append(pv);
    }
    return passwordUnableToAppend;
}

//gets the size of the file
unsigned int PasswordProxy::getSize(){
    return protectedFile->getSize();
}

//gets the name of the file
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