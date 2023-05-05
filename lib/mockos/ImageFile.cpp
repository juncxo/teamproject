#include <vector>
#include "mockos/ImageFile.h"
#include <iostream>
using namespace std;

/*
 * ImageFile constructor
 */
ImageFile :: ImageFile (string initializeName) {
    imageName = initializeName;
    imageSize = 0;
}

/*
 * Returns the size of the image contained in the imagefile
 */
unsigned int ImageFile::getSize() {
    return imageSize*imageSize;
}

/*
 * Returns the name of the imagefile
 */
string ImageFile::getName () {
    return imageName;
}

/*
 * Creates content to the imagefile
 */
int ImageFile::write(vector <char> vc) {
    int size = (vc[vc.size() - 1] - 48);
    imageSize = size;
   if (vc.size() - 1 != imageSize * imageSize) {
      imageContents.clear();
      imageSize = 0;
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

/*
 * Returns the contents of the imagefile
 */
vector<char> ImageFile::read () {
    return imageContents;
}


/*
 * Clones the file passed in the parameter, add the extension of the file, sets the file's content to match source file's
 */
AbstractFile* ImageFile::clone (string fileName) {
    ImageFile* newFile =  new ImageFile(*this);
    newFile->imageName = fileName + ".img";
    newFile->imageContents = imageContents;
    return newFile;
}

/*
 * Visits the displayvisitor function
 */
void ImageFile::accept(AbstractFileVisitor* afv){
    afv->visit_ImageFile(this);
}

