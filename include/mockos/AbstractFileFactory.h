#pragma once
#include <string>
class AbstractFileFactory{
public:
    virtual AbstractFile* createFile(std::string) = 0;

};