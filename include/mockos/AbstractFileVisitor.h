#pragma once
#include <vector>
//#include "ImageFile.h"
//#include  "TextFile.h"
class ImageFile;
class TextFile;

class AbstractFileVisitor {
public:
    virtual void visit_TextFile(TextFile*) = 0;
    virtual void visit_ImageFile(ImageFile*) = 0;
};
