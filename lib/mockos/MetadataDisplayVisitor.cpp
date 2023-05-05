#include "mockos/MetadataDisplayVisitor.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Displays information about a given text file passed in the parameter
 */
void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
    cout << left << setw(20) << tf->getName();
    cout << left << setw(20) << "text";
    cout << left << setw (20) << tf->getSize() << endl;

}

/*
 * Displays information about a given image file passed in the parameter
 */
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img){
    cout << setw(20) << img->getName();
    cout << setw(20) << "image";
    cout << setw (20) << img->getSize() << endl;

}
