#include "mockos/MetadataDisplayVisitor.h"
#include <cmath>
#include <iostream>
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
    cout << "File Name: " << tf->getName()<< endl;
    cout << "File Size: " << tf->getSize() << endl;
    cout << "File Type: text" << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img){
    cout << "File Name: " << img->getName()<< endl;
    cout << "File Size: " << img->getSize() << endl;
    cout << "File Type: image" << endl;
}
