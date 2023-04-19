#include <vector>
#include "mockos/ImageFile.h"
#include <iostream>
using namespace std;

ImageFile :: ImageFile (string initializeName) {
    imageName = initializeName;
    imageSize = 0;
}

unsigned int ImageFile::getSize() {
    return imageSize*imageSize;
}


string ImageFile::getName () {
    return imageName;
}

int ImageFile::write(vector <char> vc) {
    int size = (vc[vc.size() - 1] - 48);
    imageSize = size;
    //cout << imageSize << endl;
   if (vc.size() - 1 != imageSize * imageSize) {
      imageContents.clear();
      imageSize = 0;
      cout << "Test " << endl;
      return sizeMismatchError;
  }
    for (int i = 0; i < imageSize * imageSize; i++) {
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


vector<char> ImageFile::read () {
    /*
    for (int y = imageSize - 1; y >= 0; y--) {
        for (int x = 0; x < imageSize; x++) {
            std::cout << imageContents[y * imageSize + x];
        }
        cout << endl;
    }


    cout << endl;
    */
    return imageContents;
}

void ImageFile::accept(AbstractFileVisitor* afv){
    afv->visit_ImageFile(this);
}

