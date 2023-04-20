#pragma once
#include "AbstractFile.h"
#include <string>

class PasswordProxy : public AbstractFile{
public:
    PasswordProxy(AbstractFile*, std::string);
    virtual ~PasswordProxy();
protected:
    std::string passwordPrompt();
    bool passwordCheck(std::string);
private:
    AbstractFile* protectedFile;
    std::string password;

};