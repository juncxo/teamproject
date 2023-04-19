
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/BasicDisplayVisitor.h"

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

    ImageFile* img = new ImageFile("test");
    vector <char> vi = {'f', 'g', 'h', 'i', 'e'};
    img->write(vi);
    img->read();
    vector<char> ap1 = {'g'};
    img->append(ap1);
    img->read();
    cout<< img->getSize() << endl;

    BasicDisplayVisitor* bv = new BasicDisplayVisitor();
    tf->accept(bv);
    img->accept(bv);

    return 0;
}