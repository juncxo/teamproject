#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"

enum imageReturns {imageSuccess, sizeMismatchError, incorrectPixelError, appendNotSupportedError};

class ImageFile : public AbstractFile {
public:
    ImageFile(std::string);
    virtual std::string getName();
    virtual unsigned int getSize();
    virtual void read();
    virtual int write(std::vector<char>);
    virtual int append(std::vector<char>);
protected:

private:
    std::string imageName;
    std::vector<char> imageContents;
    char imageSize;
};
