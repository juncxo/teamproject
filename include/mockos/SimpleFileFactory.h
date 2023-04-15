#pragma once
#include "mockos/AbstractFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"

class SimpleFileFactory : public AbstractFileFactory{
public:
    virtual AbstractFile* createFile(std::string);
};