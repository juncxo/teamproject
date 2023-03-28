#include <vector>
#include <string>
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
    TextFile(std::string);
protected:
    std::vector<char> contents;
    std::string name;
private:

};