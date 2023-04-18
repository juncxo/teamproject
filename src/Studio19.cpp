
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    TextFile* tf = new TextFile("hello");
    vector <char> vc = {'a', 'b', 'c', 'd', 'e'};
    tf->write(vc);
    tf->read();
    vector<char> ap = {'f'};
    tf->append(ap);
    tf->read();
    return 0;
}