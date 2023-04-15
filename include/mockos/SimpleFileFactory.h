#pragma once
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFile.h"

class SimpleFileFactory : public AbstractFileFactory{
public:
    virtual AbstractFile* createFile(std::string);
};