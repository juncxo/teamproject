#pragma once
#include "AbstractFile.h"
#include <string>

class PasswordProxy : public AbstractFile{
public:
    PasswordProxy(AbstractFile*, std::string);
    virtual ~PasswordProxy();
    virtual std::string getName();
    virtual unsigned int getSize();
    virtual std::vector<char> read();
    virtual int write(std::vector<char>);
    virtual int append(std::vector<char>);
    virtual void accept(AbstractFileVisitor*);
protected:
    std::string passwordPrompt();
    bool passwordCheck(std::string);
private:
    AbstractFile* protectedFile;
    std::string password;

};