#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"


using namespace std;

AbstractFile* SimpleFileFactory::createFile(string cf){
    int dotIndex;
    for (int i = 0; i < cf.length(); i++) {
        if (cf[i] == '.') {
            dotIndex = i;
        }
    }
    string extension = cf.erase(0, dotIndex+1);
    if (extension == "txt") {
        TextFile* tf = new TextFile (cf);
        return tf;

    }
    else if (extension == "img") {
        ImageFile* image = new ImageFile (cf);
        return image;
    }
    return nullptr;
}