#pragma once
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class MetadataDisplayVisitor : public AbstractFileVisitor{
public:
    virtual void visit_TextFile(TextFile*);
    virtual void visit_ImageFile(ImageFile*);

};
