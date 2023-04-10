#include <vector>
#include <string>
#include "mockos/TextFile.h"
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    TextFile* tf = new TextFile("hello");
    vector <char> vc = {'a', 'b', 'c', 'd', 'e'};
    tf->write(vc);
    tf->read();
    cout << tf->getName()<<endl;
    cout << tf->getSize()<<endl;
    vector<char> ap = {'f'};
    tf->append(ap);
    tf->read();
    AbstractFile* af = new TextFile("testing");
    af->write(ap);
    af->read();
    cout << af->getName()<<endl;
    cout << af->getSize()<<endl;
    af->append(vc);
    af->read();
    return 0;
}