#include "mockos/BasicDisplayVisitor.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile * image) {
    int imageSize = image->getSize();
    cout << image->getSize() <<endl;
    for (int y = imageSize - 1; y >= 0; y--) {
        cout <<"image test2" <<endl;
        for (int x = 0; x < imageSize; x++) {
           cout << image->read()[y * imageSize + x];
        }
        cout << endl;
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_TextFile(TextFile * tf) {
    for (int i = 0; i < tf->read().size(); i++) {
        cout << tf->read()[i];
    }
    cout << endl;
}