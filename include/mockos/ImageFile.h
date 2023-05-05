#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"

/*
 * Enumeration for ImageFile class
 */
enum imageReturns {
    imageSuccess,
    sizeMismatchError,
    incorrectPixelError,
    appendNotSupportedError
};

class ImageFile : public AbstractFile {
public:
    ImageFile(std::string);
    virtual std::string getName();
    virtual unsigned int getSize();
    virtual std::vector<char> read();
    virtual int write(std::vector<char>);
    virtual int append(std::vector<char>);
    virtual void accept(AbstractFileVisitor*);
    virtual AbstractFile* clone(std::string);

protected:

private:
    std::string imageName;
    std::vector<char> imageContents;
    char imageSize;
};
