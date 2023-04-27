#pragma once
#include "mockos/AbstractFileFactory.h"


class SimpleFileFactory : public AbstractFileFactory{
public:
    virtual AbstractFile* createFile(std::string);
};