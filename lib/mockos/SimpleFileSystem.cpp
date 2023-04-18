#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <string>
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
using namespace std;

int SimpleFileSystem::addFile(string a, AbstractFile* p){
    if (maps.count(a) != 0) {
        //file with that name already exists
        return fileExists; //file exists
    }
    if(p == NULL){
        return pointerIsNull; //it is null
    }
    pair <string, AbstractFile*> filePair;
    filePair.first = a;
    filePair.second = p;
    maps.insert(filePair);
    return SFSSuccess;
}

/* Comment out for studio 18
int SimpleFileSystem::createFile(string f) {
    if (maps.count(f) != 0) {
        //file with that name already exists
        return fileExists; //file exists
    }
    int dotIndex;
    for (int i = 0; i < f.length(); i++) {
        if (f[i] == '.') {
            dotIndex = i;
        }
    }
    string extension = f.substr(dotIndex + 1, dotIndex+3);        //studio 17 error came from here
    //string truncatedName = f.erase(dotIndex, f.length() - dotIndex - 1);
    pair <string, AbstractFile*> filePair;

    if (extension == "txt") {
        TextFile* tf = new TextFile (f);
        filePair.first = f;
        filePair.second = tf;
        maps.insert(filePair);
        //cout << "inserted into the map" << endl;
        return SFSSuccess;

    }
    else if (extension == "img") {
        ImageFile* image = new ImageFile (f);
        filePair.first = f;
        filePair.second = image;
        maps.insert(filePair);
        //cout << "inserted into the map" << endl;

        return SFSSuccess;
    }
    return invalidExtension;
}
*/

AbstractFile* SimpleFileSystem::openFile(string of){
    if (maps.count(of) != 0) {
        //file with that name already exists
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
        //file with that name already exists
        if (sets.find(maps[df]) != sets.end()) {
            return fileIsOpen;
        }
        delete maps[df];
        maps.erase(df);
        return SFSSuccess;

    }
    return fileDoesNotExist;
}