#include "mockos/MetadataDisplayVisitor.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
    cout << left << setw(20) << tf->getName();
    cout << left << setw(20) << "text";
    cout << left << setw (20) << tf->getSize() << endl;

}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img){
    cout << setw(20) << img->getName();
    cout << setw(20) << "image";
    cout << setw (20) << img->getSize() << endl;

}
