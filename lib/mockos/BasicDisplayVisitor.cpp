#include "mockos/BasicDisplayVisitor.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile * image) {
    int imageSize = sqrt(image->getSize());
    vector<char> imgContent = image->read();
    for (int y = imageSize - 1; y >= 0; y--) {
        for (int x = 0; x < imageSize; x++) {

           cout << imgContent[y * imageSize + x];

        }
        //cout << "test4" << endl;
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