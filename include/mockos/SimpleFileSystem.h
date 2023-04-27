#pragma once
#include <string>
#include <map>
#include <set>
#include "AbstractFileSystem.h"

enum SFSErrors{
    SFSSuccess,
    fileExists,
    pointerIsNull,
    fileNotOpen,
    fileIsOpen,
    fileDoesNotExist,
    invalidExtension
};
class SimpleFileSystem : public AbstractFileSystem{
public:
    virtual int addFile(std::string, AbstractFile *);
    virtual AbstractFile * openFile(std::string);
    virtual int closeFile(AbstractFile *);
    virtual int deleteFile(std::string);
private:
    std::map<std::string, AbstractFile*> maps;
    std::set<AbstractFile*> sets;
};