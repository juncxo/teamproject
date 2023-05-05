#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    AbstractFileSystem* afs = new SimpleFileSystem();
    AbstractFileFactory* aff = new SimpleFileFactory();
    ImageFile* img = new ImageFile ("hello.img");
    TextFile* tf = new TextFile ("332.txt");
    aff->createFile("hello.img");
    aff->createFile("332.txt");
    afs->openFile("hello.img");
    afs->openFile("332.txt");
    vector <char> vc = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
    img->write (vc);
    tf->write (vc);

    img->read();
    tf->read();
    
    return 0;
}