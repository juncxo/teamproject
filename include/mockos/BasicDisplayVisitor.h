#pragma once
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor{
public:
    virtual void visit_TextFile(TextFile*);
    virtual void visit_ImageFile(ImageFile*);
};