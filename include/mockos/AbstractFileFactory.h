#pragma once
#include <string>
#include "AbstractFile.h"
class AbstractFileFactory{
public:
    virtual AbstractFile* createFile(std::string) = 0;

};