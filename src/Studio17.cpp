#include "mockos/ImageFile.h"
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    ImageFile* tf = new ImageFile("hello");
    vector <char> vc = {'a', 'b', 'c', 'd', 'e'};
    tf->write(vc);
    tf->read();
    cout << tf->getName()<<endl;
    cout << tf->getSize()<<endl;
}