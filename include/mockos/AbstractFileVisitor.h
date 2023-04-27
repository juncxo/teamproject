#pragma once
#include <vector>
class ImageFile;
class TextFile;


class AbstractFileVisitor {
public:
    virtual void visit_TextFile(TextFile*) = 0;
    virtual void visit_ImageFile(ImageFile*) = 0;
};
