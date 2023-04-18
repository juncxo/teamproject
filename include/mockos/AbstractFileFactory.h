#pragma once
#include <string>
class AbstractFile;

class AbstractFileFactory{
public:
    virtual AbstractFile* createFile(std::string) = 0;

};