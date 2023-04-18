#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    ImageFile* img = new ImageFile("hello.img");
    vector <char> vc = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
    img->write(vc);
    cout << "imgFile reading: " << endl;
    img->read();
    /*cout << img->getName()<<endl;
    cout << img->getSize()<<endl;*/
    SimpleFileSystem sf;
    TextFile* tf = new TextFile("Test.txt");
    sf.addFile("Test.txt", tf);
    sf.addFile("hello.img", img);
    sf.createFile("Test1.txt");
    sf.openFile("Test2.txt");
    tf->write(vc);
    cout << "TextFile reading: " << endl;
    tf->read();

    sf.closeFile(tf);
    sf.deleteFile("Test1.txt");
    sf.deleteFile("Test.txt");
    sf.deleteFile("hello.img");
    cout << "imgFile reading: " << endl;
    img->read();

    return 0;
}