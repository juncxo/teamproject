#include "mockos/SimpleFileSystem.h"
#include <string>
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
using namespace std;

int SimpleFileSystem::addFile(string a, AbstractFile* p){
    if (maps.count(a) != 0) {
        return fileExists;
    }
    if(p == NULL){
        return pointerIsNull;
    }
    pair <string, AbstractFile*> filePair;
    filePair.first = a;
    filePair.second = p;
    maps.insert(filePair);
    return SFSSuccess;
}



AbstractFile* SimpleFileSystem::openFile(string of){
    if (maps.count(of) != 0) {

        if (sets.find(maps[of]) == sets.end()) {
            sets.insert (maps[of]);
            return maps[of];
        }
    }

    return nullptr;
}


int SimpleFileSystem::closeFile(AbstractFile *cf) {
    if (sets.find(cf) != sets.end()) {
        sets.erase(cf);
        return SFSSuccess;
    }
    return fileNotOpen;
}


int SimpleFileSystem::deleteFile(string df) {
    if (maps.count(df) != 0) {
        if (sets.find(maps[df]) != sets.end()) {
            return fileIsOpen;
        }
        delete maps[df];
        maps.erase(df);
        return SFSSuccess;

    }
    return fileDoesNotExist;
}

std::set<std::string> SimpleFileSystem::getFileNames(){
    std::set<string> returnedSet;

    for (pair <string, AbstractFile*> filePair : maps) {
        returnedSet.insert(filePair.first);
    }
    return returnedSet;
}