#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"

/*
 * Enumeration for TextFile
 */
enum text{
    textSucess
};
class TextFile : public AbstractFile {
public:
    TextFile();
    TextFile(std::string);
    virtual std::string getName();
    virtual unsigned int getSize();
    virtual std::vector<char> read();
    virtual int write(std::vector<char>);
    virtual int append(std::vector<char>);
    virtual void accept(AbstractFileVisitor*);
    virtual AbstractFile* clone(std::string);

private:
    std::vector<char> contents;
    std::string name;
};