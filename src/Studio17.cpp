#include "mockos/ImageFile.h"
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    ImageFile* tf = new ImageFile("hello");
    vector <char> vc = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
    tf->write(vc);
    tf->read();
    cout << tf->getName()<<endl;
    cout << tf->getSize()<<endl;
    return 0;
}