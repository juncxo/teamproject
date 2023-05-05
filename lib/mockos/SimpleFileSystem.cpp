#include "mockos/SimpleFileSystem.h"
#include <string>
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
using namespace std;

/*
 * This function adds a file to the file system
 */
int SimpleFileSystem::addFile(string a, AbstractFile* p){
    if (maps.count(a) != SFSSuccess) {
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


/*
 * This function opens a existing file from the file system
 */
AbstractFile* SimpleFileSystem::openFile(string of){
    if (maps.count(of) != SFSSuccess) {

        if (sets.find(maps[of]) == sets.end()) {
            sets.insert (maps[of]);
            return maps[of];
        }
    }

    return nullptr;
}

/*
 * This function closes a file that was opened
 */
int SimpleFileSystem::closeFile(AbstractFile *cf) {
    if (sets.find(cf) != sets.end()) {
        sets.erase(cf);
        return SFSSuccess;
    }
    return fileNotOpen;
}

/*
 * This function deletes an existing file from the file system
 */
int SimpleFileSystem::deleteFile(string df) {
    if (maps.count(df) != SFSSuccess) {
        if (sets.find(maps[df]) != sets.end()) {
            return fileIsOpen;
        }
        delete maps[df];
        maps.erase(df);
        return SFSSuccess;

    }
    return fileDoesNotExist;
}


/*
 * The functions uses a for each loop to go through the map containing all the files of the system and returning a set
 */
std::set<std::string> SimpleFileSystem::getFileNames(){
    std::set<string> returnedSet;

    for (pair <string, AbstractFile*> filePair : maps) {
        returnedSet.insert(filePair.first);
    }
    return returnedSet;
}