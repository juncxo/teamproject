#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"
#include <vector>
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    AbstractFile* protect = new TextFile ("thing");
    AbstractFile* proxy = new PasswordProxy(protect, "i love CS332");
    vector <char> theOtherThing;
    theOtherThing.push_back('h');
    theOtherThing.push_back('i');
    proxy->write(theOtherThing);
    proxy->read();
    cout<<proxy->getName() << endl;
    cout<<proxy->getSize() << endl;
    return 0;
}