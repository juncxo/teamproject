#include <vector>
#include "mockos/ImageFile.h"
#include <iostream>
using namespace std;

ImageFile :: ImageFile (string initializeName) {
    imageName = initializeName;
    imageSize = 0;
}

unsigned int ImageFile::getSize() {
    return imageContents.size();
}


string ImageFile::getName () {
    return imageName;
}

int ImageFile::write(vector <char> vc) {
    imageSize = (imageContents[ImageFile::getSize() - 1] - 48);
    if ((vc.size() - 1) != imageSize * imageSize) {
        imageContents.clear();
        imageSize = 0;
        return sizeMismatchError;
    }
    for (int i = 0; i < imageSize; i++) {
        imageContents.push_back (vc[i]);
        if (!(vc[i] == 'X' || vc[i] == ' ')) {
            imageContents.clear();
            imageSize = 0;
            return incorrectPixelError;
        }
    }
    return imageSuccess;
}

int ImageFile::append(vector <char> vc) {
   return appendNotSupportedError;
}

void ImageFile::read () {
    for (int y = imageSize - 1; y >= 0; y--) {
        for (int x = 0; x < imageSize; x++) {
            std::cout << imageContents[y * imageSize + x];
        }
    }

    /*for (int i = 0; i < contents.size(); i++) {
        cout << contents[i];
    }
    cout << endl;*/
}


