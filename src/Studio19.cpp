
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"

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
    vector <char> vi = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
    img->write(vi);
    img->read();
    //cout<< img->getSize() << endl;

    BasicDisplayVisitor* bv = new BasicDisplayVisitor();
    //cout << bv << endl;
    tf->accept(bv);
    img->accept(bv);
    MetadataDisplayVisitor* mv = new MetadataDisplayVisitor();
    tf->accept(mv);
    img->accept(mv);


    return 0;
}