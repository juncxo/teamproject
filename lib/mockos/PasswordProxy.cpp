#include "mockos/PasswordProxy.h"
#include <string>
#include <iostream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* af, std::string str) {
    password = str;
    protectedFile = af;
}

PasswordProxy::~PasswordProxy() {
    delete protectedFile;
}

