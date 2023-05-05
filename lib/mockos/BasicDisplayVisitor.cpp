#include "mockos/BasicDisplayVisitor.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


/*
 * Function loops through the content of an image file
 * Prints out the formatted version of the image file content
 */
void BasicDisplayVisitor::visit_ImageFile(ImageFile * image) {
    int imageSize = sqrt(image->getSize());
    vector<char> imgContent = image->read();
    for (int y = imageSize - 1; y >= 0; y--) {
        for (int x = 0; x < imageSize; x++) {

           cout << imgContent[y * imageSize + x];

        }

        cout << endl;
    }
    cout << endl;
}


/*
 * Function loops through the content of text file
 * prints out each character of the content
 */
void BasicDisplayVisitor::visit_TextFile(TextFile * tf) {
    for (int i = 0; i < tf->read().size(); i++) {
        cout << tf->read()[i];
    }
    cout << endl;
}